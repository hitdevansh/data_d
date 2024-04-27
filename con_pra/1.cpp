#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
int H=10,W=20;
char Action;
int X=1,Y=0;
char player = {4};
void PlayerAction();
unsigned char maze[13][27]{
    {' ',176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,' '},
    {' ',' ',' ',176,' ',' ',' ',' ',176,' ',176,' ',176,' ',' ',' ',176,' ',' ',' ',' ',' ',' ',' ',' ',176,' '},
    {' ',176,' ',' ',' ',176,176,176,176,' ',' ',' ',176,' ',176,176,176,176,176,' ',' ',176,176,176,' ',176,' '},
    {' ',176,176,176,' ',176,' ',' ',' ',' ',176,' ',176,' ',176,' ',' ',' ',176,176,' ',176,' ',176,' ',176,' '},
    {' ',176,' ',176,' ',176,176,176,' ',176,176,' ',176,' ',176,' ',176,' ',' ',176,' ',176,' ',176,' ',176,' '},
    {' ',176,' ',176,' ',176,' ',176,' ',176,' ',' ',176,' ',176,' ',176,176,' ',' ',' ',176,' ',176,' ',176,' '},
    {' ',176,' ',176,' ',176,' ',176,' ',176,' ',176,176,' ',176,' ',' ',176,176,176,176,176,' ',176,' ',176,' '},
    {' ',176,' ',176,' ',176,' ',' ',' ',176,' ',176,' ',' ',176,' ',' ',' ',' ',176,' ',' ',' ',176,' ',176,' '},
    {' ',176,' ',' ',' ',176,' ',176,' ',176,' ',176,' ',176,176,176,' ',176,' ',176,' ',176,' ',176,176,176,' '},
    {' ',176,' ',' ',' ',' ',' ',176,' ',176,' ',176,' ',176,' ',176,' ',176,' ',176,' ',176,' ',' ',' ',176,' '},
    {' ',176,' ',176,176,176,176,176,' ',176,' ',176,' ',' ',' ',176,' ',176,' ',' ',' ',176,176,176,' ',' ',' '},
    {' ',176,' ',' ',' ',176,' ',' ',' ',176,' ',' ',' ',176,' ',' ',' ',176,' ',176,' ',' ',' ',176,' ',176,' '},
    {' ',176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,' '},
};
char tmp_map[18][32];
char map[18][32] = {
	"+#############################+",
	"|                             |",
	"|                             |",
	"|## ########### ##   #########|",
	"|   |                         |",
	"| | |### |  |           |     |",
	"| |      |  | |###  |   |  |  |",
	"| | #####|  | |      ## |     |",
	"| |           |###  |      |  |",
	"| |##### ###         ##       |",
	"|          ######  ####### ###|",
	"|                             |",
	"|# ### ####      ###   #######|",
	"|                             |",
	"|          #                  |",
	"|  #########        #######   |",
	"|                   #         |",
	"+#############################+"
	};
   
void gotoxy( short x22, short y22 )
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD position = { x22, y22 } ;

    SetConsoleCursorPosition( hStdout, position ) ;
}
class entity {
public:
	entity( int x22, int y22 ){
		this ->x22 = x22;
		this ->y22 = y22;
	}

	void move_x( int p ){
		if( map[y22][x22+p] == ' ' ) x22 += p;
	}

	void move_y( int p ){
		if( map[y22+p][x22] == ' ' ) y22 += p;
	}

	void move( int p, int q ){
		x22 += p;
		y22 += q;
	}

	int get_x(){ return x22; }
	int get_y(){ return y22; }

	void draw( char p ){
		map[x22][y22] = p;
		gotoxy( x22, y22 ); printf( "%c", p );
	}

private:
	int x22;
	int y22;
};

void ShowMap()
{
	for(int i = 0; i < 18; i++) {
		printf("%s\n",map[i] );
	}
}
struct walk {
	short walk_count;
	short x22;
	short y22;
	short back;
};
struct target {
	short x22;
	short y22;
};

vector<target> walk_queue;
vector<walk> BFSArray;
void AddArray( int x22, int y22, int wc , int back ){
	if( tmp_map[y22][x22] == ' ' || tmp_map[y22][x22] == '.' ){
		tmp_map[y22][x22] = '#';
		walk tmp;
		tmp.x22 = x22;
		tmp.y22 = y22;
		tmp.walk_count = wc;
		tmp.back = back;
		BFSArray.push_back( tmp );
	}
}

void FindPath( int sx, int sy, int x22, int y22 ){
	memcpy( tmp_map, map, sizeof(map) );
	BFSArray.clear();
	walk tmp;
	tmp.x22 = sx;
	tmp.y22 = sy;
	tmp.walk_count = 0;
	tmp.back = -1;
	BFSArray.push_back( tmp );

	int i = 0;
	while( i < BFSArray.size() ){
		if( BFSArray[i].x22 == x22 && BFSArray[i].y22 == y22 ){
			walk_queue.clear();
			target tmp2;
			while( BFSArray[i].walk_count != 0 ){
				tmp2.x22 = BFSArray[i].x22;
				tmp2.y22 = BFSArray[i].y22;
				walk_queue.push_back( tmp2 );

				i = BFSArray[i].back;
			}

			break;
		}

		AddArray( BFSArray[i].x22+1, BFSArray[i].y22, BFSArray[i].walk_count+1, i );
		AddArray( BFSArray[i].x22-1, BFSArray[i].y22, BFSArray[i].walk_count+1, i );
		AddArray( BFSArray[i].x22, BFSArray[i].y22+1, BFSArray[i].walk_count+1, i );
		AddArray( BFSArray[i].x22, BFSArray[i].y22-1, BFSArray[i].walk_count+1, i );

		/*
			AddArray( BFSArray[i].x22+1, BFSArray[i].y22+1, BFSArray[i].walk_count+1, i );
			AddArray( BFSArray[i].x22-1, BFSArray[i].y22+1, BFSArray[i].walk_count+1, i );
			AddArray( BFSArray[i].x22+1, BFSArray[i].y22+1, BFSArray[i].walk_count+1, i );
			AddArray( BFSArray[i].x22+1, BFSArray[i].y22-1, BFSArray[i].walk_count+1, i );

			AddArray( BFSArray[i].x22+1, BFSArray[i].y22-1, BFSArray[i].walk_count+1, i );
			AddArray( BFSArray[i].x22-1, BFSArray[i].y22-1, BFSArray[i].walk_count+1, i );
			AddArray( BFSArray[i].x22-1, BFSArray[i].y22+1, BFSArray[i].walk_count+1, i );
			AddArray( BFSArray[i].x22-1, BFSArray[i].y22-1, BFSArray[i].walk_count+1, i );
		*/
		i++;
	}

	BFSArray.clear();
}




/*----------------------------------------------------------------------------------------------------------------------------------------*/
int gameOver;
const int height=20;
const int width=35;
int x,y,fruitX,fruitY,score;
int tailX[100],tailY[100],nTail;
enum eDirection{STOP=0,UP,DOWN,LEFT,RIGHT};
eDirection dir;
/*----------------------------------------------------------------------------------------------------------------------------*/
void Setup(){
    gameOver=1;
    dir = STOP;
    x=width/2;
    y=height/2;
    fruitX=rand()%(width-2);
    fruitY=rand()%(height-2);
}
/*----------------------------------------------------------------------------------------------------------------------------*/
void Draw(){
    system("CLS");
    for(int i=0;i<width;i++){
        cout<<(char)176;
    }cout<<endl;

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(j==0||j==width-1){
                cout<<(char)176;
            }
            else if(i==y && j==x){
                cout<<"O";
            }
            else if(i==fruitY && j==fruitX){
                cout<<(char)254;
            }
            else{
                bool print=false;
                for(int k=0;k<nTail;k++){
                    if(i==tailY[k] && j==tailX[k]){
                        cout<<"o";
                        print=true;
                    }
                }
            if(!print){
                cout<<" ";}
            }
        }cout<<endl;
    }
    for(int i=0;i<width;i++){
        cout<<(char)176;
    }cout<<endl;
    cout<<"w for Up\na for Left\nd for Right\ns for Down"<<endl;
    cout<<endl;
    cout<<"Score = "<<score<<endl;

}
/*----------------------------------------------------------------------------------------------------------------------------*/
void Input(){
    if(_kbhit()){
        switch(_getch()){
            case 'W':
            dir=UP;
            break;
            case 'A':
            dir=LEFT;
            break;
            case 'S':
            dir=DOWN;
            break;
            case 'D':
            dir=RIGHT;
            break;
            default:
            break;
        }
    }
}
/*----------------------------------------------------------------------------------------------------------------------------*/
void Logic(){
    int px=tailX[0];
    int py=tailY[0];
    tailX[0]=x;
    tailY[0]=y;
    int px2,py2;
    for(int i=1;i<nTail;i++){
        px2=tailX[i];
        py2=tailY[i];
        tailX[i]=px;
        tailY[i]=py;
        px=px2;
        py=py2;
    }

    switch(dir){
        case UP:
        y--;
        break;
        case DOWN:
        y++;
        break;
        case LEFT:
        x--;
        break;
        case RIGHT:
        x++;
        break;
        default:
        break;
    }
    if(x<0 || x>(width+1) || y<0 || y>(height+1)){
        gameOver=0;
    }
    for(int i=0;i<nTail;i++){
        if(x==tailX[i] && y==tailY[i]){
            gameOver=0;
        }
    }
    if(x==fruitX && y==fruitY){
        score=score+10;
    fruitX=rand()%(width-2);
    fruitY=rand()%(height-2);
    nTail++;
    }
}
/*----------------------------------------------------------------------------------------------------------------------------*/
int main(){
    int choice;
    yuu:;
    cout<<"\t\t\t\t\t\t\t\tWelcome to Tres juegos."<<endl;
    cout<<"\t\t\t\t\t\t\t\t-----------------------\n\n"<<endl;
    cout<<"Enter 1 for Maze Game.\nEnter 2 for Snake Game.\nEnter 3 for Pac-Run.\nEnter 4 for Quit"<<endl;
    cin>>choice;
    switch(choice){
        case 1:
    int n,A;
    wer:;
    X=1,Y=0;
    while(Action !='Q'){
        if(Action=='Q' || Action=='q'){
        }else{
    maze[X][Y]=player;
    for(int i=0;i<13;i++){
        for(int j=0;j<27;j++){
            cout<<maze[i][j];
        }   
        cout<<endl;
    } 
    cout<<"W for Up\nA for Left\nD for Right\nS for Down\nQ for Quit."<<endl;
    PlayerAction();
    if(X==10 && Y==25){
        cout<<"\n\nYou Won the Game."<<endl;  
    cout<<"Do you want to play the game Again ? (1 for Yes :0 for No)"<<endl;
    cin>>A;
    if(A==1){
        goto wer;
    }
    else{
        goto yuu;
    }
    }
    }
    }
    break;
    case 2:
    tuu:;
    nTail=0;
    cout<<"Enter the difficulty level:"<<endl;
    cout<<"1 for Easy.\n2 for Medium.\n3 for Hard.\n4 for back to Menu."<<endl;
    int ans,ans1,ans2;
    cin>>ans1;
    switch(ans1){
        case 1:
        ans2=200;
        break;
        case 2:
        ans2=60;
        break;
        case 3:
        ans2=10;
        break;
        case 4:
        goto yuu;
        break;
    }
    Setup();
    while(gameOver!=0){
        Draw();
        Input();
        Logic();
        Sleep(ans2);
    }
    cout<<"The game is over"<<endl;
    cout<<"Do you want to goback ?(1 for Yes : 0 for No)"<<endl;
    cin>>ans;
    if(ans==0){
        goto tuu;
    }
    if(ans==1){
        goto tuu;
    }
    break;
    case 3:
    tyty:;
    bool runns = true;
	int x22 = 15; // hero x22
	int y22 = 16; // hero y22
	int old_x;
	int old_y;
	int ex = 1;
	int ey = 1;
	int pts = 0;
    int fffgh;
	printf("\nInstruction:\n1. Arrow Keys to move your hero\n2. Eat the dots produced by the Eater to gain poins\n3. Don't get caught by the Eater\n\n");
	printf("H -> Hard\nN -> Normal\nE -> Easy\nMode : ");
	char diffi;
	int speedmod = 3;
	cin >> diffi;
	if( diffi == 'N' ){
		speedmod = 2;
	}else if( diffi == 'H' ){
		speedmod = 1;
	}
	system("cls");
    ShowMap();
	gotoxy( x22, y22 ); cout << "H";
	int frame = 0;
	FindPath( ex,ey,x22,y22 );
	while( runns ){
		gotoxy( x22, y22 ); cout << " ";
		old_x = x22;
		old_y = y22;
		if ( GetAsyncKeyState( VK_UP ) ){
			if( map[y22-1][x22] == '.' ){ y22--; pts++; } else
			if( map[y22-1][x22] == ' ' ) y22--;
		}
		if ( GetAsyncKeyState( VK_DOWN ) ){
			if( map[y22+1][x22] == '.' ){ y22++; pts++; } else
			if( map[y22+1][x22] == ' ' ) y22++;
		}
		if ( GetAsyncKeyState( VK_LEFT ) ){
			if( map[y22][x22-1] == '.' ){ x22--; pts++; } else
			if( map[y22][x22-1] == ' ' ) x22--;
		}
		if ( GetAsyncKeyState( VK_RIGHT ) ){
			if( map[y22][x22+1] == '.' ){ x22++; pts++; } else
			if( map[y22][x22+1] == ' ' ) x22++;
		}
		if( old_x != x22 || old_y != y22 ){
			FindPath( ex,ey,x22,y22 );
		}
		gotoxy( x22,y22 ); cout << (char)64;
		map[ey][ex] = '.';
		gotoxy( ex, ey ); cout << ".";
		if( frame%speedmod == 0 && walk_queue.size() != 0 ){
			ex = walk_queue.back().x22;
			ey = walk_queue.back().y22;
			walk_queue.pop_back();
		}
		gotoxy( ex, ey ); cout << (char)176;
		if( ex == x22 && ey == y22 ){
			break;
		}
		gotoxy( 32, 18 );
		gotoxy( 32, 1 ); cout << pts;
		Sleep( 100 );
		frame++;
	}
	system("cls");
	printf("\nYou Lose and your score is : %i", pts );
	cin.get();
    cout<<"\nDo you want to play again?(1 for Yes and 0 for No)";
    cin>>fffgh;
    if(fffgh==1){
        goto tyty;
    }
    else{
        goto yuu;
    }
    break;
    }
    return 0;
}
/*----------------------------------------------------------------------------------------------------------------------------------------*/
void PlayerAction(){
    cout<<"Define your action:"<<endl;
    cin>>Action;
    int PX=X;
    int PY=Y;
    switch(Action){
        case 'A':
        if(maze[X][Y-1]!=176){
            Y--;
            cout<<X<<","<<Y<<endl;
            maze[PX][PY] = ' ';
            system("cls");
        }
        else{
            cout<<"That was a invalid move."<<endl;
        }
        break;
        case 'W':
        if(maze[X-1][Y]!=176){
            X--;
            cout<<X<<","<<Y<<endl;
            maze[PX][PY]=' ';
            system("cls");
        }
        else{
            cout<<"That was a invalid move."<<endl;
        }
        break;
        case 'S':
        if(maze[X+1][Y]!=176){
            X++;
            cout<<X<<","<<Y<<endl;
            maze[PX][PY]=' ';
            system("cls");
        }else{
            cout<<"That was a invalid move."<<endl;
        }
        break;
        case 'D':
        if(maze[X][Y+1]!=176){
            Y++;
            cout<<X<<","<<Y<<endl;
            maze[PX][PY]=' ';
            system("cls");
        }
        else{
            cout<<"That was a invalid move."<<endl;
        }
        break;
        case 'q':
        return ;
        case 'Q':
        return ;
        default:
        cout<<"Invalid Move."<<endl;
        }
        
    }   
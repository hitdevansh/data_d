#include<iostream>
using namespace std;
class bt
{
    public:
    int cap;
    bt(){
        cout<<"Enter aa total capacity "<<endl;
        int val;
        cin>>val; 
        cap=val; 
    }
    int size=0;
    char *bi[cap];
    int parent(int i){
        return (i-1/2);
    }
    int rchild(int i)
    {
        return (2*i+1);
    }
    
    int lchild(int i)
    {
        return (2*i);
    }
    void insert(int val)
    {   if(bi[0]!='\0')
    {
        cout<<"root set"<<endl;
        bi[0]=val;
        cout<<bi[0]<<endl;
        return ;
    }
        else{
        for(int i=0;i<cap;i++)
        {   
            if(bi[lchild(i)]!='\0')
            {
                bi[lchild(i)]=val;
                cout<<"Insrted at left of "<<bi[i]<<endl;
                size++;
                return ;
            }
            else if(rchild(i)==0)
            {
                bi[rchild(i)]=val;
                cout<<"Insrted at right of "<<bi[i]<<endl;
                return ;
            }
        }}
    }
    void print()
    {   cout<<"print called!"<<endl;
        for(int j=0;j<=size-1;j++)
        {
            cout<<bi[j]<<" ";
        }
    }
};
int main(){
    bt b;
    int p=0;
    do
    {
        cin>>p;
        if(p==1){
        cout<<"Entera data to insert"<<endl;
        int val;
        cin>>val;
        b.insert(val);}
        /* code */
        if(p==2)
        {
            b.print();
        }
    } while (p!=0);
    

return 0;
}
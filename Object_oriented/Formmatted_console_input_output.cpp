#include<iostream>
using namespace std;
//********
//fill function wil fill the free spaces of width and etc by perticular given thing.
// pricision also set a length of out put and this both control output basically.
//(.width) will give that much colums for that..
//**********************************************
// int main()
// {
// cout.width(5);
// cout<<5;
// return 0;
// }

//put and get functions
//*************************************
// int main()
// {
// char c;
// cin.get(c);    //get strinf from user
// while(c!='\n')
// {
//     cout.put(c);
//     cin.get(c);    //go to forward charactor
// }
// return 0;
// }

/*getline and write same but write is more prefereable bcz 
it will direcly print & in getlint we have to cout */
//***********************************
int main()
{
    char city[50];
    cin>>city;
    cout.write(city,5);
   

return 0;
}
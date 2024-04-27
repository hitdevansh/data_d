#include<iostream>
using namespace std;
#include<string.h>
class String
{
    public:
    char s[200];
    String()
    {
        cout<<"enter the string";
        cin>>s;
    }
    void operator ==(String p2)
    {
        if(strcmp(s,p2.s)==0)
        {
            cout<<"your srtuing is equal";
        }
        else
        {
            cout<<"it is noy equall";
        }
    }
};
int main()
{
String p1,p2;
p1==(p2);
return 0;
}
#include<iostream>
#include<string.h>
using namespace std;
int main(int argc,char *argv[])
{

char p[ ] = "wc ";
strcat(p,argv[1]);
cout<<p<<endl;
return 0;
}
#include<iostream>
using namespace std;
class octal
{
    int decimal;
    public:
    void input()
    {
        cout<<"taken input is "<<endl;
        cin>>decimal;
    }
    void convert()
    {   cout<<"enter for convert";
        int arr[50],i=0,p;
        while(decimal!=0)
        {   p=decimal%8;
            arr[i]=p;
            decimal=decimal/8;
            i++;
        }
    cout<<"the octal is ";
    for(int j=i-1;j>=0;j--)
    {
        cout<<arr[j];
    }
    }
    
};
int main()
{
octal a;
a.input();
a.convert();
return 0;
}
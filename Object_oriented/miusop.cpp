#include<iostream>
using namespace std;
class Minus 
{   public:
    int decimal;
    public:
    Minus(){
    }
    void getdata(int x){
        decimal=x;
    }
    Minus operator-()
    {  
        decimal=decimal-1;
       
    }
    
};
int main()
{
Minus p1;
p1.getdata(5);
-p1;
cout<<p1.decimal;
return 0;
}
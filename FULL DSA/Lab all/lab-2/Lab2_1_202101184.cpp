#include<iostream>
using namespace std;
class Binary;
class Octal
{  
    public:
    int decimal;
    Octal()
    {}
    friend int add(Binary c,Octal d); 
    int octal(int n)
    {  
    int octalNum[100];
    // counter for octal number array
    int i = 0;
    while (n != 0) {
 
        // storing remainder in octal array
        octalNum[i] = n % 8;
        n = n / 8;
        i++;
    }
    // printing octal number array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << octalNum[j];    
    }
};
class Binary
{   
    public:
    int decimal;
    Binary()
    {
    }
    friend int add(Binary c,Octal d);
    int binary(int n)
    {  
    int binaryNum[32];
    int i = 0;
    while (n > 0) {
    // storing remainder in binary array
    binaryNum[i] = n % 2;
    n = n / 2;
    i++;
    }
    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
    cout << binaryNum[j];
    }
};

int add(Binary c,Octal d) {
return (c.decimal + d.decimal);
}

int main()
{
Binary c;
cout<<"Enter the decimal to store value in a class of Octal"<<endl;
cin>>c.decimal;
Octal d;
cout<<"Enter the decimal to store value in a class of Binary"<<endl;
cin>>d.decimal;
int n;
n=add(c,d);
cout<<n<<endl;
cout<<"Value of decimal to binary is : ";
c.binary(n);
cout<<endl<<"Value of decimal to octal is : ";
d.octal(n);
return 0;
}
//can we 
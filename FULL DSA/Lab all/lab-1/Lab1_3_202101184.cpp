#include <iostream>
using namespace std;
class complex {
public:
int a,b;
complex add(complex a, complex b)
{
complex c;
c.a = a.a + b.a;
c.b = a.b + b.b;
// returning the object
return c;
}
complex mult(complex a, complex b)
{
complex c;
c.a = (a.a*b.a) - (a.b*b.b);
c.b = (a.b*b.a) + (a.a*b.b);
// returning the object
return c;
}
void getdata(void);
};
// This is modified part to show function calling other function
void complex :: getdata()
{
cout <<"Enter the value of real part"<<"\n";
cin >> a;
cout <<"Enter the value  of imaginary part"<<"\n";
cin >> b;
};
int main()
{
complex E1, E2, E3, E4;
cout<<"Enter the value of first element"<<endl;
E1.getdata();
cout<<"Enter the value of second element"<<endl;
E2.getdata();
E3 = E3.add(E1, E2);
cout << "Addition is  \n";
cout << "Value of add" << E3.a<<"+"<< E3.b<< "i"<<endl;
E4 = E4.mult(E1, E2);
cout << "multipilation is \n";
cout << "Value of add" << E4.a<< "+" << E4.b<< "i"<<endl;
return 0;
}

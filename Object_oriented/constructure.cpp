// #include<iostream>
// using namespace std;
// class Complex
// {
//     int a, b;

// public:
//     // Creating a Constructor
//     // Constructor is a special member function with the same name as of the class.
//     //It is used to initialize the objects of its class
//     //It is automatically invoked whenever an object is created

//     Complex(void); // Constructor declaration

//     void printNumber()
//     {
//         cout << "Your number is " << a << " + " << b << "i" << endl;
//     }
// };
// Complex ::Complex(void) // ----> This is a default constructor as it takes no parameters
// {
//     a = 10;
//     b = 0;
//     // cout<<"Hello world";
// }
// int main()
// {Complex a;
// a.printNumber();
// return 0;
// };

// parameter constructure
// #include<iostream>
// using namespace std;
// class Complex
// {
//     int a, b;

// public:
//     Complex(int x,int y); // Constructor declaration

//     void printNumber()
//     {
//         cout << "Your number is " << a << " + " << b << "i" << endl;
//     }
// };
// Complex ::Complex(int x,int y) // ----> This is a default constructor as it takes no parameters
// {
//     a = x;
//     b =y;
//     // cout<<"Hello world";
// }
// int main()

// {   //insplicie caall
//     Complex a(10,20);
//     a.printNumber();
//     //ecplicie call
//     Complex b=Complex(10,2);
//     b.printNumber();
//     return 0;

// Program to calculate the distance between two cartesian points
#include <iostream>
#include <cmath>
using namespace std;
class point
{
    int a,b;
public :
        point(int x,int y);
   friend  int  distance (point A,point B);
};
 point :: point (int x,int y)
    {
        a =x; b=y;
    }
int distance (point C,point D)
{
 float c = sqrt ((C.a- D.a)*(C.a- D.a)+ (C.b- D.b)*(C.b- D.b));
  return c;
}
int main()
{   int x,y;
    cout <<"Enter value of first point's two coordinates"<<endl;
    cin>>x>>y;
    point C=point(x,y);
    cout <<"Enter value of second point's two coordinates"<<endl;
    cin>>x>>y;
    point D=point(x,y);
    int c =distance (C,D);
    cout << " the distance between the two respective points is "<< c;
}
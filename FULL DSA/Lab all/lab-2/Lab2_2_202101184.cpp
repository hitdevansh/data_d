#include <iostream>
using namespace std;
class Matrix;
class Vector;

class Vector
{   
    public:
    int a[3];
    Vector()
    {cout<<"Enter 3 values for 3*1 vector."<<endl;
    for(int i=0;i<3;i++){
       cin>>a[i];
   }
    cout<<"\n Vector A \n";
   //vector 
   for(int i=0;i<3;i++){
       cout<<"\n"<<a[i];
   }
    }
    public:
     friend int* MetVetMultiply(Matrix a, Vector b);

};
class Matrix
{   
    public:
    int b[3][3];
    Matrix()
    {   cout<<endl<<"Enter values for 3*3 matrix"<<endl;
        for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
        cin>>b[i][j];
       }
       cout<<"\n";
   }
    cout<<"\n Matrix B \n";
   //matrix 3*3
   for(int i=0;i<3;i++){
       for(int j=0;j<3;j++){
           cout<<" "<<b[i][j];
       }
       cout<<"\n";
   }}
   int* MetVetMultiply(Matrix a, Vector b);    

};
int arr[3]={0,0,0};

int* Matrix ::MetVetMultiply(Matrix a, Vector b)
{
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i] += (a.b[i][j] * b.a[j]);
        }
    }
   
    return arr;
   
    
}
int main()
{
Vector b;
Matrix a;
int *arr_result;

   arr_result= a.MetVetMultiply(a,b);
 
  cout<<"The result is:"<<endl;
   for (int i = 0; i < 3; i++)
   {
       cout<<*(arr_result+i)<<endl;
      
   }
return 0;
}
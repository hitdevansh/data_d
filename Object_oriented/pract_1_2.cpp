#include<iostream>
#include<math.h>
using namespace std;
class progration{
protected:
int first,length=10;
public:
void value(int k);
void friend priprogration(int k);
};
class arithpro:public progration{
private:
int increment=2;
public:
int p;
void value(int k)
{first=1; 
int l=(first+(k-1)*(increment));
cout<<"kth value is "<<l<<endl;} 
void friend priprogration(int k);
};
void priprogration(int k)
{int l=0;
for(int i=0;i<length;i++)
{p=first+(increment*l);
 cout<<p<<" ";
 l++;}
}

class geopro:public progration{
private:
int base=3;
public:
int p;
void value(int k)
{first=2; 
int l=(first*pow(base,k-1));
cout<<endl<<"kth value is "<<l<<endl;} 
void priprogration(int k)
{int l=0;
for(int i=0;i<k;i++)
{p=first*(pow(base,l));
 cout<<p<<" ";
 l++;}
}
};
int main()
{
arithpro a;
a.value(5);
a.priprogration(5);
geopro b;
b.value(5);
b.priprogration(5);
return 0;
}
#include <iostream>
#include <cmath>
using namespace std;
class point
{
    int a,b;
public :
    point(int x,int y);
   friend  float  distance (point A,point B);
   
};
 point :: point (int x,int y)
    {
        a =x; b=y;
    }
float distance (point C,point D)
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
    float c =distance (C,D);
    cout << " the distance between the two respective points is "<< c;
}
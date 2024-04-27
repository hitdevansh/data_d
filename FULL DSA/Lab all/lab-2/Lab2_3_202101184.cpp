
#include <iostream>
using namespace std;

class Vector
{
    float a[5];

public:
    Vector()
    {

        for (int i = 0; i < 5; i++)
        {
            a[i] = 0;
        }
    }
    Vector(int x1, int x2, int x3, int x4, int x5)
    {

        a[0] = x1;
        a[1] = x2;
        a[2] = x3;
        a[3] = x4;
        a[4] = x5;
    }
    void modify(int, float);
    void show_vector(void);

    Vector(Vector &vec1)
    {
        cout << endl<<"Copy constructor called !!" << endl;
        a[0] = vec1.a[0];
        a[1] = vec1.a[1];
        a[2] = vec1.a[2];
        a[3] = vec1.a[3];
        a[4] = vec1.a[4];
    }
};

void Vector::modify(int position, float value)
{
    if(position>5)
    {
        cout<<"you have entered invalid position your task of modition is failed"<<endl;
    }
    else
    a[position - 1] = value;
}

void Vector::show_vector()
{
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{

    Vector vec1, vec2;
    int x1, x2, x3, x4, x5;
    cout << "The default values of the vector:" << endl;
    vec1.show_vector();

    cout << "Enter the five elements for the vector:" << endl;

    cin >> x1 >> x2 >> x3 >> x4 >> x5;
    cout << endl;
    vec1 = Vector(x1, x2, x3, x4, x5);
    cout<<"Vector of your given input is:-";
    vec1.show_vector();

    int position, value;
    cout << endl
         << "Enter the position and new value for function modification:" << endl;
    cin >> position >> value;
    vec1.modify(position, value);
    if(position>0 && position<6)
    {cout << "The modified vector is:" << endl;
    vec1.show_vector();}
    vec2 = Vector(vec1);
    vec2.show_vector();

    return 0;
}

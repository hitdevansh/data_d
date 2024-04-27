#include <iostream>
using namespace std;
class matrix
{
public:
    int mat[3][3];
    matrix() {}
    void take()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> mat[i][j];
            }
        }
    }
   matrix operator+(matrix m2)
    {
        matrix m;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                m.mat[i][j] = mat[i][j] + m2.mat[i][j];
        }
     return m;
    }
    matrix operator-(matrix m2)
    {
        matrix m;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                m.mat[i][j] = mat[i][j] - m2.mat[i][j];
            }
        }
        return m;
        // for(int i=0;i<3;i++)
        //     {
        //         for(int j=0;j<3;j++)
        //         {
        //             cout<<m.mat[i][j];
        //         }
        //     }
    }
    matrix operator*(matrix m2)
    {   int i,j,k;
        matrix m;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                m.mat[i][j]=0;
                for (k = 0; k < 3; k++)
                {
                    m.mat[i][j] += mat[i][k] * m2.mat[k][j];
                }
            }
        }
        return m;
    }
};
int main()
{
    cout << "enter a 1st " << endl;
    matrix m1;
    m1.take();
    cout << "Enter a seccond matrix" << endl;
    matrix m2;
    m2.take();
    cout << "yourr * is";
    matrix m;
    m = m1.operator*(m2);
    for (int i = 0; i < 3; i++)
    {
        cout << endl;
        for (int j = 0; j < 3; j++)
        {
            cout << m.mat[i][j] << " ";
        }
    }
    return 0;
}
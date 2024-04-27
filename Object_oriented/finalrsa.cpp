#include <iostream>
#include <math.h>
using namespace std;
// find gcd
// 2 random prime numbers
double p = 13;
double q = 11;
double n = p * q; // calculate n
double track;
double phi = (p - 1) * (q - 1); // calculate phi
double e = 7;
double d1 = 1 / e;
double d = fmod(d1, phi);
// public key
// e stands for encrypt
int gcd(int a, int b)
{
    int t;
    while (1)
    {
        t = a % b;
        if (t == 0)
            return b;
        a = b;
        b = t;
    }
}
void RSA(string letter)
{
    float m[500];
    float c[500];
    char ch[500];
    for (int i = 0; i < letter.length(); i++)
    {
        char x = letter.at(i);
        m[i] = int(x);
        c[i] = pow(m[i], e); // encrypt the message
        m[i] = (pow(c[i], d));
        ch[i] = char(m[i]);
    }
    
    cout<< "p = " << p;
    cout << "\n"
         << "q = " << q;
    cout << "\n"
         << "n = pq = " << n;
    cout << "\n"
         << "phi = " << phi;
    cout << "\n"
         << "e = " << e;
    cout << "\n"
         << "d = " << d;
    cout << "\n"
         << "Encrypted message = ";
    for(int i=0;i<letter.length();i++ )
    {cout << c[i]<<" ";}
    cout << "\n"
         << "Decrypted message = " << ch;
   
}
int main()
{

    // for checking that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n) are coprime.

    // private key
    // d stands for decrypt
    // choosing d such that it satisfies d*e = 1 mod phi
    cout<<"Enter a message to send"<<endl;
    char msg[100];
    cin >> msg;
    cout << "Original Message = " << msg;
    cout << "\n";
    RSA(msg);
    
    return 0;
}

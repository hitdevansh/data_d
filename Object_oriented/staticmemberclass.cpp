#include<iostream>
using namespace std;
    class test
    {
        int code;
        static int c;
        public:
        void setcode(void)
        {
            code=++c;
        }
        void showcode()
        {
            cout<<"object number:"<<code<<"\n";
        }
        static void showcount()
        {
            cout<<"count:"<<c<<"\n";
        }
    };
    int test :: c;
    int main()
    {
        test t1,t2;
        t1.setcode();
        t2.setcode();
        test :: showcount();
        test t3;
        t3.setcode();
        test :: showcount();
        t1.showcode();
        t2.showcode();
        t3.showcode();
    }

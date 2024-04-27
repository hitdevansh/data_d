// syntax*****************
// class className {
//     ... .. ...
//     public
//        returnType operator symbol (arguments) {
//            ... .. ...
//        } 
//     ... .. ...
// };
// example
// Overload ++ when used as prefix

// #include <iostream>
// using namespace std;

// class Count {
//    private:
//     int value;

//    public:

//     // Constructor to initialize count to 5
//     Count() : value(9) {}

//     // Overload ++ when used as prefix
//     void operator -- () {
//         value+=10;
//     }

//     void display() {
//         cout << "Count: " << value << endl;
//     }
// };

// int main() {
//     Count count1;

//     // Call the "void operator ++ ()" function
//     --count1;

//     count1.display();
//     return 0;
// }
//-->here at 26 line and 39 operators shold be same u can change it in your code eighther u want multiplication 
//   or division or substraction 



// // Overload ++ when used as prefix and postfix

#include <iostream>
using namespace std;

class Count {
   private:
    int value;

   public:

    // Constructor to initialize count to 5
    Count() : value(5) {}


    // Overload ++ when used as prefix
    void operator ++ () {
        ++value;
    }


    // Overload ++ when used as postfix
    void operator ++ (int) {
        value++;
        cout<<value<<endl;
    }

    void display() {
        cout << "Count: " << value << endl;
    }
};

int main() {
    Count count1;

    // Call the "void operator ++ (int)" function
    count1++;
    count1.display();

    // Call the "void operator ++ ()" function
    ++count1;

    count1.display();
    return 0;
}
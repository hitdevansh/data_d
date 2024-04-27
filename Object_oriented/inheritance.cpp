// //single inheritance
// // C++ program to explain
// // Single inheritance
// #include<iostream>
// using namespace std;
// // base class
// class Vehicle {
// public:
// 	Vehicle()
// 	{
// 	cout << "This is a Vehicle\n";
// 	}
// };
// // sub class derived from a single base classes
// class Car : public Vehicle {
// int a=10;
// public:
// Car(){
// cout<<"Hello"<<a;}
// };
// // main function
// int main()
// {
// 	// Creating object of sub class will
// 	// invoke the constructor of base classes
// 	Car obj;
// 	return 0;
// }

// //Multiple class
// // C++ program to explain
// // multiple inheritance
#include<iostream>
using namespace std;
// first base class
class Vehicle {
public:
	Vehicle()
	{
	cout << "This is a Vehicle\n";
	}
};
// second base class
class FourWheeler {
public:
	FourWheeler()
	{
	cout << "This is a 4 wheeler Vehicle\n";
	}
};
// sub class derived from two base classes
class Car : public FourWheeler, public Vehicle {
    public:
    int point=5;
    friend void set(Car a,int i)
    {
        a.point=i;
        cout<<a.point<<endl;
    }
    void operator - ();
};
 void Car :: operator - (){point=-point;}
// main function
int main()
{
	// Creating object of sub class will
	// invoke the constructor of base classes.
	Car obj;
    //set(obj,5);
    -obj;
    cout<<obj.point<<endl;
	return 0;
}

// //Multilevel inheritance
// // C++ program to implement
// // Multilevel Inheritance
// #include<iostream>
// using namespace std;
// // base class
// class Vehicle
// {
// public:
// 	Vehicle()
// 	{
// 	cout << "This is a Vehicle\n";
// 	}
// };
// // first sub_class derived from class vehicle
// class fourWheeler: public Vehicle
// { public:
// 	fourWheeler()
// 	{
// 	cout << "Objects with 4 wheels are vehicles\n";
// 	}
// };
// // sub class derived from the derived base class fourWheeler
// class Car: public fourWheeler {
// public:
// 	Car()
// 	{
// 	cout << "Car has 4 Wheels\n";
// 	}
// };
// // main function
// int main()
// {
// 	// Creating object of sub class will
// 	// invoke the constructor of base classes.
// 	Car obj;
// 	return 0;
// }

// //Hierarchical inheritance
// // C++ program to implement
// // Hierarchical Inheritance
// #include<iostream>
// using namespace std;
// // bse class
// class Vehicle
// {
// public:
// 	Vehicle()
// 	{
// 	cout << "This is a Vehicle\n";
// 	}
// };
// // first sub class
// class Car: public Vehicle
// {

// };
// // second sub class
// class Bus: public Vehicle
// {
	
// };
// // main function
// int main()
// {
// 	// Creating object of sub class will
// 	// invoke the constructor of base class.
// 	Car obj1;
// 	Bus obj2;
// 	return 0;
// }

// //Hybride inheeritance
// // C++ program for Hybrid Inheritance
// #include<iostream>
// using namespace std;
// // base class
// class Vehicle
// {
// public:
// 	Vehicle()
// 	{
// 	cout << "This is a Vehicle\n";
// 	}
// };
// //base class
// class Fare
// {
// 	public:
// 	Fare()
// 	{
// 		cout << "Fare of Vehicle\n";
// 	}
// };
// // first sub class
// class Car : public Vehicle
// {

// };
// // second sub class
// class Bus : public Vehicle, public Fare
// {
// };
// // main function
// int main()
// {
// 	// Creating object of sub class will
// 	// invoke the constructor of base class.
// 	Bus obj2;
// 	return 0;
// }

//6. A special case of hybrid inheritance: Multipath inheritance
// // C++ program demonstrating ambiguity in Multipath
// // Inheritance
// #include<iostream>
// class ClassA {
// public:
// 	int a;
// };
// class ClassB : public ClassA {
// public:
// 	int b;
// };
// class ClassC : public ClassA {
// public:
// 	int c;
// };
// class ClassD : public ClassB, public ClassC {
// public:
// 	int d;
// };
// int main()
// {
// 	ClassD obj;
// 	// obj.a = 10;				 // Statement 1, Error
// 	// obj.a = 100;				 // Statement 2, Error
// 	obj.ClassB::a = 10; // Statement 3
// 	obj.ClassC::a = 100; // Statement 4
// 	obj.b = 20;
// 	obj.c = 30;
// 	obj.d = 40;
// 	cout << " a from ClassB : " << obj.ClassB::a;
// 	cout << "\n a from ClassC : " << obj.ClassC::a;
// 	cout << "\n b : " << obj.b;
// 	cout << "\n c : " << obj.c;
// 	cout << "\n d : " << obj.d << '\n';
// }


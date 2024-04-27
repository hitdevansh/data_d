#include <iostream>
using namespace std;
	void my_function(int &x,int &y) {
	int temp;
	temp=y;
	y=x;
	x=temp;

}

	int main() {
	int x,y;
	cout<<"Enter the two values"<<endl;
	cin>>x>>y;
	cout << "Value of x from main function: " << x<<endl;
	cout << "Value of y from main function: " << y<<endl;
	my_function(x,y);
	cout << "Value of x after my function: " << x<<endl;
	cout << "Value of y after my function: " << y<<endl;
	return 0;
}



// C++ implementation of tree using array
// numbering starting from 0 to n-1.
#include<iostream>
#include<string.h>
using namespace std;
char tree[10];int capacity=0;
int root(char key) {
if (tree[0] != '\0')
	cout << "Tree already had root";
else
	tree[0] = key;
	capacity++;
return 0;
}

int set_left(char key, int parent) {
if (tree[parent] == '\0' || tree[(parent*2)+1])
	cout << "\nCan't set child at "
	<< (parent * 2) + 1
	<< " , no parent found or already have a key at that place";
else
	tree[(parent * 2) + 1] = key;
	capacity++;
return 0;
}

int set_right(char key, int parent) {
if (tree[parent] == '\0')
	cout << "\nCan't set child at "
	<< (parent * 2) + 2
	<< " , no parent found or already have a key at that place";
else
	tree[(parent * 2) + 2] = key;
	capacity++;
return 0;
}

int print_tree() {
cout << "\n";
for (int i = 0; i < 10; i++) {
	if (tree[i] != '\0')
	cout <<" ' "<<tree[i]<<" ' ";
	else
	cout << "-";
}
return 0;
}
void Delete(char key)
{
	for(i=0; i<tot; i++)
    {
        if(tree[i]==key)
        {
            for(j=i; j<(tot-1); j++)
                key[j] = key[j+1];
            found++;
            i--;
            tot--;
        }
    }
    if(found==0)
        cout<<"\nElement doesn't found in the Array!";
    else
        cout<<"\nElement Deleted Successfully!";
	

}
// Driver Code
int main() {
root('A');
//insert_left('B',0);
set_right('C', 0);
set_left('D', 1);
set_left('D', 1);
set_right('E', 1);
set_right('F', 2);
print_tree();

Delete('C');
print_tree();
return 0;
}

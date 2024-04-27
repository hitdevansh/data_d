// // C++ program for implementation
// // of Bubble sort
// #include <bits/stdc++.h>
// using namespace std;
// // A function to implement bubble sort
// void bubbleSort(int arr[], int n)
// {
//     int i, j, temp;
//     while (i < n)
//     {
//         for (j = 0; j < n - i - 1; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//             temp = arr[j];
//             arr[j] = arr[j + 1];
//             arr[j + 1] = temp;}
//             }
//         i++;
//     }
//     int p;
//     for (p = 0; p < n; p++)
//         cout << arr[p] << " ";
//     cout << endl;
// }

// int main()
// {
//     int arr[] = {5, 1, 4, 2, 8};
//     int N = sizeof(arr) / sizeof(arr[0]);
//     bubbleSort(arr, N);
//     cout << "Sorted array: \n";
    
//     return 0;
// }



//insertion shorting
// C++ program for insertion sort
#include <bits/stdc++.h>
using namespace std;
// Function to sort an array using
// insertion sort
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}
// A utility function to print an array
// of size n
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}
// Driver code
int main()
{
	int arr[] = { 12, 11, 37, 187,2588, 5, 6 };
	int N = sizeof(arr) / sizeof(arr[0]);
	insertionSort(arr, N);
	printArray(arr, N);
	return 0;
}

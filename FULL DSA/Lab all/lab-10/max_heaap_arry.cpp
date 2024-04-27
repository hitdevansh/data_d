#include <iostream>
#include <math.h>
#include <limits.h>
using namespace std;
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

class maxheap
{
public:
    int capacity;
    int heapsize;
    int *heap;
    maxheap(int cap)
    {
        heap = new int[cap];
        capacity = cap;
        heapsize = 0;
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int left(int i)
    {
        return (2 * i + 1);
    }

    int right(int i)
    {
        return (2 * i + 2);
    }

    int getmax()
    {
        return heap[0];
    }

    void linearSearch(int val)
    {
        for (int i = 0; i < heapsize; i++)
        {
            if (heap[i] == val)
            {
                cout << "Value Found!";
                return;
            }
        }
        cout << "Value NOT Found!";
    }

    void insert(int k)
    {
        if (capacity == heapsize)
        {
            cout << "YOur heap is full. " << endl;
        }
        else
        {
            heapsize++;
            int i = heapsize - 1;
            heap[i] = k;
            while (i != 0 && heap[parent(i)] < heap[i])
            {
                swap(heap[i],heap[parent(i)]);
                i = parent(i);
            }
        }
    }
    void maxHeapify(int i)
    {   //int L=0,R=0;
        int l= left(i);
        int r=right(i);
        int largest =i;
        if(l<heapsize && heap[l]> largest[i])
        {largest=l;
        }
        if(r<heapsize && heap[r]> largest[i])
        {largest=r;
        }
        if(largest!=i)
        {  
            cout<<heap[i]<<" and "<<heap[largest]<<endl;
            swap(heap[largest],heap[i]);
            maxHeapify(largest);
        }
    }
    void increaseKey(int i)
    {
        heap[i] = INT_MAX;

        while (i != 0 && heap[parent(i)] < heap[i])
        {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }
    void printa()
    {
        for(int i=0;i<heapsize;i++)
        {
            cout<<heap[i]<<" ";
        }
    }
    int deleteKey(int i)
    {
        increaseKey(i);
        if(heapsize<0)
        {
            return INT_MIN;
        }
        if(heapsize==1)
        {
            heapsize--;
            return heap[0];
        }
        
        
        heap[0]=heap[heapsize-1];
        heapsize--;
        maxHeapify(0);
        
        return heap[0];
    }
};
int main()
{  int s;
  cout << "Enter Size of Min Heap" << endl;
  cin >> s;
  maxheap obj(s);
  cout << "Min Heap Created" << endl;

  int option, val;

  do {
    cout << "What operation do you want to perform? " <<
      " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Key/Node" << endl;
    cout << "2. Search Key/Node" << endl;
    cout << "3. Delete Key/Node" << endl;
    cout << "4. Get Min" << endl;
    cout << "6. Height of Heap" << endl;
    cout << "7. Print/Traversal Heap values" << endl;
    cout << "0. Exit Program" << endl;

    cin >> option;

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "INSERT Operation -" << endl;
      cout << "Enter VALUE to INSERT in HEAP: ";
      cin >> val;
      obj.insert(val);
      cout << endl;
      break;
    case 2:
      cout << "SEARCH Operation -" << endl;
      cout << "Enter VALUE to SEARCH in HEAP: ";
      cin >> val;
      obj.linearSearch(val);
      break;
    case 3:
      cout << "DELETE Operation -" << endl;
      cout << "Enter INDEX of Heap Array to DELETE: ";
      cin >> val;
      if(val>obj.heapsize){
        cout<<"please choose valid option to delete"<<endl;
        break;
      }
      obj.deleteKey(val);
      break;
    case 4:
      cout << "GET Min value : " << obj.getmax();
      cout << endl;
      break;
    case 7:
      cout << "PRINT Heap Array : " << endl;
      obj.printa();

      cout << endl;
      break;

    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}
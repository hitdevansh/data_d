#include <iostream>
using namespace std;
#define n 10
int queue[n];
int front = -1, rear = -1;
void enque(int p)
{
    if (rear == n - 1)
    {
        cout << "it is a overflow condiion" << endl;
    }
    else if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        queue[front]=p;
        queue[rear] = p;
    }
    else
    {
        rear++;
        queue[rear] = p;
    }
}
void deque()
{
    if (front == -1 && rear == -1)
    {
        cout << "underflow";
    }
    else if (front == rear)
    {
        cout << "u have deque " << queue[front] << endl;
        front++;
        
    }
    else
    {
        cout << "u have deque " << queue[front] << endl;
        front++;
    }
}
void display()
{
    if (front == -1 && rear == -1)
    {
        cout << "nothing to display" << endl;
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << endl;
        }
    }
}
void peak()
{
    if (front == -1 && rear == -1)
    {
        cout << "nothing to peak" << endl;
    }
    else
        cout << "your peak is " << queue[front] << endl;
}
int main()
{
    int x;
jump:
    cout << endl
         << "Enter a value according given below for ur operations" << endl
         << "for enque choose 1" << endl
         << "for deque choose 2" << endl
         << "for peak choose 3" << endl
         << "for display choose 4" << endl;
    cin >> x;
    switch (x)
    {
    case 1:
    {
        int p;
        cout << "enter your value to store in queue" << endl;
        cin >> p;
        enque(p);
        goto jump;
        break;
    }
    case 2:
    {
        cout << "u have choose to pop" << endl;
        deque();
        goto jump;
        break;
    }
    case 3:
    {
        cout << "u have choose to see peak" << endl;
        peak();
        goto jump;
        break;
    }

    case 4:
    {
        cout << "u have choose to see display enque elements" << endl;
        display();
        goto jump;
        break;
    }

    default:
        break;
    }
    return 0;
}
#include <iostream>
using namespace std;

struct node
{
    node *prev;
    int data;
    node *next;
};
node *head;
class DoublyLL
{
public:
    // creating DLL
    DoublyLL()
    {
        head = NULL;
    }

    void insert_at_starting(int val)
    {
        // create new node
        node *new_node = new node;
        new_node->data = val;
        new_node->prev = NULL;
        new_node->prev = NULL;

        // if head is null
        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    void insert_at_end(int val)
    {
        node *new_node = new node;
        node *tmp;
        new_node->data = val;
        new_node->next = NULL;
        new_node->prev = NULL;

        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            tmp = head;
            // going to end
            while (tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = new_node;
            new_node->prev = tmp;
            new_node->next = NULL;
        }
    }

    void update(int val, int newval)
    {
        node *tmp = head;
        while (tmp->next != NULL)
        {
            if (tmp->data == val)
            {
                tmp->data = newval;
                return;
            }
            tmp->data = newval;
        }
        cout << endl;
        return;
    }

    void remove(int val)
    {
        // removing from start
        if (head->data == val)
        {
            delete head;
            head = head->next;
            return;
        }

        // if DLL has only one node
        if (head->next == NULL)
        {
            if (head->data == val)
            {
                delete head;
                head = NULL;
                return;
            }
            cout << "Value not found1\n";
            return;
        }

        // remove from inside DLL
        node *tmp = head;
        while (tmp->next != NULL)
        {
            if (tmp->next->data == val)
            {
                node *temp_ptr = tmp->next->next; // save the next of next in a temperory variable
                delete tmp->next;
                tmp->next = temp_ptr;
                return;
            }
            tmp = tmp->next;
        }
        cout << "Value not found2" << endl;
    }
     void insertafternode(node *&prev, int n)
    {
        if (prev->next == head)
        {
            insert_at_starting( n);
            return;
        }
        node *new_node = new node;
        new_node->data = n;
        new_node->next = NULL;
        new_node->prev=NULL;

        new_node->next = prev->next;
        prev->next = new_node;
        new_node->prev=new_node->next->prev;
        new_node->next->prev=new_node;

    }
         void insertbeforenode(node *&prev, int n)
    {
        if (prev->next == head)
        {
            insert_at_starting( n);
            return;
        }
        node *new_node = new node;
        new_node->data = n;
        new_node->next = NULL;
        new_node->prev=NULL;

        new_node->next = prev->next;
        prev->next = new_node;
        new_node->prev=new_node->next->prev;
        new_node->next->prev=new_node;

    }

    bool search(int val)
    {
        node *tmp = head;
        while (tmp != NULL)
        {
            if (tmp->data == val)
            {
                return true;
            }
            tmp = tmp->next;
        }
        return false;
    }

    void display()
    {
        node *tmp = head;
        while (tmp->next!=NULL)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << tmp->data << " ";
        cout << endl;
    }
    void displayrev()
    {   struct node* tail = head;
        cout<<"You have choose to print in reverse order "<<endl;
         while (tail->next != NULL) {
        tail = tail->next;
    }
  
    // Traversing linked list from tail
    // and printing the node->data
    while (tail != head) {
        cout << tail->data << " ";
        tail = tail->prev;
    }
    cout << tail->data << endl;
    }
};

int main()
{   DoublyLL d;
     while (1)
    {
        int ch;
        cout <<endl<<"Enter your choice " << endl;
        cout << "Enter 1. for the insertion at the end of the linked list: - \nEnter 2. for the insertion at the front of the linked list:-"
             << "\nEnter 3.for the insertion after position\nEnter 4. for the display the elements:-"
             << "\nEnter 0. to quit the program:- " << endl<<"Enter 5 to delete a node "<<endl<<"Enter 6 to insert before a position\n"<<
             "Enter 7 to print in reverse order "<<endl;
        cin >> ch;
        if (ch == 0)
        {
            exit(0);
        }

        else if (ch == 1)
        {
            cout << endl
                 << "Enter your data to store at end " << endl;
            int end;
            cin >> end;
            d.insert_at_end(end);
        }
        else if (ch == 2)
        {
            cout << endl
                 << "Enter your data to store at front " << endl;
            int front;
            cin >> front;
            d.insert_at_starting(front);
        }

        else if (ch == 3)
        {
            cout << endl
                 << "Enter the element after which you want to insert new element  " << endl;
            int prev;
            cin >> prev;
            node *tmp = head;
            while (tmp->data != prev)
            {
                tmp = tmp->next;
            }
            cout << endl
                 << "Enter your data to store at next position " << endl;
            int front;
            cin >> front;
            d.insertafternode(tmp,front);
        }
        else if (ch ==6 )
        {
            cout << endl
                 << "Enter the element before which you want to insert new element  " << endl;
            int prev;
            cin >> prev;
            node *tmp = head;
            while (tmp->data != prev)
            {
                tmp = tmp->next;
            }
            tmp=tmp->prev;
            cout << endl
                 << "Enter your data to store at before position " << endl;
            int front;
            cin >> front;
            d.insertbeforenode(tmp,front);
        }

        else if (ch == 4)
        {
            d.display();
        }
        else if (ch == 7)
        {
            d.displayrev();
        }
        else if (ch == 5)
        {
            cout << "Enter the element which you want to delete" << endl;
            int del;
            cin >> del;
            d.remove(del);
        }
        else{cout<<"please enter a valid choice "<<endl;}
    }
    return 0;
}
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
void apend(node *&head, int v);
void insertatfront(node *&head, int newdata)
{
    node *new_node = new node;
    new_node->data = newdata;
    new_node->next = NULL;

    // if head is Null(means that this is first node, then make head as pointer to new_nodenewdatif (head == NULL)
    if(head==NULL)
    {
        head = new_node;
    }
    // else assign next of new_node to previous head and assign head to new_node
    else
    {
        new_node->next = head;
        head = new_node;
    }
}

void insertfollwingnode(node *&prev, node *&head, int n)
{

    if (prev->next == head)
    {
        apend(head, n);
        return;
    }
    node *new_node = new node;
    new_node->data = n;
    new_node->next = NULL;

    new_node->next = prev->next;
    prev->next = new_node;
}

void apend(node *&head, int v)
{
    node *newdata = new node();
    newdata->data = v;
    if (head == NULL)
    {
        head = newdata;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newdata;
}

void deletenode(node *&head, int newdata)
{
    // removing from start
    if (head->data == newdata)
    {
        delete head;
        head = head->next;
        return;
    }

    // if linked list has only one node
    if (head->next == NULL)
    {
        if (head->data == newdata)
        {
            delete head;
            head = NULL;
            return;
        }
        cout << "value not found\n";
        return;
    }

    // from inside the linked list
    node *tmp = head;
    while (tmp->next != NULL)
    {
        if (tmp->next->data == newdata)
        {
            node *temp_ptr = tmp->next->next; // save the next of next in a temperory variable
            delete tmp->next;
            tmp->next = temp_ptr;
            return;
        }
        tmp = tmp->next;
    }

    cout << "value not found" << endl;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node *head = NULL;
    node *second = NULL;
    node *third = NULL;

    head = new node();
    second = new node();
    third = new node();

    head->data = 1;      // assign data in first node
    head->next = second; // Link first node with

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    int n;

    while (1)
    {
        int ch;
        cout <<endl<<"Enter your choice " << endl;
        cout << "Enter 1. for the insertion at the end of the linked list: - \n Enter 2. for the insertion at the front of the linked list:-"
             << "\n Enter 3.for the insertion at the perticular position in the linked list:- \n Enter 4. for the display the elements:-"
             << "\n Enter 0. to quit the program:- " << endl;
        cin >> ch;
        if (ch == 0)
        {
            exit(0);
        }

        if (ch == 1)
        {
            cout << endl
                 << "Enter your data to store at end " << endl;
            int end;
            cin >> end;
            apend(head, end);
        }
        if (ch == 2)
        {
            cout << endl
                 << "Enter your data to store at front " << endl;
            int front;
            cin >> front;
            insertatfront(head, front);
        }

        if (ch == 3)
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
            insertfollwingnode(tmp, head, front);
        }

        if (ch == 4)
        {
            display(head);
        }

        if (ch == 5)
        {
            cout << "Enter the element which you want to delete" << endl;
            int del;
            cin >> del;
            deletenode(head, del);
        }
        else{cout<<"please enter a valid choice "<<endl;}
    }
    return 0;
}
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    void insertatfront(node *&head, int newdata)
    {
        node *new_node = new node;
        new_node->data = newdata;
        new_node->next = NULL;

        // if this is first node to create
        if (head == NULL)
        {
            head = new_node;
            new_node->next = head;
        }

        else
        {
            // traversing through complete CLL to assign last->next = head
            node *tmp = head;
            while (tmp->next != head)
            {
                tmp = tmp->next;
            }
            new_node->next = head;
            head = new_node;
            tmp->next = new_node; // connecting last to head
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

    void apend(node *&head, int val)
    {
        node *new_node = new node;
        node *tmp;
        new_node->data = val;
        new_node->next = NULL;

        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            tmp = head;
            do
            {
                tmp = tmp->next;
            } while (tmp->next != head);
            tmp->next = new_node;
            new_node->next = head;
        }
    }

    void deletenode(node *&head, int val)
    {
        if (head->data == val)
        {
            delete head;
            head = head->next;
            return;
        }

        // if CLL has only one node
        if (head->next == head)
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

        // remove from inside CLL
        node *tmp = head->next; // changeed to head->next bcoz it is already changed
        while (tmp != head)
        {
            if (tmp->next->data == val)
            {
                node *tmp_ptr = tmp->next->next;
                tmp->next = NULL;
                delete tmp->next;
                tmp->next = tmp_ptr;
                return;
            }
        }
        cout << "Value not found2\n";
    }

    void display(node *head)
    {
        node *tmp = head;
        cout << endl;
        do
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        } while (tmp != head);
        cout << endl
             << endl;
    }
};

int main()
{
    node n1;
    node *head = NULL;

    int n;

    while (1)
    {
        int ch;
        cout << endl
             << "Enter your choice " << endl;
        cout << "Enter 1. for the insertion at the end of the linked list: - \n Enter 2. for the insertion at the front of the linked list:-"
             << "\n Enter 3.for the insertion at the perticular position in the linked list:- \n Enter 4. for the display the elements:-"
             << "\n Enter 0. to quit the program:- " << endl;
        cin >> ch;
        if (ch == 0)
            exit(0);
        else if (ch == 1)
        {
            cout << endl
                 << "Enter your data to store at end " << endl;
            int end;
            cin >> end;
            n1.apend(head, end);
        }
        else if (ch == 2)
        {
            cout << endl
                 << "Enter your data to store at front " << endl;
            int front;
            cin >> front;
            n1.insertatfront(head, front);
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

            n1.insertfollwingnode(tmp, head, front);
        }
        else if (ch == 4)
        {
            n1.display(head);
        }
        else if (ch == 5)
        {
            cout << "Enter the element which you want to delete" << endl;
            int del;
            cin >> del;
            n1.deletenode(head, del);
        }
        else
        {
            cout << "please choose annother option " << endl;
        }
    }
    return 0;
}
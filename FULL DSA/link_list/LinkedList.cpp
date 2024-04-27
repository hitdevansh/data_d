#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

class LinkedList{
    node* head;

    public:
    //creating linked list and making head as null
        LinkedList(){
            head = NULL;
        }

        void insert_at_starting(int n){
            //create node
            node *new_node = new node;
            new_node->data = n;
            new_node->next = NULL;

            //if head is Null(means that this is first node, then make head as pointer to new_node)
            if (head == NULL){
                head = new_node;
            }
            //else assign next of new_node to previous head and assign head to new_node
            else{
                new_node->next = head;
                head = new_node;
            }
        }

        void reverse()
        {
            node *temp=head;
            node *prev=nullptr;
            node *nex=nullptr;
            while (temp!=nullptr)
            {   nex=temp->next;
                temp->next=prev;
                prev=temp;
                temp=nex;
                //nex=nex->next;
            }
            head=prev;
        }

        bool search(int val){
            node * tmp = head;
            while (tmp != NULL)
            {
                if(tmp->data == val){
                    return true;
                }
                tmp = tmp->next;
            }
            return false;
        }

        void remove(int val){
            //removing from start
            if(head->data == val){
                delete head;
                head = head->next;
                return;
            }

            //if linked list has only one node
            if (head->next == NULL)
            {
                if (head->data == val)
                {
                    delete head;
                    head = NULL;
                    return;
                }
                cout << "value not found\n";
                return;
            }

            // from inside the linked list
            node* tmp = head;
            while (tmp->next != NULL)  
            {
                if (tmp->next->data == val)
                {
                    node* temp_ptr = tmp->next->next; // save the next of next in a temperory variable
                    delete tmp->next;
                    tmp->next = temp_ptr;
                    return;
                }
                tmp = tmp->next;
            }

            cout << "value not found"<<endl;
        }

        void display(){
            node* temp = head;
            while(temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};


int main()
{
    LinkedList l;
    l.insert_at_starting(6);
    l.insert_at_starting(9);
    l.insert_at_starting(1);
    l.insert_at_starting(3);
    l.insert_at_starting(7);
    cout << "Current Linked List: ";
    l.display();

    // cout << "Deleting 1: ";
    // l.remove(1);
    // l.display();

    // cout << "Deleting 13: ";
    // l.remove(13);

    // cout << "Searching for 7: ";
    // cout << l.search(7) << endl;

    // cout << "Searching for 13: ";
    // cout << l.search(13) << endl;
    l.reverse();
    l.display();
}
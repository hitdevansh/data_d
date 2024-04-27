#include<iostream>
using namespace std;

struct node{
    node* prev;
    int data;
    node* next;
};

class DoublyLL{
    node *head;
    
    public: 
        //creating DLL
        DoublyLL(){
            head = NULL;
        }

        void insert_at_starting(int val){
            //create new node
            node *new_node = new node;
            new_node->data = val;
            new_node->prev = NULL;
            new_node->prev = NULL;

            //if head is null
            if(head == NULL){
                head = new_node;
            }
            else{
                new_node->next = head;
                head->prev = new_node;
                head = new_node;
            }
        }

        void insert_at_end(int val){
            node *new_node = new node;
            node *tmp;
            new_node->data = val;
            new_node->next = NULL;
            new_node->prev = NULL;

            if(head == NULL){
                head = new_node;
            }   
            else{
                tmp = head;
                //going to end
                while(tmp->next != NULL){
                    tmp = tmp->next;
                }
                tmp->next =new_node;
                new_node->prev = tmp;
                new_node->next = NULL;
            }
        }

        void update(int val, int newval){
            node *tmp = head;
            while(tmp->next != NULL){
                if(tmp->data == val){
                    tmp->data = newval;
                    return;
                }
                tmp->data = newval;
            }
            cout << endl;
            return;
        }

        void remove(int val){
            // removing from start
            if(head->data == val){
                delete head;
                head = head->next;
                return;}

            //remove from inside DLL
            node *tmp = head;
            while(tmp->next != NULL)
            {
                if(tmp->next->data == val)
                {
                    node* temp_ptr = tmp->next->next; // save the next of next in a temperory variable
                    delete tmp->next;
                    tmp->next = temp_ptr;
                    return; 
                }
                tmp = tmp->next;
            }
            cout << "Value not found2"<<endl;
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

        void display(){
            node *tmp = head;
            while(tmp  != NULL){
                cout << tmp->data<<" ";
                tmp = tmp->next;
            }
            cout << endl;
        }
};


int main()
{
    DoublyLL l;
    l.insert_at_starting(1);
    l.insert_at_starting(2);
    l.insert_at_end(4);
    l.insert_at_end(6);
    cout<<"searching for 2 : " << l.search(2) << endl;
    l.display();
    l.update(2,5);
    l.display();
    l.remove(6);
    l.display();
    return 0;
}
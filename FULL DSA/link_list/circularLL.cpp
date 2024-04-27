#include <iostream>
using namespace std;
struct node{
    int data;
    node *next;
};

class circularLL{
    node *head;

    public:
        //creating a circularLL
        circularLL(){
            head = NULL;
        }

        // /insertion in circular LL
        void insert_at_start(int val){
            node *new_node = new node;
            new_node->data = val;
            new_node->next = NULL;

            //if this is first node to create
            if(head == NULL){
                head = new_node;
                new_node->next = head;
            }

            else{
                //traversing through complete CLL to assign last->next = head
                node *tmp = head;
                while(tmp->next != head){
                    tmp = tmp->next;
                }
                new_node->next = head;
                head = new_node;
                tmp->next = new_node; // connecting last to head
            }
        }

        void insert_at_end(int val){
            node *new_node = new node;
            node *tmp;
            new_node->data = val;
            new_node->next = NULL;

            if(head == NULL){
                head = new_node;
            }   
            else{
                tmp = head;
                do{
                    tmp = tmp->next;
                }while(tmp->next != head);
                tmp->next =new_node;
                new_node->next = head;
            }
        }

        void update(int val,int newval){
            node *tmp = head;
            do{
                if(tmp->data == val){
                    tmp->data = newval;
                    return;
                }
                //tmp->data = newval;
            }while(tmp->next != head);
            cout << endl;
            return;
        }

        void remove(int val){{
            //remove from start
            if(head->data == val){
                delete head;
                head= head->next;
                return;
            }

            //if CLL has only one node
            if(head->next == head)
                cout<<"Value not found1\n";
                return;
            }

            //remove from inside CLL
            node *tmp = head->next;//changeed to head->next bcoz it is already changed
            while (tmp != head)
            {
                if(tmp->next->data == val){
                    node *tmp_ptr = tmp->next->next;
                    delete tmp->next;
                    tmp->next = tmp_ptr;
                    return;
                }
                tmp=tmp->next;
            }
            cout<<"Value not found2\n";
        }

        bool search(int val){
            node * tmp = head;
            do
            {
                if(tmp->data == val){
                    return true;
                }
                tmp = tmp->next;
            }while (tmp != head);
            return false;
        }


        void display()
        {
            node *tmp = head;
            do{
                cout << tmp->data<<" ";
                tmp = tmp->next;
            }while(tmp != head);
            cout<<endl;
        }


};
int main()
{
    circularLL l;
    l.insert_at_start(4);
    l.display();
    l.insert_at_start(5);
    l.display();
    l.insert_at_end(1);
    l.display();
    l.update(5,6);
    l.display();
    l.remove(1);
    l.display();
    cout<<"searching for 4 : " << l.search(4) << endl;
    return 0;
}

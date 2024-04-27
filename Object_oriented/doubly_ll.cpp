#include <iostream>
using namespace std;
struct Node {
   int data;
   struct Node *prev;
   struct Node *next;
};
struct Node* head = NULL;
struct Node* temp = NULL;
void insert(int newdata) {
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
   if(head==0)
   {head=newnode;
   newnode->data = newdata;
   newnode->prev=head;
   temp=newnode;
   }
   else
   { temp->next=newnode;
   newnode->data = newdata;
   newnode->prev = temp;
   newnode->next=NULL;
   temp=temp->next;
   }
}
void dfb()
{
   struct Node *temp;
   temp=head;
   head=head->next;
   head->prev=0;

}
void display() {
   struct Node* ptr;
   ptr = head;
   while(ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}
int main() {
   insert(3);
   insert(1);
   insert(7);
   insert(2);
   insert(9);
   cout<<"The doubly linked list is: ";
   display();
   dfb();
   cout<<"The doubly linked list is: ";
   display();
   return 0;
}
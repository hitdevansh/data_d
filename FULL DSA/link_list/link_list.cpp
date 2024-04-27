#include<iostream>
using namespace std;
class node
{   public:
    int data;
    class node *next;
};
node *head,*temp;
int choice=1;
void push()
{
    
  while (choice==1)
 {  
    int data;
    node *newnode=NULL;
    newnode=new node;
    cout<<"Enter  a data please"<<endl;
    cin>>data;
    newnode->data=data;
    newnode->next=0;
    if(head==0){
    head=newnode;
    temp=newnode;}
    else
    {
        temp->next=newnode;
        temp=newnode;
    }
    cout<<"Now if u want to continue push so press 1 or if u want so what u push so press 0"<<endl;
    cin>>choice;
 }
}
void dfp()
{
    node *nextnode;
    int position;
    int i;
    temp=head;
    cout<<endl<<"enter your position"<<endl;
    cin>>position;
    while(i<position-1)
    {
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    free(nextnode);
}
void display()
{
    temp=head;
    while(temp->next!=0)
 {
    cout<<temp->data<<endl;
    temp=temp->next;
 }
 cout<<temp->data;
 
 
}
void iap()
{   int i,position;
    cout<<endl<<"enter your position where u want to add"<<endl;
    cin>>i;
    node *newnode;
    newnode=new node;
    int data;
    cout<<endl<<"enter a data which u want to insert at the position"<<endl;
    cin>>data;
    newnode->data=data;
    temp=head;
    while(i<position){temp=temp->next;
    i++;}
    newnode->next=temp->next;
    temp->next=newnode;
}
void dfb()
{   cout<<endl;
    head=head->next;

}
void dfe()
{   
    cout<<endl;
    node *temp1;
    temp=head;
    while(temp->next!=0)
    {   temp1=temp;
        temp=temp->next;
    }
    temp1->next=0;
    free(temp);
}
void iae()
{
    node *newnode;
    newnode=new node;
    int data;
    cout<<endl<<"enter a data which u want to insert at the end"<<endl;
    cin>>data;
    temp=head;
    newnode->data=data;
    newnode->next=0;
    while (temp->next!=0)
    {   
        /* code */
        temp=temp->next;
        
    }
    temp->next=newnode;
}
void iab()
{   node *newnode=NULL;
    int data;
    cout<<endl<<"enter a data which u want to insert at the beginning"<<endl;
    cin>>data;
    newnode=new node; 
    newnode->data=data;
    newnode->next=head;
    head=newnode;
}
void rl()
{   node *cn,*nn,*pn;
    cn=head;
    pn=NULL;
    nn=head;
    while(nn!=0){nn=nn->next;
    cn->next=pn;
    pn=cn;
    cn=nn;
    }
    head=pn;
    cout<<endl<<endl;
}

int main()
{
push();
display();
// iab();
// display();
// iae();
// display();
// iap();
// dfp();
// display();
rl();
display();
return 0;
}
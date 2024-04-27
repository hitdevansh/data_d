#include<iostream>
using namespace std;
class node
{   public:
    int data;
   class node *next,*prev;
};
 node *head,*temp,*tail;
void push()
{  int count=1;
    while(count==1)
    { int data;
     node *newnode=NULL;
    newnode=new node;
    cout<<"enter a data for push"<<endl;
    cin>>data;
    newnode->data=data;
    newnode->prev=0;
    newnode->next=0;
    if(head==0){head=newnode;
    temp=newnode;}
    else{
        temp->next=newnode;
        newnode->prev=temp;
        temp=newnode;
        tail=temp;
        tail->prev=temp->prev;
    }
    cout<<"Now if u want to continue push so press 1 or if u want so what u push so press 0"<<endl;
    cin>>count;}
    
}
void iab()
{   int data;
    node *newnode=NULL;
    newnode=new node;
    cout<<endl<<"enter a data for push begin"<<endl;
    cin>>data;
    newnode->data=data;
    newnode->prev=0;
    newnode->next=0;
    head->prev=newnode;
    newnode->next=head;
    head=newnode;

}
void ial()
{
    int data;
    node *newnode=NULL,*temp2;
    newnode=new node;
    cout<<endl<<"enter a data for push last"<<endl;
    cin>>data;
    newnode->data=data;
    newnode->prev=0;
    newnode->next=0;
    temp2=head;
    while(temp2!=0)
    {
        temp2=temp2->next;
    }
    temp2->next=newnode;
    newnode->prev=temp2;
    temp2=newnode;
    tail=temp2;
    tail->prev=temp->prev;
}
void dfb()
{   cout<<endl;
    head=head->next;

    }
void display()
{
    node *temp1;
    temp1=head;
    while(temp1!=0)
    {
    cout<<temp1->data;
    temp1=temp1->next;    }
}
void dfl()
{   node *temp;
    temp=tail;
    tail->prev->next=0;
    tail=tail->prev;
    free(temp);
    
}
void rl()
{   node *nn,*cn;
    node *current;
    cn=head;
    while(cn!=0)
    {
        nn=cn->next;
        cn->next=cn->prev;
        cn->prev=nn;
        cn=nn;
    }
    cn=head;
    head=tail;
    tail=cn;
}
int main()
{
push();
display();
rl();
display();
return 0;
}
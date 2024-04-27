#include <iostream>
using namespace std;
int y;

class node{
public:
int data;
node *next;
void insertatb(int y);
void insertate(int y);
void insertatp(int y);
void deleted(int y);
void display();
};

node* head=NULL;
node* temp=NULL;
node *newnode=NULL;
node *temp1=NULL;

void node::insertatb(int y){
node* newnode=new node;
cout<<"enter value to be inserted at beginning:"<<endl;
cin>>y; 
temp1=head;
newnode->data=y;
newnode->next=head;
temp=head;
head=newnode;
do{
    temp=temp->next;
}while(temp->next!=temp1);
temp = temp->next;
while(temp->next!=temp1){
    temp=temp->next;
}
temp->next=head;
}

void node::insertate(int y){
node* newnode=new node;
cout<<"enter value to be inserted at end:"<<endl;
cin>>y; 
newnode->data=y;
temp=head;
while(temp->next!=head)
{
temp=temp->next;
}
temp->next=newnode;
newnode->next=head;
}

void node::insertatp(int y){
int pos,i=1;
node* newnode=new node;
cout<<"enter value to be inserted at position:"<<endl;
cin>>y;
cout<<"enter position where data is to be inserted:"<<endl;
cin>>pos;
newnode->data=y;
temp=head;
while((i+1)<pos){
temp=temp->next;
i++;
}
newnode->next=temp->next;
temp->next=newnode; 
}

void node::deleted(int y){
  
    temp=head;
    cout<<"enter value to be deleted from the list:"<<endl;
    cin>>y;
    while(temp->next!=head){
        if(head->data==y){
            temp1=head;
            temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            head=head->next;
            temp->next=head;
            free(temp1);
            return;
        }
        else if(temp->next->data==y){
            temp1=temp->next;
            temp->next=temp->next->next;
            free(temp1);
            return;
        }
       
        
        temp=temp->next;
    }
    cout<<"not in the list"<<endl;
}

void node::display(){
temp=head;
while(temp->next!=head){
cout<<temp->data<<endl;
temp=temp->next;
}
cout<<temp->data<<endl;
}



int main()
{ node a;
int x,choice;
temp=head;
while(choice){
node* newnode=new node;
cout<<"enter data to be entered:"<<endl;
cin>>x;
newnode->data=x;
newnode->next=head;
if(head==NULL){
temp=head=newnode;
}
else{
temp->next=newnode;
temp=newnode;

}
cout<<"do you want to continue?(0/1)"<<endl;
cin>>choice;
}
int ch;
do{
cout<<"enter number corresponding to the operation you want to perform:"<<endl;
cout<<"0)exit  1)insert at beginning  2)insert at end  3)insert at position  4)delete a node containing value provided 5)for display"<<endl;
cin>>ch;
if(ch==1){
a.insertatb(y);
}
else if(ch==2){
a.insertate(y);

}
else if(ch==3){
a.insertatp(y);

}
else if(ch==4){
a.deleted(y);

}
else if(ch==5)
{
	a.display();
}
}while(ch!=0);
return 0;
}
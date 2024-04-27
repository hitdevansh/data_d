#include <iostream>
using namespace std;
class queue;
class node;
class nodequeue
{
  public:
  node* data;
  nodequeue* next;
  nodequeue(node* v)
  {
      data=v;
      next=nullptr;
  }
  
};
class node{
    public:
    int data;
    bool color;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        color=0;
        left=right=0;
    }
};

class queue{
public:
nodequeue *front=nullptr;
nodequeue *rear=nullptr;
void enque(node* val);
void deque();
int empty();
};
node * mainroot=NULL;
void queue:: enque(node* val)
{
    nodequeue* n=new nodequeue(val);
    if(front==nullptr)
    {
        front=rear=n;
        return;
    }
    rear->next=n;
    rear=n;
}

void queue:: deque()
{
    if(front==nullptr)
    {   rear=nullptr;
        cout<<"queue is empty ";
        return;
    }
    nodequeue* temp=front;
    front=front->next;
    delete(temp);
}

int queue:: empty()
{
    if(front==nullptr)
    return 1;
    return 0;
}
node * insert(node * root,int data)
{   cout<<"HII"<<endl;
    if(root==0){root=new node(data);
    cout<<" Inserted "<<root<<" index have "<<root->data<<endl;
    return root;}
    if(root->data<data){root->right=insert(root->right,data);}
    else{root->left=insert(root->left,data);}
    return root;
}
void displayinorder(node * head)
{
    {
        if((head)==0) return ;
        if(head->left) displayinorder(head->left);
        cout<<head->data<<" ";
        if(head->right) displayinorder(head->right);
    }
}
void displaypreoreder(node * head)
{
         if((head)==0) return ;
         cout<<head->data<<" ";
         if(head->left) displaypreoreder(head->left);
         if(head->right) displaypreoreder(head->right);
}


void displaypostoreder(node * head)
{
        if(head==0) return;
        if(head->left) displaypostoreder(head->left);
        if(head->right) displaypostoreder(head->right);  
        cout<<head->data<<" ";
}

void displaylevelorder(node* root)
{   cout<<"it is called "<<endl;
    if(root==NULL)
    return ;
    queue q;
    q.enque(root);
    while(!q.empty())
    {
        node *n=q.front->data;
        cout<<" "<<n->data<<"---"<<n->color;
        q.deque();
        if(n->left)
        {
            q.enque(n->left);
        }
         if(n->right)
        {
            q.enque(n->right);
        }  
    }
}

node * makeredblack(node * root,int data)
{  
    if(root==0) {
        //cout<<"1"<<endl;
        return NULL;}
    if(root && (root->data==data)&& (root==mainroot))
        {    cout<<"a"<<endl;
            mainroot->color=1;
            return root;
        }
    else if(((root->left && root->left->data==data) || (root->right && root->right->data==data)) && root==mainroot){
    cout<<"b"<<endl;
    return root;}

    if(root && (root->left) && (root->left->left) && (root->left->left->data==data))
    {   cout<<"1"<<endl;
        if(root->left->color==1) {
            cout<<"c"<<endl;
            return root;}
        else if(root->right && root->right->color==0)
        {   cout<<"d"<<endl;
            root->left->color=root->right->color=1;
            if(root!=mainroot){root->color=0;}
            data=root->data;
            return root;
        }
        else
        {   cout<<"e"<<endl;
            node * temp=root->left->right;
            root->left->right=root;
            root=root->left;
            root->right->left=temp;
            root->color=1;
            root->right->color=0;
            return root;
        }
    }
    else if(root && (root->left) && (root->left->right) && (root->left->right->data==data))
    {   cout<<"2"<<endl;
        if(root->left->color==1) {
            cout<<"f"<<endl;
            return root;}
        else if(root->right && root->right->color==0)
        {   cout<<"g"<<endl;
            root->left->color=root->right->color=1;
            if(root!=mainroot){root->color=0;}
            data=root->data;
            return root;
        }
        else
        {   cout<<"h"<<endl;
            node * temp=root->left->right;
            temp->left=root->left;
            temp->right=root;
            root->left->right=0;
            root->left=0;
            root=temp;
            root->color=1;
            root->right->color=0;
            return root;
        }
    }
    else if(root && (root->right) && (root->right->left) && (root->right->left->data==data))
    {   cout<<"3"<<endl;
        if(root->right->color==1) {
            cout<<"i"<<endl;
            return root;}
        else if(root->left && root->left->color==0)
        {   cout<<"j"<<endl;
            root->left->color=root->right->color=1;
            if(root!=mainroot)root->color=0;
            data=root->data;
            return root;
        }
        else
        {   cout<<"k"<<endl;
            node * temp=root->right->left;
            temp->left=root;
            temp->right=root->right;
            root->right->left=0;
            root->right=0;
            root=temp;
            root->color=1;
            root->left->color=0;
            return root;
        }
    }
    else if(root && (root->right) && (root->right->right) && (root->right->right->data==data))
    {   cout<<"4"<<endl;
        if(root->right->color==1){
            cout<<"l"<<endl;
             return root;}
        else if(root->left && root->left->color==0)
        {   cout<<"m"<<endl;
            root->left->color=root->right->color=1;
            if(root!=mainroot){root->color=0;}
            data=root->data;
            return root;
        }
        else
        {   cout<<"n"<<endl;
            node * temp=root->right->left;
            root->right->left=root;
            root=root->right;
            root->left->right=temp;
            root->color=1;
            root->left->color=0;
            return root;
        }
    }
     node * temp=root;
     root->left=makeredblack(root->left ,data);
     root=temp;
     root->right=makeredblack(root->right,data);
     root=temp;
     //root->
     return root;
}
int height(node *root)
{
    int x;
    int y;
    if(root==nullptr){return 0;}
    x=height(root->left);
    y=height(root->right);
    return x>y?x+1:y+1;}

int main()
{
    node* root=0;
    while(1)
    {
        cout<<"for insert enter  : 1 \n";
        cout<<"for display enter : 2 \n";
        cout<<"for quit enter    : q \n";
        char c;
        cin>>c;
        if(c=='q') return 0;
        switch(c)
        {
            case '1':
            cout<<"enter a data you want to insert :  ";
            int data;
            cin>>data;
            root=insert(root,data);
            cout<<"iII"<<endl;
            int he;
            he=height(root);
            mainroot=root;
            for(int i=0;i<he;i++){root=makeredblack(root,data);}
            cout<<endl<<height(root)<<endl;
            break;
            
            case '2':
            displaylevelorder(root);
            cout<<endl<<"post order is:"<<endl;
            displaypostoreder(root);
            break;
            default:
            cout<<"unvalied choice please enter valid choice : \n";
            return 0;
            
        }
        
    }
    return 0;
}

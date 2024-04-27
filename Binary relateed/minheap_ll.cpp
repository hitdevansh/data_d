#include <iostream>
using namespace std;
class queue;
class node;
class binarytree;
void swap(int &x, int &y)
{   cout<<"seap is called"<<endl;
    int temp = x;
    x = y;
    y = temp;
}
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
    node* left;
    node* right;
    node * parent;
};
class queue{
  public:
  nodequeue *front=nullptr;
  nodequeue *rear=nullptr;
void enque(node* val);
void deque();
int empty();
};
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
    {
        cout<<"queue is empty ";
        return;
    }
    nodequeue* temp=front;
    front=front->next;
    if(front==nullptr)
   { rear=nullptr;}
    
    delete(temp);
}

int queue:: empty()
{
    if(front==nullptr)
    return 1;
    return 0;
}
class binarytree
{
   public:
   node* root;
   node* creatnode(int val);
   void preorder(node* root);
   void postorder(node* root);
   void inorder(node* root);
   node* insertnode(int val);
   void print2D(node *root,int val);
   node* deletenode(int key);
   void levelordertraversal(node* t);
};

node* binarytree::creatnode(int val)
{
    node* n=new node();
    n->data=val;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void binarytree::preorder(node* root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void binarytree::postorder(node* root)
{
    if(root==NULL)
    return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void binarytree::inorder(node *root)
{
    if(root==NULL)
    return;
    
    inorder(root->left);
     cout<<root->data<<" ";
    inorder(root->right);
   
}

node* binarytree::insertnode(int val)
{
    if(root==NULL)
    {
        root=creatnode(val);
        return root;
    }
    queue q;
    q.enque(root);
    
    while(!q.empty())
    {  int c=0;
        node* t;
        t=q.front->data;
        q.deque();
        
        if(t->left!=NULL)
        {
            q.enque(t->left);
        }
        else
        {
            t->left= creatnode(val);
            t->left->parent=t;
            c++;
            goto jump;
        }
        
        
        if(t->right!=NULL)
        {
            q.enque(t->right);
        }
        else
        {
            t->right= creatnode(val);
            t->right->parent=t;
            goto jump;
             c++;
            // return root;
        }
        if(c==1){jump:
            while(t->parent->data>t->data && t!=NULL){
                swap(t->parent->data,t->data);
                t=t->parent;
            }
        retz
        }
    }
}

node* binarytree::deletenode(int key)
{
    if(root==NULL)
    return NULL;
    if(root->left==NULL && root->right==NULL)
    {
        if(root->data==key){
        root=NULL;
        return NULL;
        }
        else
        return root;
    }
    
    node* keynode=NULL;
    node* temp;
    node* last;
    queue q;
    q.enque(root);
    while(!q.empty())
    {
        temp=q.front->data;
        q.deque();
        if(temp->data==key)
        {
            keynode=temp;
        }
        if(temp->left)
        {
            last=temp;
            q.enque(temp->left);
        }
        if(temp->right)
        {
            last=temp;
            q.enque(temp->right);
        }
    }
    if(keynode!=NULL){
        keynode->data=temp->data;
        if(last->right==temp)
        {
            last->right=NULL;
        }
        else
        last->left=NULL;
        delete(temp);
    }
    else{
        cout<<"key is not found "<<endl;
    }
    return root;
}

void binarytree:: levelordertraversal(node* t)
{
    if(root==NULL)
    return;
    queue q;
    q.enque(root);
    
    while(!q.empty())
    {
        node *n=q.front->data;
        cout<<n->data<<" ";
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
void binarytree::print2D(node *r, int space)
{
    if (r == NULL) // Base case  1
        return;
    space =space + 10;            // Increase distance between levels   2
    print2D(r->right, space); // Process right child first 3
    cout << endl;
    for (int i = 10; i < space; i++) // 5
        cout << " ";                    // 5.1
    cout << r->data << "\n";            // 6
    print2D(r->left, space);          // Process left child  7
}
int main()
{
   binarytree b;
   b.root=NULL;
   int ch;
  
   while(1){
      
  cout<<endl;
   cout<<"Enter your choice "<<endl;
   cout<<"Enter 1 for insertion in the tree "<<endl;
   cout<<"Enter 2 for deletion in the tree "<<endl;
   cout<<"Enter 3 for show the inorder traversal in the tree "<<endl;
 cout<<"Enter 4 for show the postorder traversal in the tree "<<endl;
  cout<<"Enter 5 for show the prerder traversal in the tree "<<endl;
   cout<<"Enter 6 for show the level order traversal in the tree "<<endl;
   cout<<"Enter 7 for exit "<<endl;
   cin>>ch;
   if(ch==1)
   {
       cout<<"Enter the data you want to insert in the tree "<<endl;
        int data;
       cin>>data;
       b.insertnode(data);
       cout<<"After insertion the tree is like this "<<endl;
       b.inorder(b.root);
   }
   
    if(ch==2)
   {
       cout<<"Enter the data you want to delete from the tree "<<endl;
        int data;
       cin>>data;
       b.deletenode(data);
       cout<<"After deletion the data "<<data<<" The tree is like this "<<endl;
       b.inorder(b.root);
   }
  
  if(ch==3)
  {
      cout<<" The inorder traversal is "<<endl;
      b.inorder(b.root);
  }
  
   if(ch==4)
  {
      cout<<" The preorder traversal is "<<endl;
      b.preorder(b.root);
  }
  
   if(ch==5)
  {
      cout<<" The postorder traversal is "<<endl;
      b.postorder(b.root);
  }
  
  if(ch==6)
  {
      cout<<" The levelorder traversal is "<<endl;
      b.levelordertraversal(b.root);
  }
  if(ch==8){b.print2D(b.root,10);}
  if(ch==7)
  break;
   }
    return 0;
}

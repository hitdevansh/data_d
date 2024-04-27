#include<iostream>
using namespace std;
void swap(int &x, int &y)
{   cout<<"seap is called"<<endl;
    int temp = x;
    x = y;
    y = temp;
}
class heap;
class node
{
    public:
    int data;
    node * left;
    node *right;
    node *parent;
};
class nodequeue
{
    public:
    node *data;
    nodequeue *next;
    nodequeue *prev;
    nodequeue(){};
    nodequeue(node *p)
    {
        data=p;
        next=NULL;
    }
};
class queue
{
public:
nodequeue *front=nullptr;
nodequeue *rear=nullptr;

void enque(node* val);
void deque();
int empty();
node *Rear();
};
queue p;
void queue:: enque(node* val)
{
    nodequeue* n=new nodequeue(val);
    if(front==nullptr)
    {
        front=rear=n;
        n->prev=nullptr;
        return;
    }
    n->prev=rear;
    rear->next=n;
    rear=n;
}
node * queue:: Rear()
{
    nodequeue* n=new nodequeue;
    if(rear->data!=nullptr &&  rear->data->right==nullptr && rear->data->left==nullptr)
    {   n=rear;
        rear=rear->prev;
        return n->data;
    }
    return n->data;
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
};
class heap
{
   public:
   node* root;
   node* creatnode(int val);
   void preorder(node* root);
   node * inhelper(node *r);
   //void postorder(node* root);
   //void inorder(node* root);
   node* insertnode(int val);
   void print2D(node *root,int val);
   //node* deletenode(int key);
   //void levelordertraversal(node* t);
};
node* heap::creatnode(int val)
{
    node* n=new node();
    n->data=val;
    n->left=NULL;
    n->right=NULL;
    n->parent=NULL;
    return n;
}

node *heap ::inhelper(node *r)
{
    while(r->parent->data>r->data && r->parent)
    {
        swap(r->parent->data,r->data);

    }
}
// void * upheap(node *temp)
// {
//     //void upHeapify(HeapNode* temp)
//     {
//         if(temp->parent == NULL)
//         {
//             return NULL;
//         }
//         if(temp->parent->data < temp->data)
//         {
//             swap(temp->parent->data,temp->data);
//             upheap(temp->parent);
//         }
//     }
//     return temp;
// }
node * temp=nullptr;
temp=b.root;
node* heap ::insertnode(int val)
{   cout<<" hh "<<endl;
    if(root==NULL)
    {   cout<<" hi "<<endl;
        root->parent=nullptr;
        root=creatnode(val);
        return root;
    }
    queue q;
    q.enque(root);
    p.enque(root);
    while(!q.empty())
    {
        node* t;
        t=q.front->data;
        q.deque();
        
        if(t->left!=NULL)
        {
            q.enque(t->left);
        }
        else
        {   cout<<"a called"<<endl;
            t->left= creatnode(val);
            t->left->parent=temp;
            p.enque(t->left);
            
         return root;
        }
        
        
        if(t->right!=NULL)
        {
            q.enque(t->right);
        }
        else
        {   //node *c=NULL;
            //node *p=NULL;
            t->right= creatnode(val);
            p.enque(t->right);
            t->left->parent=temp;
            //upheap(t->right);
        //     pump:
        // if(t->right->parent->data < t->right->data )
        // {
        //     swap(t->right->parent->data,t->right->data);
        //     t=t->parent;
        //     goto pump;
        // }
        return root;
        }
    }
    
}
void heap::print2D(node *r, int space)
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
   heap b;
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
       b.root=b.insertnode(data);
    //    if(b.root && b.root->right && b.root->left)
    //    {cout<<b.root->right->parent->data<<endl;}
        // while (p.front->next!=nullptr)
        // {   nodequeue * temp=p.front;
        //     /* code */cout<<temp->data<<endl;
            
        // }
        
       cout<<"After insertion the tree is like this "<<endl;
       //b.inorder(b.root);
   }
   
//     if(ch==2)
//    {
//        cout<<"Enter the data you want to delete from the tree "<<endl;
//         int data;
//        cin>>data;
//        b.deletenode(data);
//        cout<<"After deletion the data "<<data<<" The tree is like this "<<endl;
//        b.inorder(b.root);
//    }
  
//   if(ch==3)
//   {
//       cout<<" The inorder traversal is "<<endl;
//       b.inorder(b.root);
//   }
  
//    if(ch==4)
//   {
//       cout<<" The preorder traversal is "<<endl;
//       b.preorder(b.root);
//   }
  
//    if(ch==5)
//   {
//       cout<<" The postorder traversal is "<<endl;
//       b.postorder(b.root);
//   }
  
//   if(ch==6)
//   {
//       cout<<" The levelorder traversal is "<<endl;
//       b.levelordertraversal(b.root);
//   }
  if(ch==8){b.print2D(b.root,10);}
  if(ch==7)
  break;
   }
return 0;
}
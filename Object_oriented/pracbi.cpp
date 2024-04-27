#include<iostream>
using namespace std;
class queue;
class node;
class queeuenode;
class binarytree;
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
class binarytree{
    public:
    node * root=0;
    node * createnode(int val)
    {
        node  *n=new node ;
        n->data=val;
        n->left=nullptr;
        n->right=nullptr;
    }
    node * lastpar(node *root)
    {
        if(root==nullptr){return root;}
        queue q;
        //node * last=nullptr;
        q.enque(root);
        while(!q.empty())
        {
            node * temp=q.front->data;
            q.deque();
            if(temp->right && temp->left)
            {
                q.enque(temp->left);
                q.enque(temp->right);
            }
            else
            {
                return temp;
            }
        }
    }
    
        node * last=nullptr;
        node * keynode=nullptr;
        node * temp=nullptr;
        node * lp=nullptr;
    void lastnode(node *root,int key)
    {
        // if(root==nullptr){return ;}
        queue q;
        q.enque(root);
        while(!q.empty())
        {
             temp=q.front->data;
            q.deque();
            if(temp->data==key){
                cout<<"found"<<endl;
                keynode=temp;}
            if(temp->left)
            {   last=temp->left;
                q.enque(temp->left);
            }
            if(temp->right)
            {   last=temp->right;
                q.enque(temp->right);
            }
        }
        lp=temp;
        
    }
    node * insert(int val)
    {
        if(root==nullptr){
            root=createnode(val);
            return root;
        }
        node * par=lastpar(root);
        if(par->left==nullptr)
        {
            par->left=createnode(val);
        }
        else
        {
            par->right=createnode(val);
        }
        return par;
    }
    node * Delete(int val)
    {
       if(root==NULL)
    return NULL;
    if(root->left==NULL && root->right==NULL)
    {
        if(root->data==val){
        root=NULL;
        return NULL;
        }
        else
        return root;
    }   lastnode(root,val);
        if(keynode!=nullptr)
        {   cout<<"Deleted succed"<<endl;
            keynode->data=last->data;
            //node * lk=lp;
            if(last->left==temp)
            {   
                last->left=nullptr;
            
            }
            else
            {   
                last->right=nullptr;
            }
            delete(temp);
        }
        else{
            cout<<"key not found"<<endl;
            return nullptr;} 
        return root;

    }
    void print2D(node *r, int space)
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
};
int main(){

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
       b.insert(data);
       //cout<<"After insertion the tree is like this "<<endl;
      // b.inorder(b.root);
   }
   
    if(ch==2)
   {
       cout<<"Enter the data you want to delete from the tree "<<endl;
        int data;
       cin>>data;
      b.root= b.Delete(data);
       cout<<"After deletion the data "<<data<<" The tree is like this "<<endl;
    //
      // b.inorder(b.root);
   }
  
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

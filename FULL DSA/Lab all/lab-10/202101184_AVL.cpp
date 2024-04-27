#include<iostream>
using namespace std;
class Node{
    public:
    Node *left;
    Node *right;
    int value;
    int height;
    Node() {
    value = 0;
    left = NULL;
    right = NULL;
  }
  Node(int v) {
    value = v;
    left = NULL;
    right = NULL;
  }
};
class AVL{
   public:
    Node *root;
   AVL(){
   root=NULL;

   }
    bool isTreeEmpty() {
    if (root == NULL) {
      return true;
    } else {
      return false;
    }
  }
   int height(Node *r)
   {
    int x,y;
    if(r==NULL){return 0;}
    x=height(r->left);
    y=height(r->right);
    return x>y ? x+1:y+1;
   }
    void print2D(Node * r, int space) {
    if (r == NULL) 
      return;
    space += 10;
    print2D(r -> right, space);  
    cout << endl;
    for (int i = 10; i < space; i++) 
      cout << " "; 
    cout << r -> value << "\n";
    print2D(r -> left, space);   }
   int balancefactor(Node *r)
{    int x,y;
    if(r==NULL){return 0;}
    x=height(r->left);
    y=height(r->right);
    return x-y;
   }
       Node *llrotation(Node *r)
    {
       Node *pl=r->left;
       Node *pll=pl->right;
       pl->right=r;
       r->left=pll;
       r->height=height(r);
       pl->height=height(pl);;
    //    pll->height=height(pll);
       if(root==r)
       {
        root=pl;
       }
        return pl;
    }
    Node* rlrotation(Node *p) {
    Node* pr = p->right;
    Node* prl = pr->left;
 
    pr->left = prl->right;
    p->right = prl->left;
 
    prl->right = pr;
    prl->left = p;
 
    // Update height
    pr->height = height(pr);
    p->height = height(p);
    prl->height = height(prl);
 
    // Update root
    if (root == p){
        root = prl;
    }
    return prl;
}
Node *minvalue(Node *r)
{ cout<<"min value is called !"<<endl;
  Node *temp;
  temp=r;
  while(temp->left!=NULL)
  {
    temp=temp->left;
  }
  return temp;
}
      Node *lrrotation(Node *r)
    {
       Node *pl=r->left;
       Node *pll=pl->right;
       pl->right=r;
       r->left=pll;
       r->height=height(r);
       pl->height=height(pl);;
    //    pll->height=height(pll);
       if(root==r)
       {
        root=pl;
       }
        return pl;
    }
      Node *rrrotation(Node *r)
    {
       Node *pl=r->right;
       Node *pll=pl->right;
       r->right=pl->left;
       pl->left=r;
       r->height=height(r);
       pl->height=height(pl);;
    //    pll->height=height(pll);
       if(root==r)
       {
        root=pl;
       }
        return pl;
    }
   Node *insert(Node *r,Node *new_node){ 
    if(r==NULL)
    {   cout<<"INSEERT"<<endl;
        r=new_node;
        cout<<"Insert succecfully!"<<endl;
        r->height=1;
        return r;
    }
    else if(new_node->value<r->value){
        r->left=insert(r->left,new_node);
    }
    
    else if(new_node->value>root->value){
        r->right=insert(r->right,new_node);
    }
    else{
        
        cout<<"No duplicates are allowed"<<endl;
        return r;
    }

     root->height=height(r);
    if(balancefactor(r)==2 && balancefactor(r->left)==1)
    {
        cout<<"So here we need a left rotation "<<endl;
        return llrotation(r);
    }
    else if(balancefactor(r)==2 && balancefactor(r->left)==-1)
     {
        cout<<"So here we need a left and then right rotation "<<endl;
        return lrrotation(r);
    }
    else if(balancefactor(r)==-2 && balancefactor(r->right)==-1)
    {
        cout<<"So here we need a right rotation "<<endl;
        return rrrotation(r);
    }
    else if(balancefactor(r)==-2 && balancefactor(r->right)==1)
    {
        cout<<"So here we need a right and then left rotation "<<endl;
        return rlrotation(r);
    }
   return r;
   }
  Node * deleteNode(Node * r, int v) {
    if (r == NULL) {
      cout<<"So data is deleteed"<<endl;
      return NULL;
      
    }
    else if (v < r -> value) {
      r -> left = deleteNode(r -> left, v);
    } 
    else if (v > r -> value) {
      r -> right = deleteNode(r -> right, v);
    }
    // if key is same as root's key, then This is the node to be deleted 
    else {
      // node with only one child or no child 
      if (r -> left == NULL) {
        Node * temp = r -> right;
        delete r;
        return temp;
      } else if (r -> right == NULL) {
        Node * temp = r -> left;
        delete r;
        return temp;
      } else {
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        Node * temp1 = minvalue(r -> right);
        cout<<" Copy the inorder successor's content to this node"<<endl; 
        r -> value = temp1 -> value;
        // Delete the inorder successor 
        r -> right = deleteNode(r -> right, temp1 -> value);
      }
    }
    r->height=height(r);
    if(balancefactor(r)==2 && balancefactor(r->left)==1)
    {
        cout<<"So here we need a left rotation "<<endl;
        return llrotation(r);
    }
    
    if(balancefactor(r)==2 && balancefactor(r->left)==0)
    {
        cout<<"So here we need a left rotation "<<endl;
        return llrotation(r);
    }
    else if(balancefactor(r)==2 && balancefactor(r->left)==-1)
     {
        cout<<"So here we need a left and then right rotation "<<endl;
        return lrrotation(r);
    }
    else if(balancefactor(r)==-2 && balancefactor(r->right)==-1)
    {
        cout<<"So here we need a right rotation "<<endl;
        return rrrotation(r);
    }
    
    else if(balancefactor(r)==-2 && balancefactor(r->right)==0)
    {
        cout<<"So here we need a right rotation "<<endl;
        return rrrotation(r);
    }
    else if(balancefactor(r)==-2 && balancefactor(r->right)==1)
    {
        cout<<"So here we need a right and then left rotation "<<endl;
        return rlrotation(r);
    }
      return r;
    }
};
int main()
{AVL b1;
int p,val;
cout<<"what the fuck"<<endl;
do
{
    cout<<"press 1 for insertion in AVL tree, 3 delete "<<endl<<"press 2 for print"<<endl<<"press 0 for exit"<<endl;
    cin>>p;
    Node *new_node=new Node();
    if(p==1)
    {cout<<"Enter a value to insert "<<endl;
    cin>> val;
    new_node->value=val;
    b1.root=b1.insert(b1.root,new_node);
    }
    else if(p==2)
    {
        b1.print2D(b1.root,5);
    }
    else if(p==3)
    { cout<<"Enter a daa to remove "<<endl;
      cin>>val;
      b1.root=b1.deleteNode(b1.root,val);
    }
}while(p!=0);
return 0;
}
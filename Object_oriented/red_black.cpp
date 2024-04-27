#include <iostream>
using namespace std;
class tree;
class queue
{
    public:
    int fronts;
    int rear;
    tree* arr[100000];
    queue()
    {
      fronts=rear=-1;
    }
    void push(tree* data)
    {
      if(fronts==-1) fronts++;
      rear++;
      arr[rear]=data;
    }
    tree* front()
    {
        return arr[fronts];
    }
    void pop()
    {
        if(fronts!=-1)
        arr[fronts]=0;
        if(fronts==rear) fronts=rear=-1;
        else
        {
        fronts++;
        }
    }
    void pop_rear()
    {
        if(rear==fronts && rear==-1)
        fronts=rear=-1;
        else
        rear--;
    }
    tree * rears()
    {
       return arr[rear]; 
    }
    bool empty()
    {
        if(fronts==rear && rear==-1)
        return true;
        else return false;
    }
    
};

class tree
{
    public:
    int data;
    bool color;
    tree * left;
    tree * right;
    tree(int data)
    {
        this->data=data;
        color=0;
        left=right=0;
    }
};


void displayinorder(tree * head)
{
    {
        if((head)==0) return ;
        if(head->left) displayinorder(head->left);
        cout<<head->data<<" ";
        if(head->right) displayinorder(head->right);
    }
}
void displaypreoreder(tree * head)
{
         if((head)==0) return ;
         cout<<head->data<<" ";
         if(head->left) displaypreoreder(head->left);
         if(head->right) displaypreoreder(head->right);
}


void displaypostoreder(tree * head)
{
        if(head==0) return;
        if(head->left) displaypostoreder(head->left);
        if(head->right) displaypostoreder(head->right);  
        cout<<head->data<<" ";
}
void displaylevelorder(tree* root)
{
    if(root==NULL)
    return;
    queue q;
    q.push(root);
    while(!q.empty())
    {
        tree *n=q.front();
        cout<<n->data<<"---"<<n->color<<" ";
        q.pop();
        if(n->left)
        {
            q.push(n->left);
        }
         if(n->right)
        {
            q.push(n->right);
        }
        
    }
}

// void displaylevelorder(tree * root)
// {
//  int x=0;
//  if(root==0) return ;
//   queue st;
//   st.push(root);
//   st.push(0);
//   cout<<"level "<<x++<<" : ";
//   while(!st.empty())
//   {
//     tree *temp=st.front();
//     st.pop();
//     if(temp)
//     {
//     cout<<(temp->data);
//     if(temp->color==0)
//     cout<<"(0)";
//     else
//     cout<<"(1)";
//     cout<<" ";
//     if(temp->left) st.push(temp->left);
//     if(temp->right) st.push(temp->right);
//     }
//     else if(!st.empty())
//     {
//         cout<<"\nlevel "<<x++<<" : ";
//         st.push(0);
//     }
//  }
// }

void display(tree *head)
{
    cout<<"your tree data is : \n";
    
    cout<<"\ninorder sequence \n";
    if(head==0)   cout<<"(...empty...)"<<endl;
    else          displayinorder(head);
    
    cout<<"\npreorder sequence \n";
    if(head==0)   cout<<"(...empty...)"<<endl;
    else          displaypreoreder(head);
    
    cout<<"\npostorder sequence \n";
    if(head==0)   cout<<"(...empty...)"<<endl;
    else          displaypostoreder(head);
    
    cout<<"\nlevel-order sequence\n";
    if(head==0)   cout<<"(...empty...)"<<endl;
    else          displaylevelorder(head);
    
    cout<<endl;
}

void insert(tree ** root,int &data)
{
   if(*root==0)
   {
   *root=new tree(data);
   return ;
   }
   if(root->data<data) insert(&root->right,data);
   else                   insert(&root->left,data);
   
}
tree * mainroot;
void makeredblack(tree ** root,int & data)
{
    if(root==0) return;
    if(*root && (root->data==data)&&root==mainroot)
        {
            mainroot->color=1;
            return;
        }
    else if(((root->left && root->left->data==data) || (root->right && root->right->data==data)) && root==mainroot)
    return;
    tree * temp=root;
     makeredblack(&root->left ,data);
     root=temp;
     makeredblack(&root->right,data);
     root=temp;
    if(root && root->left && root->left->left && root->left->left->data==data)
    {
        if(root->left->color==1) return;
        else if(root->right && root->right->color==0)
        {
            root->left->color=root->right->color=1;
            if(root!=mainroot)root->color=0;
            data=root->data;
        }
        else
        {
            tree * temp=root->left->right;
            root->left->right=root;
            root=root->left;
            root->right->left=temp;
            root->color=1;
            root->right->color=0;
            return;
        }
    }
    else if(root && root->left && root->left->right && root->left->right->data==data)
    {
        if(root->left->color==1) return;
        else if(root->right && root->right->color==0)
        {
            root->left->color=root->right->color=1;
            if(root!=mainroot)root->color=0;
            data=root->data;
        }
        else
        {
            tree * temp=root->left->right;
            temp->left=root->left;
            temp->right=root;
            root->left->right=0;
            root->left=0;
            root=temp;
            root->color=1;
            root->right->color=0;
            return;
        }
    }
    else if(root && root->right && root->right->left && root->right->left->data==data)
    {
        if(root->right->color==1) return;
        else if(root->left && root->left->color==0)
        {
            root->left->color=root->right->color=1;
            if(root!=mainroot)root->color=0;
            data=root->data;
        }
        else
        {
            tree * temp=root->right->left;
            temp->left=root;
            temp->right=root->right;
            root->right->left=0;
            root->right=0;
            root=temp;
            root->color=1;
            root->left->color=0;
            return;
        }
    }
    else if(root && root->right && root->right->right && root->right->right->data==data)
    {
        if(root->right->color==1) return;
        else if(root->left && root->left->color==0)
        {
            root->left->color=root->right->color=1;
            if(root!=mainroot)root->color=0;
            data=root->data;
        }
        else
        {
            tree * temp=root->right->left;
            root->right->left=root;
            root=root->right;
            root->left->right=temp;
            root->color=1;
            root->left->color=0;
            return;
        }
    }
}

int main()
{
    tree* root=0;
    while(1)
    {
        cout<<"for insert enter  : i \n";
        cout<<"for deleter enter : d \n";
        cout<<"for quit enter    : q \n";
        char c;
        cin>>c;
        if(c=='q') return 0;
        switch(c)
        {
            case 'i':
            cout<<"enter a data you want to insert :  ";
            int data;
            cin>>data;
            insert(&root,data);
            mainroot=root;
            makeredblack(&root,data);
            display(root);
            break;
            
            case 'd':
            // mainroot=root;
            // cout<<"enter a data you want to delete :   ";
            // int value;
            // cin>>value;
            // root=delet(root,value);
            // display(root);
            break;
            
            default:
            cout<<"unvalied choice please enter valid choice : \n";
            
        }
        
    }
    return 0;
}
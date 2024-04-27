#include <iostream>
using namespace std;
class tree
{
    public:
    int data;
    tree * left;
    tree * right;
    tree(int data)
    {
        this->data=data;
        left=0;
        right=0;
    }
   
};
tree *root;
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
      if(fronts==-1) 
      {fronts++;}
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
    bool empty()
    {
        if(fronts==rear && rear==-1)
        return true;
        else return false;
    }
    
};

int w=0;
void insert(tree ** root,int data)
{
       if(*root==0)
       {*root=new tree(data);
       return;
       }
       queue  st;
       st.push(root);
       st.push(0);
       while(!st.empty())
       {
        tree *temp=(tree*)st.front();
        st.pop();
        if(temp)
        {
        if(temp->left) st.push(temp->left);
        else
        {cout<<"THIS is inserted at left!"<<endl;
         temp->left=new tree(data);  
         return ;
        }
        if(temp->right) st.push(temp->right);
        else
        {   cout<<"THIS is inserted at right !"<<endl;
            temp->right=new tree(data);
            return ;
        }
        }
        else if(!st.empty())
        {
            st.push(0);
        }
 }
}
void displayinorder(tree * head)
{
    {
        if((head)==0) {return ;}
        displayinorder(head->left);
        cout<<head->data<<" ";
        displayinorder(head->right);
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
// void height(tree *head)
// {
//     int x,t;
//     if(head=NULL)
//     {return 0;}
//     else
//     {x = height(head->left);
//     y = height(head->right);
//     return x > y ? x+1 : y+1 ;
//     }
// }
// void printgiven(tree *head,int level)
// {
//     if(head==nullptr){return ;}
//     else if(level==0){cout<<head->data<<" "<<<<endl;}
//     else {printgiven(head->left,level-1);
//     printgiven(head->right,level-1);}
// }
// void displaylevelorder(tree * head)
// {
//     for(int i=0;i<=height(root);i++)
//     {
//         printgiven(head,i);
//     }
// }




void display(tree *head)
{   cout<<"Enter which order you want to print?"<<endl<<"1 for inorder,2 for preorder and 3 for postorder and 4 for level order travrsal"<<endl;
    int o;
    cin>>o;

    cout<<"your tree data is : \n";
    if(o==1){
    cout<<"\ninorder sequence \n";
    if(head==0)   cout<<"(...empty...)"<<endl;
    else          displayinorder(head);}
    else if(o==2){
    cout<<"\npreorder sequence \n";
    if(head==0)   cout<<"(...empty...)"<<endl;
    else          displaypreoreder(head);}
    
    else if (o==3){cout<<"\npostorder sequence \n";
    if(head==0)   cout<<"(...empty...)"<<endl;
    else          displaypostoreder(head);
    }
    else if(o==4){cout<<"\nlevel-order sequence\n";
    if(head==0)   cout<<"(...empty...)"<<endl;
    else          //displaylevelorder(head);
    }
    cout<<endl;
}

void search(tree ** root,int key)
{
     if(*root==0) return ;
     if(root->data==key) mcheck=1,repls=root;
     if((root->left)==0 && root->right==0)
     {
        if(check==0)
        {
        check=1;
        curr=*root;
        }
     }
     if(check==0)
     {
     prevs=root;
     }
     if(root->right) search(&root->right,key);
     if(root->left) search(&root->left,key);
 }
int successor(tree *root)
    {
        root = root->right;
        while (root->left != NULL)
        {
            root = root->left;
        }
        return root->data;
    }

    int predecessor(tree *root)
    {
        root = root->left;
        while (root->right != NULL)
        {
            root = root->right;
        }
        return root->data;
    }

tree *delete(tree **root, int key)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (key > root->data)
        {
            root->right = delete(root->right, key);
        }

        else if (key < root->data)
        {
            root->left = delete(root->left, key);
        }

        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                root = NULL;
            }

            else if (root->right != NULL)
            {
                root->data = successor(root);
                root->right = delete(root->right, root->data);
            }

            else
            {
                root->data = predecessor(root);
                root->left = delete(root->left, root->data);
            }
        }

        return root;
    }
void delet(tree ** root,int key)
{
    mcheck=0;
    prevs=0;
    curr=0;
    repls=0;
    check=0;
    if(root==0)
    {
        cout<<"tree is empty so nothing will be deleted \n";
        return;
    }
    else if(root->data==key && root->left==0 && root->right==0)
    {
        tree * temp=*root;
        *root=0;
        delete(temp);
        return;
    }
    else
    {
        search(root,key);
        if(mcheck==0)
        {
            cout<<"element is not resent in tree : \n";
            return ;
        }
        else
        {
        tree * temp=curr;
        repls->data=temp->data;
        if(prevs->left==temp)
        {
            prevs->left=0;
        }
        else
        {
            prevs->right=0;
        }
        delete(temp);
        }
    }
}
int main()
{
    tree * root=0;

    while(1)
    {
        cout<<"for insert enter : i \n";
        cout<<"for delete enter : d \n";
        cout<<"for quit enter   : q \n";
        char c;
        cin>>c;
        if(c=='q') return 0;
        switch(c)
        {
            case 'i':
                cout<<"enter data you want insert\n";
                int data;
                cin>>data;
                insert(&root,data);
                display(root);
                break;
            case 'd':
                int key;
                cout<<"enter element you want to delete :\n";
                cin>>key;
                delet(&root,key);
                display(root);
                break;
                
            default:
            cout<<"unvalied choice please enter valied choice : \n";
            
        }
    }
    return 0;
}
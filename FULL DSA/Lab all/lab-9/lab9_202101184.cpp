#include <iostream>
#define SPACE 10
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
tree *root=NULL;
class TreeNode {
  public:
    int val;
  TreeNode * left;
  TreeNode * right;
  TreeNode() {
    val = 0;
    left = NULL;
    right = NULL;
  }
  TreeNode(int v) {
    val = v;
    left = NULL;
    right = NULL;
  }
};
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
    tree* rears()
    {
	return arr[rear];
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
	if(fronts==rear && rear==1)
	fronts=rear=-1;
	else rear--;
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
        tree * temp=(tree*)st.front();
        st.pop();
        if(temp)
        {
        if(temp->left) st.push(temp->left);
        else
        {
         temp->left=new tree(data);  
         return ;
        }
        if(temp->right) st.push(temp->right);
        else
        {
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
bool treecheck(tree *root, tree *min, tree *max)
{
    if (root == NULL)
    {
        return true;
    }

    if (min != NULL && root->data <= min->data)
        return false;

    if (max != NULL && root->data > max->data)
        return false;

    bool leftcheck = treecheck(root->left, min, root);
    bool rightcheck = treecheck(root->right, root, max);

    return leftcheck and rightcheck;
}
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

void displaylevelorder(tree * root)
{
 if(root==0) return ;
  queue st;
  st.push(root);
  st.push(0);
  while(!st.empty())
  {
    tree *temp=st.front();
    st.pop();
    if(temp)
    {
    cout<<(temp->data)<<" ";
    if(temp->left) st.push(temp->left);
    if(temp->right) st.push(temp->right);
    }
    else if(!st.empty())
    {
        st.push(0);
    }
 }
}
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
tree* prevs;
tree* repls;
tree* curr;
int check;
int mcheck;
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

void Delet(tree** root,int key)
{
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
              queue st;
              queue bt;
              st.pushroot;
              bt.pushroot;
              st.push(0);
              bt.push(0);
              while(!st.empty())
              {
                tree *temp=st.front();
                st.pop();
                if(temp)
                {
                if(temp->left) st.push(temp->left),bt.push(temp->left);
                if(temp->right) st.push(temp->right),bt.push(temp->right);
                }
                else if(!st.empty())
                {
                    st.push(0);
                    bt.push(0);
                }
                }
                bt.pop_rear();
                tree * temp= bt.rears();
                repls->data=temp->data;
        
                while(!bt.empty() && bt.rears()!=0)
                {
                    bt.pop_rear();
                }
                bt.pop_rear();
                while(1)
                {
                    tree * temp2=bt.rears();
                    if(temp2->right==temp)
                    {
                        temp2->right=0;
                        delete(temp);
                        break;
                    }
                    if(temp2->left==temp)
                    {
                        temp2->left=0;
                        delete(temp);
                        break;
                    }
                    bt.pop_rear();
                }
            }
        }
                
}
class BST
{ public:
  TreeNode *root2=NULL;
  bool isEmpty();
  void insertnode(TreeNode *new_node)
  {
  if(root2==NULL)
  {  root2 = new_node;
    cout << "Value Inserted as root node!" << endl;}
  else 
  {     TreeNode * temp = root2; 
        while (temp != NULL) {
         if ((new_node -> val <= temp -> val) && (temp -> left == NULL)) {
          temp -> left = new_node;
          cout << "val Inserted to the left!" << endl;
          break;
        } else if (new_node -> val < temp -> val) {
          temp = temp -> left;
        } else if ((new_node -> val > temp -> val) && (temp -> right == NULL)) {
          temp -> right = new_node;
          cout << "val Inserted to the right!" << endl;
          break;
        } else {
          temp = temp -> right;
        }
      }
    }
  }
   void print2D(TreeNode * r, int space) {
    if (r == NULL) 
      return;
    space += SPACE; 
    print2D(r -> right, space); 
    cout << endl;
    for (int i = SPACE; i < space; i++)  
      cout << " ";   
    cout << r -> val << "\n";
    print2D(r -> left, space); 
  }
   TreeNode * recursiveSearch(TreeNode * r, int val) {
    if (r == NULL || r -> val == val)
      return r;

    else if (val < r -> val)
      return recursiveSearch(r -> left, val);

    else
      return recursiveSearch(r -> right, val);
  }

  TreeNode * minvalNode(TreeNode * node) {
    TreeNode * current = node;
    /* loop down to find the leftmost leaf */
    while (current -> left != NULL) {
      current = current -> left;
    }
    return current;
  }

  TreeNode * maxvalNode(TreeNode * node) {
    TreeNode * current = node;
    /* loop down to find the leftmost leaf */
    while (current -> right != NULL) {
      current = current -> right;
    }
    return current;
  }
TreeNode * deleteNode(TreeNode * r, int v) {
    // base case 
    if (r == NULL) {
      return NULL;
    }
    else if (v < r -> val) {
      r -> left = deleteNode(r -> left, v);
    }
    else if (v > r -> val) {
      r -> right = deleteNode(r -> right, v);
    }
    // if key is same as root's key, then This is the node to be deleted 
    else {
      // node with only one child or no child 
      if (r -> left == NULL) {
        TreeNode * temp = r -> right;
        delete r;
        return temp;
      } else if (r -> right == NULL) {
        TreeNode * temp = r -> left;
        delete r;
        return temp;
      } else {
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        TreeNode * temp = minvalNode(r -> right);
        // Copy the inorder successor's content to this node 
        r -> val = temp -> val;
        r->right=deleteNode(r->right, r->val); 
      }
    }
    return r;
  }
int height(TreeNode * r) {
    if (r == NULL)
      return -1;
    else {
      /* compute the height of each subtree */
      int lheight = height(r -> left);
      int rheight = height(r -> right);

      /* use the larger one */
      if (lheight > rheight)
        return (lheight + 1);
      else return (rheight + 1);
    }
  }

  /* Print nodes at a given level */
  void printGivenLevel(TreeNode * r, int level) {
    if (r == NULL)
      return;
    else if (level == 0)
      cout << r -> val << " ";
    else // level > 0  
    {
      printGivenLevel(r -> left, level - 1);
      printGivenLevel(r -> right, level - 1);
    }
  }
  void printLevelOrderBFS(TreeNode * r) {
    int h = height(r);
    for (int i = 0; i <= h; i++)
      printGivenLevel(r, i);
  }

  void printInorder(TreeNode* p){
  if (p){
  printInorder(p->left);
  cout << p->val<< ", " << flush;
  printInorder(p->right);
    }
}
  void printPostorder(TreeNode* p){
  if (p){
  printPostorder(p->left);
  printPostorder(p->right);
  cout << p->val << ", " << flush;
    }}
  void printPreorder(TreeNode* p){
  if (p){
  cout << p->val << ", " << flush;
  printPreorder(p->left);
  printPreorder(p->right);
    }} 

  TreeNode * iterativeSearch(int v) {
    if (root2 == NULL) {
      return root2;
    } else {
      TreeNode * temp = root2;
      while (temp != NULL) {
        if (v == temp -> val) {
          return temp;
        } else if (v < temp -> val) {
          temp = temp -> left;
        } else {
          temp = temp -> right;
        }
      }
      return NULL;
    }
  }

};
int main() {
int p;
do{
pump:
cout<<"Enter 1 to do things with simple binary tree and Enter 2 to do things with binary search tree and Enter 0 for exit from this programme "<<endl;

cin>>p;
BST obj;
if(p==1){ cout<<"You are in binary tree "<<endl;
while(1){    cout<<endl<<"Enter 1 to create tree"<<endl<<"2 for display"<<endl<<"press 5 for deleting"<<endl<<"press 0 for exit "<<endl;
    int p;
    cin>>p;
    if(p==1)
    {   int data;;
        cout<<"Enter a data to add in binary tree"<<endl;
        cin>>data;
        insert(&root,data);
    }
    else if(p==2){
        
        display(root);
    }
    else if(p==5)
    {
    cout<<"Enter a data to delete form a tree "<<endl;
    int data;
    cin>>data;
    Delet(&root,data);
    }
    else if(p==0)
    {
        goto pump;
    }}}
else if(p==2)
{ BST obj;
  int option, val;

  do {
    cout << "What operation do you want to perform? " <<
      " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Search Node" << endl;
    cout << "3. Delete Node" << endl;
    cout << "4. Print/Traversal BST vals" << endl;
    cout << "5. Height of Tree" << endl;
    cout << "0. Exit Program" << endl;

    cin >> option;
    //Node n1;
    TreeNode * new_node = new TreeNode();

    switch (option) {
    case 0:
      break;
    case 1:
      	cout <<"INSERT"<<endl;
	      cout <<"Enter val of TREE NODE to INSERT in BST: ";
	      cin >> val;
	      new_node->val = val;
	      //obj.root= obj.insertRecursive(obj.root,new_node);
	      obj.insertnode(new_node);
	      cout<<endl;
    		break;
      
    case 2:
      cout << "SEARCH" << endl;
      cout << "Enter value of TREE NODE to SEARCH in BST: ";
      cin >> val;
      new_node = obj.iterativeSearch(val);
      //new_node = obj.recursiveSearch(obj.root, val);
      if (new_node != NULL) {
        cout << "value found" << endl;
      } else {
        cout << "value NOT found" << endl;
      }
      break;
    case 3:
      cout << "DELETE" << endl;
      cout << "Enter val of TREE NODE to DELETE in BST: ";
      cin >> val;
      obj.root2=obj.deleteNode(obj.root2, val);
      //new_node = obj.iterativeSearch(val);
      // if (new_node != NULL) {
      //   obj.deleteNode(obj.root2, val);
      //   cout << "value Deleted" << endl;
      // } else {
      //   cout << "value NOT found" << endl;
      // }
      break;
    case 4:
      cout << "PRINT 2D: " << endl;
      obj.print2D(obj.root2, 5);
      cout << endl;
      cout << "Print Level Order BFS: \n";
      obj.printLevelOrderBFS(obj.root2);
      cout << endl;
          cout <<"PRE-ORDER: ";
      	      obj.printPreorder(obj.root2);
      	      cout<<endl;
      	      cout <<"IN-ORDER: ";
      	      obj.printInorder(obj.root2);
      	      cout<<endl;
      	      cout <<"POST-ORDER: ";
	      obj.printPostorder(obj.root2);
      break;
    case 5:
      cout << "TREE HEIGHT" << endl;
      cout << "Height : " << obj.height(obj.root2) << endl;
      break;
    case 6:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

}
else if(p==0)
{
    return 0;
}
else
{cout<<"Please choose valid option to do things with simple binary tree or binary search tree "<<endl;
goto pump;} 
  }while(p!=0);
return 0;
}

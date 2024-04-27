#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *right;
    node *left;
    node()
    {
        data = 0;
        right = nullptr;
        left = nullptr;
    }
    node(int data)
    {
        data = data;
        right = nullptr;
        left = nullptr;
    }
};
class BST
{
public:
    node *root;
    BST() { root = nullptr; }
    int isTreeEmpty()
    {
        if (root == nullptr)
            return 1;
        return 0;
    }
    node *insertRecursive(node *root, int key)
    {
        if (root == nullptr)
        {
            node *new_node = new node;

            new_node->data=key;
            new_node->left = NULL;
            new_node->left = NULL;
            root=new_node;
            cout << "Insertion successful" << endl;
            return root;
        }
        if (key < root->data)
        {
            root->left = insertRecursive(root->left, key);
        }
        else if (key > root->data)
        {
            root->right = insertRecursive(root->right, key);
        }
        else
        {
            cout << "No duplicate datas allowed!" << endl;
            return root;
        }
    }
    void printPreorder(node *r) //(current node, Left, Right)
    {
        if (r == NULL)
            return;
        /* first print data of node */
        cout << r->data << " ";
        /* then recur on left sutree */
        printPreorder(r->left);
        /* now recur on right subtree */
        printPreorder(r->right);
    }

    void printInorder(node *r) //  (Left, current node, Right)
    {
        if (r == NULL)
            return;
        /* first recur on left child */
        printInorder(r->left);
        /* then print the data of node */
        cout << r->data << " ";
        /* now recur on right child */
        printInorder(r->right);
    }
    void printPostorder(node *r) //(Left, Right, Root)
    {
        if (r == NULL)
            return;
        // first recur on left subtree
        printPostorder(r->left);
        // then recur on right subtree
        printPostorder(r->right);
        // now deal with the node
        cout << r->data << " ";
    }
    int height(node *p)
    {
        int x;
        int y;
        if (p == nullptr)
        {
            return 0;
        }
        x = height(p->left);
        y = height(p->right);
        return x > y ? x + 1 : y + 1;
    }

    void printGivenLevel(node *r, int level)
    {
        if (r == NULL)
            return;
        else if (level == 0)
            cout << r->data << " ";
        else // level > 0
        {
            printGivenLevel(r->left, level - 1);
            printGivenLevel(r->right, level - 1);
        }
    }
    void printLevelOrderBFS(node *r)
    {
        int h = height(r);
        for (int i = 0; i <= h; i++)
        printGivenLevel(r, i);
    }

    node * mindataNode(node * noe) {
        cout<<noe->data;
        cout<<"min called"<<endl;
    node * current = noe;
    /* loop down to find the leftmost leaf */
    while (current -> left != NULL) {
        cout<<"in while loop"<<endl;
      current = current -> left;
    }
    cout<<current->data<<"it is gona to return ";
    return current;
  }
    node * maxdataNode(node * noe) {
        cout<<"max called"<<endl;
    node * current = noe;
    /* loop down to find the leftmost leaf */
    while (current -> right != NULL) {
      current = current -> right;
    }
    return current;
  }
  int space;
    void print2D(node * r, int space) {
    cout<<"tree jevu aha"<<r->data<<endl;
    if (r == NULL) // Base case  1
    return ;
    space =space+ 10; // Increase distance between levels   2
    print2D(r -> right, space); // Process right child first 3 
    cout << endl;
    for (int i = 10; i < space; i++) // 5 
    cout << " "; // 5.1  
    cout << r -> data << "\n"; // 6
    print2D(r -> left, space); // Process left child  7
  }
//   node * deleteNode(node * r, int v) {
//     if (r == NULL) {
//       return NULL;
//     }
//     else if (v < r -> data) {
//       r -> left = deleteNode(r -> left, v);
//     } 
//     else if (v > r -> data) {
//       r -> right = deleteNode(r -> right, v);
//     }
//     // if key is same as root's key, then This is the node to be deleted 
//     else if(v==r->data){
//       // node with only one child or no child 
//       if (r -> left == NULL) {
//         node * temp = r -> right;
//         delete r;
//         return temp;
//       } else if (r -> right == NULL) {
//         node * temp = r -> left;
//         delete r;
//         return temp;
//       } else {
//         // node with two children: Get the inorder successor (smallest 
//         // in the right subtree) 
//         node * temp = mindataNode(r -> right);
//         // Copy the inorder successor's content to this node 
//         r -> data = temp -> data;
//         // Delete the inorder successor 
//          r -> right = deleteNode(r -> right, temp -> data);
//         //deleteNode(r->right, temp->data); 
//       }
//     }
//     else
//     {
//       cout<<"DELETION dataLUE NOT FOUND "<<endl;
//     }
//     return r;}
  
  node * deleteNode(node *r,int data)
  { cout<<"delete called"<<r<<" ---"<<r->data<<endl;

    if(r==nullptr){
        cout<<"1"<<endl;
        return nullptr;}
    else if(r->data>data){
        cout<<"2"<<endl;r->left=deleteNode(r->left,data);}
    else if(r->data<data){
        cout<<"3"<<endl;r->right=deleteNode(r->right,data);}
    else if(data==r->data)
    {   cout<<"4"<<endl;
        if(r->right==nullptr){
            cout<<"5"<<endl;
        node *temp=r->left;
        delete r;
        return temp;}
        
        if(r->left==nullptr){
            cout<<"6"<<endl;
        node *temp=r->right;
        delete r;
        return temp;}

        else{
            cout<<"7"<<endl;
            node* temp=mindataNode(r->right);
            cout<<"min out"<<endl;
        if(temp!=nullptr)
        {   cout<<"8"<<endl;
            r->data=temp->data;
        r->right=deleteNode(r->right,temp->data);}
        else{cout<<"9"<<endl;
            temp=maxdataNode(r->left);
            r->data=temp->data;
            r->left=deleteNode(r->left,temp->data);
        }
        }

    }
    else
    {
      cout<<"DELETION dataLUE NOT FOUND "<<endl;
    }
    return r;
  }

};
int main()
{   BST obj;
  int option,data;

  do {
    cout << "What operation do you want to perform? " <<
      " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Search Node" << endl;
    cout << "3. Delete Node" << endl;
    cout << "4. Print/Traversal BST datas" << endl;
    cout << "5. Height of Tree" << endl;
    cout << "6. Clear Screen" << endl;
    cout << "0. Exit Program" << endl;

    cin >> option;
    //Node n1;
    node * new_node = new node();

    switch (option) {
    case 0:
      break;
    case 1:
      	cout <<"INSERT"<<endl;
	      cout <<"Enter data of TREE NODE to INSERT in BST: ";
	      cin >> data;
	    obj.root=obj.insertRecursive(obj.root,data);
	      //obj.insertNode(new_node);
	      cout<<endl;
    		break;
        case 3:
      cout << "DELETE" << endl;
      cout << "Enter data of TREE NODE to DELETE in BST: ";
      cin >> data;
      obj.root=obj.deleteNode(obj.root,data);
      break;
    case 4:
      cout << "PRINT 2D: " << endl;
    obj.printLevelOrderBFS(obj.root);
      break;}}while(option!=0);

    return 0;
}
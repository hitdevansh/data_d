

Skip to content
Using Dhirubhai Ambani Institute of Information and Communication Technology Mail with screen readers
Conversations
Using 0.76 GB
Program Policies
Powered by Google
Last account activity: 28 minutes ago
Details
// Ashish Parmar 202101174

#include <iostream>
using namespace std;
class node;
class BinaryTree;

// queue implimentation using linked list

class Qnode
{
public:
    node *data;
    Qnode *next;
    Qnode(node *d)
    {
        data = d;
        next = nullptr;
    }
};

class Queue
{
public:
    Qnode *front, *rear;
    Queue()
    {
        front = rear = nullptr;
    }

    void enqueue(node *x)
    {
        Qnode *temp = new Qnode(x);

        if (front == nullptr)
        {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    node *dequeue()
    {
        if (front == nullptr)
            return NULL;

        Qnode *temp = front;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;
        node *t = temp->data;
        delete (temp);
        return t;
    }

    int empty(void)
    {
        if (front == nullptr)
            return 1;

        return 0;
    }

    node *top(void)
    {
        return front->data;
    }
};

// class Binary Tree
class node
{
public:
    int data;
    node *left;
    node *right;
};

class BinaryTree
{
public:
    node *root;
    node *deletion(node *t, int key);
    node *Insertnode(int data);
    node *Createnode(int data);
    void inorder(node *temp);
    void preorder(node *temp);
    void postorder(node *temp);
    void levelorder(node *temp);
    bool treecheck(node *root, node *min, node *max);
};

node *BinaryTree::Createnode(int data)
{
    node *newnode = new node();
    if (!newnode)
    {
        cout << "Memory error\n";
        return NULL;
    }
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

node *BinaryTree::Insertnode(int data)
{

    if (root == NULL)
    {
        root = Createnode(data);
        return root;
    }

    Queue q;
    q.enqueue(root);

    while (!q.empty())
    {
        node *temp;

        temp = q.front->data;
        q.dequeue();

        if (temp->left != NULL)
            q.enqueue(temp->left);
        else
        {
            temp->left = Createnode(data);
            return root;
        }

        if (temp->right != NULL)
            q.enqueue(temp->right);
        else
        {
            temp->right = Createnode(data);
            return root;
        }
    }
}

/* Inorder traversal of a binary tree */

void BinaryTree::inorder(node *temp)
{
    if (temp == NULL)
        return;

    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
}

void BinaryTree::preorder(node *temp)
{
    if (temp == NULL)
        return;

    cout << temp->data << " ";
    preorder(temp->left);
    preorder(temp->right);
}

void BinaryTree::postorder(node *temp)
{
    if (temp == NULL)
        return;

    postorder(temp->left);
    postorder(temp->right);
    cout << temp->data << " ";
}

void BinaryTree::levelorder(node *temp)
{
    if (root == NULL)
        return;

    Queue q;
    q.enqueue(root);

    while (!q.empty())
    {
        node *n = q.front->data;
        cout << n->data << " ";
        q.dequeue();

        if (n->left)
            q.enqueue(n->left);

        if (n->right)
            q.enqueue(n->right);
    }
}


node* BinaryTree:: deletion(node* t, int key)
{
    if(t==NULL)
    return NULL;

    if(t->left==NULL && t->right==NULL)
    {
        if(t->data==key)
        return NULL;

        else 
        return t;
    }

    node* temp;
    node* deletion_node;
    node* parent;
    Queue q;

    q.enqueue(t);
    while(!q.empty())
    {
        temp=q.top();
        q.dequeue();

        if(temp->data==key)
        {
            deletion_node=temp;
        }

        if(temp->left != NULL)
        {
            parent=temp;
            q.enqueue(temp->left);
        }

        if(temp->right!=NULL)
        {
            parent=temp;
            q.enqueue(temp->right);

        }


    }
    
    if(deletion_node != NULL)
    {
        deletion_node->data=temp->data;
        if(parent->right==temp)
        parent->right=NULL;
        else
        parent->left=NULL;
        delete(temp);
    }
    return t;

}
// node *BinaryTree::deletion(node *t, int key)
// {
//     if (t == NULL)
//         return NULL;
//     if (t->left == NULL && t->right == NULL)
//     {
//         if (t->data == key)
//             return NULL;

//         return root;
//     }
//     node *key_node = NULL;
//     node *temp;
//     node *last;
//     Queue q;
//     q.enqueue(t);

//     while (!q.empty())
//     {
//         temp = q.top();
//         q.dequeue();
//         if (temp->data == key)
//             key_node = temp;
//         if (temp->left)
//         {
//             last = temp; // storing the parent node
//             q.enqueue(temp->left);
//         }
//         if (temp->right)
//         {
//             last = temp; // storing the parent node
//             q.enqueue(temp->right);
//         }
//     }
//     if (key_node != NULL)
//     {
//         key_node->data = temp->data; // replacing key_node's data to deepest node's data
//         if (last->right == temp)
//             last->right = NULL;
//         else
//             last->left = NULL;
//         delete (temp);
//     }
//     return t;
// }

// Binary Search Tree
class BSTnode
{
public:
    int data;
    BSTnode *left;
    BSTnode *right;
};

class BST
{
public:
    BSTnode *BSTroot = NULL;
    void BSTinsert(BSTnode *t, int key);
    BSTnode *CreateNode(int key);
    BSTnode *inorder(BSTnode *t);
    BSTnode *preorder(BSTnode *t);
    BSTnode *postorder(BSTnode *t);
    BSTnode *BSTdeletion(BSTnode *t, int key);
    BSTnode *sucessor(BSTnode *t);
    int searchNode(BSTnode *t, int key);
};

BSTnode *BST::CreateNode(int key)
{
    BSTnode *temp;
    temp = new BSTnode;
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp;
}

void BST::BSTinsert(BSTnode *t, int key)
{
    BSTnode *p;
    if (BSTroot == NULL)
    {
        BSTroot = CreateNode(key);
        return;
    }
    else
    {
        while (t)
        {
            p = t;

            if (key >= t->data)
                t = t->right;

            else
                t = t->left;
        }

        BSTnode *temp = CreateNode(key);
        if (key >= p->data)
            p->right = temp;
        else if (key < p->data)
            p->left = temp;
    }
}

BSTnode *BST::inorder(BSTnode *t)
{
    if (t == NULL)
        return NULL;
    inorder(t->left);
    cout << t->data << ",";
    inorder(t->right);
}

BSTnode *BST::preorder(BSTnode *t)
{
    if (t == NULL)
        return NULL;

    cout << t->data << ",";
    preorder(t->left);
    preorder(t->right);
}

BSTnode *BST::postorder(BSTnode *t)
{
    if (t == NULL)
        return NULL;

    postorder(t->left);
    postorder(t->right);
    cout << t->data << ",";
}

BSTnode *BST::sucessor(BSTnode *t)
{
    BSTnode *temp = t;
    while (temp && temp->left != NULL)
    {
        t = t->left;
    }

    return t;
}
BSTnode *BST::BSTdeletion(BSTnode *t, int key)
{
    if (key < t->data)
        t->left = BSTdeletion(t->left, key);

    else if (key > t->data)
        t->right = BSTdeletion(t->right, key);

    else
    {

        if (!t->left)
        {
            BSTnode *temp = t->right;
            free(t);
            return temp;
        }

        else if (!t->right)
        {
            BSTnode *temp = t->left;
            free(t);
            return temp;
        }

        BSTnode *temp = sucessor(t->right);
        t->data = temp->data;
        t->right = BSTdeletion(t->right, temp->data);
    }

    return t;
}

bool BinaryTree::treecheck(node *root, node *min, node *max)
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

int flag = 0;
int BST::searchNode(BSTnode *t, int key)
{
    if (t == NULL)
    {

        return 0;
    }

    if (t->data == key)
    {
        flag = 1;
        return 0;
    }
    if (key >= t->data)
        searchNode(t->right, key);

    if (key < t->data)
        searchNode(t->left, key);

    else
    {
        return 0;
    }
}

int main()
{

    BinaryTree t;
    t.root = NULL;
    BST t1;
    t1.BSTroot = NULL;
    int choice;
    int data;
up:
    cout << "\n\n";
    cout << "Insert in Binary Tree(press 1): " << endl
         << "Insert in Binary Search Tree (press 2): " << endl
         << "Delete in Binary Tree (press 3): " << endl
         << "Delete in Binary Search Tree (press 4): " << endl
         << "Search in Binary Search Tree (press 5): " << endl
         << "Check for Binary Search Tree (press 6): " << endl
         << "For Traversals of Binary Tree (press 7): " << endl
         << "For Traversals of Binary Search Tree (press 8): " << endl
         << "For Exit (press 9): " << endl;

    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Enter the data value: ";
        cin >> data;
        t.root=t.Insertnode(data);
        cout << "After insertion:";
        t.inorder(t.root);

        break;

    case 2:
        cout << "Enter the data value: ";
        cin >> data;
        t1.BSTinsert(t1.BSTroot, data);
        cout << "After insertion:";
        t1.inorder(t1.BSTroot);
        break;

    case 3:
        cout << "Enter the data value that you want to delete: ";
        cin >> data;
        t.root= t.deletion(t.root,data);
        cout << "After deletion: ";
        t.inorder(t.root);
        break;

    case 4:
        cout << "Enter the data value that you want to delete: ";
        cin >> data;
        t1.BSTroot=t1.BSTdeletion(t1.BSTroot, data);
        cout << "After deletion: ";
        t1.inorder(t1.BSTroot);
        break;

    case 5:
        int data;
        cout <<"Enter the value: ";
        cin>>data;
        t1.searchNode(t1.BSTroot,data);
        if(flag)cout<<"Node found !"<<endl;
        else cout<<"Not found !"<<endl;

        break;

    case 6:
        if (t.treecheck(t.root, NULL, NULL))
            cout << "True";
        else
            cout << "False";
        break;

    case 7:
        cout << "Inorder Traversal: ";
        t.inorder(t.root);
        cout << "\nPreorer Traversal: ";
        t.preorder(t.root);
        cout << "\nPostorder Traversal: ";
        t.postorder(t.root);
        break;

    case 8:
        cout << "Inorder Traversal: ";
        t1.inorder(t1.BSTroot);
        cout << "\nPreorer Traversal: ";
        t1.preorder(t1.BSTroot);
        cout << "\nPostorder Traversal: ";
        t1.postorder(t1.BSTroot);
        break;

    case 9:
        cout << "Exit !!";
        goto endofprogramme;
        break;

    default:
        cout << "Wrong Input" << endl;
        break;
    }

    goto up;

endofprogramme:

    return 0;
}
202101174_Lab8.cpp
Displaying 202101174_Lab8.cpp.
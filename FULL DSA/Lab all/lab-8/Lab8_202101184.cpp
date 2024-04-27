#include <iostream>
#define SPACE 10
using namespace std;
class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue
{
private:
    int size;
    int front;
    int rear;
    Node **Q; // [Node*]*: Pointer to [Pointer to Node]
public:
    Queue(int size);
    bool isFull();
    bool isEmpty();
    void enqueue(Node *x);
    Node *dequeue();
};


int Height(Node *p)
{
    int l = 0;
    int r = 0;
    if (p == nullptr)
    {
        return 0;
    }

    l = Height(p->lchild);
    r = Height(p->rchild);

    if (l > r)
    {
        return l + 1;
    }
    else
    {
        return r + 1;
    }
}
Queue::Queue(int size)
{
    this->size = size;
    front = -1;
    rear = -1;
    Q = new Node *[size];
}

bool Queue::isEmpty()
{
    if (front == rear)
    {
        return true;
    }
    return false;
}

bool Queue::isFull()
{
    if (rear == size - 1)
    {
        return true;
    }
    return false;
}

void Queue::enqueue(Node *x)
{
    if (isFull())
    {
        cout << "Queue Overflow" << endl;
    }
    else
    {
        rear++;
        Q[rear] = x;
    }
}

Node *Queue::dequeue()
{
    Node *x = nullptr;
    if (isEmpty())
    {
        cout << "Queue Underflow" << endl;
    }
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}

Node *root = new Node;
int c = 0;
Node *p;
Node *t;
Queue q(500);
int createTree()
{
    int x;
    if (c == 0)
    {
        cout << "Enter root value: " << flush;
        cin >> x;
        root->data = x;
        root->lchild = nullptr;
        root->rchild = nullptr;
        q.enqueue(root);
        c++;
        goto jump;
    }
    else
    {
    jump:
        while (!q.isFull())
        {
            p = q.dequeue();
            cout << "Enter left child value of " << p->data << ": " << endl;
            cin >> x;
            if (x != -1)
            {
                t = new Node;
                t->data = x;
                t->lchild = nullptr;
                t->rchild = nullptr;
                p->lchild = t;
                q.enqueue(t);
            }
            cout << "Enter right child value of " << p->data << ": " << endl;
            cin >> x;
            if (x != -1)
            {
                t = new Node;
                t->data = x;
                t->lchild = nullptr;
                t->rchild = nullptr;
                p->rchild = t;
                q.enqueue(t);
            }
            cout << "press 0 for exit or anything else to continue" << endl;
            cin >> x;
            if (x == 0)
            {
                return 0;
            }
        }
    }
}
int mcheck = 0;//for check that element is exist or not in tree
Node *prevs = 0;
Node *curr = 0;
Node *repls = 0;
int check = 0;
void search(Node *&root, int key)
{
    if (root == 0)
        return;
    if (root->data == key)
    {
        mcheck = 1, repls = root;
    }
   
    if ((root->lchild) == 0 && root->rchild == 0)
    {
        if (check == 0)
        {
            check = 1;
            curr = root;
            search(root, key);
        }
    }
    if (check == 0)
    {
        prevs = root;
    }
     if (root->rchild)
        search(root->rchild, key);
    if (root->lchild)
        search(root->lchild, key);

}
void delet(Node *&root, int key)
{

    if (root == 0)
    {
        cout << "tree is empty so nothing will be deleted \n";
        return;
    }
    else if (root->data == key && root->lchild == 0 && root->rchild == 0)
    {
        Node *temp = *root;
        *root = 0;
        delete (temp);
        cout << endl
        << "Data is deleted succesfully ";
        return;
    }
    else
    {
        search(root, key);
        if (mcheck == 0)
        {
            cout << "element is not resent in tree : \n";
            return;
        }
        else
        {
            Node *temp = curr;
            repls->data = temp->data;
            if (prevs->lchild == temp)
            {
                prevs->lchild = 0;
            }
            else
            {
                prevs->rchild = 0;
            }
            delete (temp);
            cout << endl
                 << "Data is deleted succesfully ";
        }
    }
}
void print2D(Node *r, int space)
{
    if (r == NULL) // Base case  1
        return;
    space =space+ 10;            // Increase distance between levels   2
    print2D(r->rchild, space); // Process right child first 3
    cout << endl;
    for (int i = 10; i < space; i++) // 5
        cout << " ";                    // 5.1
    cout << r->data << "\n";            // 6
    print2D(r->lchild, space);          // Process left child  7
}
// Node *ip(Node **root){

// }
void preorder(Node *p)
{
    if (p)
    {
        cout << p->data << ", " << flush;
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        cout << p->data << ", " << flush;
        inorder(p->rchild);
    }
}

void postorder(Node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << ", " << flush;
    }
}

int main()
{

    while (1)
    {
        cout << endl
             << "Enter 1 to create tree , 2 for preorder ,3 for postorder , 4 for Inorder , press 5 for deleting ,enter 6 for 2d print , press 8 for height of tree and 0 for exit " << endl;
        int p;
        cin >> p;
        if (p == 1)
        {
            createTree();
        }
        else if (p == 2)
        {
            preorder(root);
        }
        else if (p == 3)
        {
            postorder(root);
        }
        else if (p == 4)
        {
            inorder(root);
        }
        else if (p == 5)
        {
            cout << "Enter a data to delete form a tree " << endl;
            int data;
            cin >> data;
            delet(&root, data);
        }
        else if (p == 6)
        {
            print2D(root, 5);
        }
        else if (p == 8)
        {
            int h;
            h = Height(root);
            cout << endl
                 << "Height is :" << h << endl;
        }
        else if (p == 0)
        {
            return 0;
        }
    }

    return 0;
}

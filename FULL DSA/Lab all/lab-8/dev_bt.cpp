#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *right;
    node *left;
};
class binarytree;
class nodequeue
{
public:
    node *data;
    nodequeue *next;
    nodequeue(node *val)
    {
        data = val;
        next = NULL;
    }
};
class queue
{
public:
    nodequeue *front = NULL;
    nodequeue *rear = NULL;
    void enque(node *val)
    {
        nodequeue *n = new nodequeue(val);
        if (front == nullptr)
        {
            front = rear = n;
            return;
        }
        rear->next = n;
        rear = n;
        
    }
    void deque()
    {
        if (front == nullptr)
        {
            cout << "no data" << endl;
            return;
        }
        nodequeue *temp = front;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        delete(temp);
    }
    int empty()
    {
        if (front == nullptr)
           { return 1;}
        return 0;
    }
};
class binarytree
{
public:
    node *root;
    node *createnode(int val)
    {
        node *n = new node();
        n->data = val;
        n->right = nullptr;
        n->left = nullptr;

        return n;
    }
    void preorder(node *root)
    {
        if (root == NULL)
            return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(node *root)
    {
        if (root == NULL)
            return;

        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    void inorder(node *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    node *insertnode(int val)
    {
        if (root == NULL)
        {
            root = createnode(val);
            return root;
        }
        queue q;
        q.enque(root);
        while (!q.empty())
        {
            node *t;
            t = q.front->data;
            q.deque();
            if (t->left != NULL)
            {
                q.enque(t->left);
            }
            else
            {
                t->left = createnode(val);
                return root;
            }

            if (t->right != nullptr)
            {
                q.enque(t->right);
            }
            else
            {
                t->right = createnode(val);
                return root;
            }
        }
    }
    node *deletenode(int key)
    {

        if (root == NULL)
            return NULL;
        if (root->left == NULL && root->right == NULL)
        {
            if (root->data == key)
            {
                root = NULL;
                return NULL;
            }
            else
                return root;
        }

        node *keynode = NULL;
        node *temp = NULL;
        node *last = NULL;
        queue q;
        q.enque(root);
        while (!q.empty())
        {
            temp = q.front->data;
            q.deque();
            if (temp->data == key)
            {
                keynode = temp;
            }
            if (temp->left)
            {
                last = temp;
                q.enque(temp->left);
            }
            if (temp->right)
            {
                last = temp;
                q.enque(temp->right);
            }
        }
        if (keynode != nullptr)

        {
            keynode->data = temp->data;
            if (last->right == temp)
            {
                last->right = NULL;
            }
            else
                last->left = NULL;
            delete (temp);
        }
        else
        {
            cout << "key is not found " << endl;
        }
        return root;
    }

   void levelordertraversal(node *t)
    {
        if (root == NULL)
            return;
        queue q;
        q.enque(root);

        while (!q.empty())
        {
            node *n = q.front->data;
            cout << n->data << " ";
            q.deque();
            if (n->left)
            {
                q.enque(n->left);
            }
            if (n->right)
            {
                q.enque(n->right);
            }
        }
    }
    void print2D(node *r, int space)
    {
        if (r == NULL) // Base case  1
            return;
        space = space + 10;       // Increase distance between levels   2
        print2D(r->right, space); // Process right child first 3
        cout << endl;
        for (int i = 10; i < space; i++) // 5
            cout << " ";                 // 5.1
        cout << r->data << "\n";         // 6
        print2D(r->left, space);         // Process left child  7
    }
};
int main()
{
    binarytree b;
    b.root = NULL;
    int ch;

    while (1)
    {

        cout << endl;
        cout << "Enter your choice " << endl;
        cout << "Enter 1 for insertion in the tree " << endl;
        cout << "Enter 2 for deletion in the tree " << endl;
        cout << "Enter 3 for show the inorder traversal in the tree " << endl;
        cout << "Enter 4 for show the postorder traversal in the tree " << endl;
        cout << "Enter 5 for show the prerder traversal in the tree " << endl;
        cout << "Enter 6 for show the level order traversal in the tree " << endl;
        cout << "Enter 7 for exit " << endl;
        cin >> ch;
        if (ch == 1)
        {
            cout << "Enter the data you want to insert in the tree " << endl;
            int data;
            cin >> data;
            b.insertnode(data);
            cout << "After insertion the tree is like this " << endl;
            b.inorder(b.root);
        }

        if (ch == 2)
        {
            cout << "Enter the data you want to delete from the tree " << endl;
            int data;
            cin >> data;
            b.deletenode(data);
            cout << "After deletion the data " << data << " The tree is like this " << endl;
            b.inorder(b.root);
        }

        if (ch == 3)
        {
            cout << " The inorder traversal is " << endl;
            b.inorder(b.root);
        }

        if (ch == 4)
        {
            cout << " The preorder traversal is " << endl;
            b.preorder(b.root);
        }

        if (ch == 5)
        {
            cout << " The postorder traversal is " << endl;
            b.postorder(b.root);
        }

        if (ch == 6)
        {
            cout << " The levelorder traversal is " << endl;
            b.levelordertraversal(b.root);
        }
        if (ch == 8)
        {
            b.print2D(b.root, 10);
        }
        if (ch == 7)
            break;
    }
    return 0;
}
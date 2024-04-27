#include <iostream>
using namespace std;
class queue;
class node;
queue *rear = NULL;
queue *front = NULL;
class queue
{
public:
    node *data2;
    queue *next;
    queue()
    {
    }
    queue(node *k)
    {
        data2 = k;
        next = NULL;
    }
    int isempty(queue *&head)
    {
        if (head == NULL)
            return 1;
        else
            return 0;
    }
    void push(queue *&head, node *k)
    {
        queue *n = new queue(k);
        queue *temp = head;
        if (head == NULL)
        {
            head = n;
            rear = front = head;
            return;
        }
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
        rear = n;
    }
    node *getfront(queue *head)
    {
        if (head == NULL)
        {
            cout << "Nothing in the front" << endl;
            return 0;
        }
        else
        {
            return front->data2;
        }
    }
    void pop(queue *&head)
    {
        queue *temp = head;
        if ((front == rear) && (rear != NULL))
        {
            delete(temp);
            head = front = rear = NULL;
        }
        else
        {
            head = head->next;
            front = front->next;
            delete(temp);
        }
    }
    void display(queue *&head)
    {
        queue *temp = front;
        if (front == NULL)
        {
            cout << "nothing to print" << endl;
        }
        else
        {
            while (temp != rear)
            {
                cout << temp->data2 << endl;
                temp = temp->next;
            }
            cout << temp->data2 << endl;
        }
    }
};
node *extra;
node *extra2;
class node
{
    friend class queue;

public:
    node *left;
    node *right;
    string data;
    node() {}
    node(string k)
    {
        data = k;
        left = right = NULL;
    }
    void dee(node *root)
    {
        int max = -1;
        string da = " ";
        find(root, 0, max,da);
    }
    void find(node *root, int le, int &max, string &da)
    {
        if (root != NULL)
        {
            find(root->left, ++le, max, da);
            if (le >= max)
            {
                extra = root;
                max = le;
            }
            find(root->right, le, max, da);
        }
    }
    void fofind(node *root, string k)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->data == k)
        {
            extra2 = root;
        }
        fofind(root->left, k);
        fofind(root->right, k);
    }
    void del(node *&root)
    {
        dee(root);
        cout << "Enter the element of the node which you want to delete" << endl;
        string k3;
        cin >> k3;
        fofind(root, k3);
        extra2->data = extra->data;
        wow(root, extra->data);
        delete (extra);
    }
    void wow(node *root, string k)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left != NULL)
        {
            if ((root->left->data == k) && (root->left != extra2))
            {
                root->left = NULL;
            }
            else if((root->left->data == k) && (extra == extra2))
            {
                root->left = NULL;
            }
        }
        if (root->right != NULL)
        {
            if ((root->right->data == k) && (root->right != extra2))
            {
                root->right = NULL;
            }
             else if((root->right->data == k) && (extra == extra2))
            {
                root->right = NULL;
            }
        }
        wow(root->left, k);
        wow(root->right, k);
    }
    void insert(node *&root)
    {
        cout << "Enter the elemet which you want to insert" << endl;
            string k7;
            cin >> k7;
        queue q1;
        queue *head = NULL;
        node *n = new node(k7);
        if (root == NULL)
        {
            root = n;
            return;
        }
        q1.push(head, root);
        node *temp = new node;
        while (q1.isempty(head) != 1)
        {
            node *temp = new node;
            temp = q1.getfront(head);
            q1.pop(head);
            if (temp->left != NULL)
            {
                q1.push(head, temp->left);
            }
            else
            {
                temp->left = n;
                return;
            }
            if (temp->right != NULL)
            {
                q1.push(head, temp->right);
            }
            else
            {
                temp->right = n;
                return;
            }
        }
        root = temp;
    }
    void inorder(node *temp)
    {
        if (temp == NULL)
            return;

        inorder(temp->left);
        cout << temp->data << ' ';
        inorder(temp->right);
    }
    void preorder(node *temp)
    {
        if (temp == NULL)
            return;

        cout << temp->data << ' ';
        preorder(temp->left);
        preorder(temp->right);
    }
    void postorder(node *temp)
    {
        if (temp == NULL)
            return;

        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << ' ';
    }
    void leveloeder(node *root)
    {
        queue q1;
        queue *head = NULL;
        if (root == NULL)
        {
            cout << "Nothing to print" << endl;
            return;
        }
        q1.push(head, root);
        node *temp = new node;
        while (q1.isempty(head) != 1)
        {
            node *temp = new node;
            temp = q1.getfront(head);
            cout << temp->data << endl;
            q1.pop(head);
            if (temp->left != NULL)
            {
                q1.push(head, temp->left);
            }
            if (temp->right != NULL)
            {
                q1.push(head, temp->right);
            }
        }
        root = temp;
    }
};

int main()
{
    node n1;
    node *root = NULL;
    int i = 0;
    while (i != -1)
    {
        cout << "If you want to insert a node in the bnary tree then enter 1" << endl;
        cout << "If you want to delete a specific node then enter 2" << endl;
        cout << "If you want to show the inorder of the binary tree then enter 3" << endl;
        cout << "If you want to show the preoreder of the binary list then enter 4" << endl;
        cout << "If you want to show the postorder of the binary tree then enter 5" << endl;
        cout << "If you want to show the levelorder of the binary tree then enter 6" << endl;
        cout << "If you want to exit then enter -1" << endl;
        cin >> i;
        cout << endl;
        switch (i)
        {
        case 1:
            n1.insert(root);
            cout << endl;
            break;
        case 2:
            n1.del(root);
            cout << endl;
            break;
        case 3:
            n1.inorder(root);
            cout << endl;
            cout << endl;
            break;
        case 4:
            n1.preorder(root);
            cout << endl;
            cout << endl;
            break;
        case 5:
            n1.postorder(root);
            cout << endl;
            cout << endl;
            break;
        case 6:
            n1.leveloeder(root);
            cout << endl;
            cout << endl;
            break;
        default:
            cout << "You are entering the worng information" << endl;
            break;
        }
    }
    return 0;
}

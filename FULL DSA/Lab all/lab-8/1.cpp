#include <stdlib.h>
#include <iostream>
using namespace std;
class node;
class node
{
public:
    int val;
    class node *left;
    class node *right;

    void insert(node *root,int key)
    {
        node *newnode;
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->val = key;
    }

    // Traverse Preorder
    void traversePreOrder(node *temp)
    {
        cout << "Preorder" << endl;
        if (temp == NULL)
        {
            return;
        }
        cout << " " << temp->val;
        traversePreOrder(temp->left);
        traversePreOrder(temp->right);
    }

    // Traverse Inorder
    void traverseInOrder(node *temp)
    {
        if (temp == NULL)
        {
            return;
        }
        traverseInOrder(temp->left);
        cout << " " << temp->val;
        traverseInOrder(temp->right);
    }

    // Traverse Postorder
    void traversePostOrder(node *temp)
    {
        if (temp == NULL)
        {
            return;
        }
        traversePostOrder(temp->left);
        traversePostOrder(temp->right);
        cout << " " << temp->val;
    }

    int successor(node *root)
    {
        root = root->right;
        while (root->left != NULL)
        {
            root = root->left;
        }
        return root->val;
    }

    int predecessor(node *root)
    {
        root = root->left;
        while (root->right != NULL)
        {
            root = root->right;
        }
        return root->val;
    }

    node *deleteNode(node *root, int key)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }

        else if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }

        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                root = NULL;
            }

            else if (root->right != NULL)
            {
                root->val = successor(root);
                root->right = deleteNode(root->right, root->val);
            }

            else
            {
                root->val = predecessor(root);
                root->left = deleteNode(root->left, root->val);
            }
        }

        return root;
    }
};
node *root;
int main()
{
    node b1;
    b1.insert(root,4);
    b1.insert(root->left,2);
    b1.insert(root->right,5);
    cout << "Enter 1 for insert " << endl
         << "Enter 2 for delete" << endl
         << "Enter 3 for preorer" << endl
         << "Enter 4 for postorer"
         << endl
         << "Enter 5 for inorer" << endl;

    char ch = 10;
    while (ch != 0)
    {
        cout << "Choose a option for perform a opereton " << endl;
        cin >> ch;
        if (ch == 3)
        {
            b1.traversePreOrder(root);
        }
        else if (ch == 2)
        {
            cout << "Enter a value to delete" << endl;
            int i = 0;
            cin >> i;
            // b1.deletenode(root,i);
        }
        // else if (ch == 1)
        // {
        //     b1.insert(tmp);
        // }
        else if (ch == 5)
        {
            cout << "\nInorder traversal: ";
            b1.traverseInOrder(root);
        }
        else if (ch == 4)
        {
            cout << "\nPostorder traversal: ";
            b1.traversePostOrder(root);
        }
    }
}

#include <iostream>
#define SPACE 10

using namespace std;

class TreeNode
{
public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode()
  {
    val = 0;
    left = NULL;
    right = NULL;
  }
  TreeNode(int v)
  {
    val = v;
    left = NULL;
    right = NULL;
  }
};

class BST
{
public:
  TreeNode *root;
  BST()
  {
    root = NULL;
  }
  bool isTreeEmpty()
  {
    if (root == NULL)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  TreeNode *insertRecursive(TreeNode *r, TreeNode *new_node)
  {
    if (r == NULL)
    {
      r = new_node;
      cout << "Insertion successful" << endl;
      return r;
    }

    if (new_node->val < r->val)
    {
      r->left = insertRecursive(r->left, new_node);
    }
    else if (new_node->val > r->val)
    {
      r->right = insertRecursive(r->right, new_node);
    }
    else
    {
      cout << "No duplicate vals allowed!" << endl;
      return r;
    }
    return r;
  }

  void print2D(TreeNode *r, int space)
  {
    if (r == NULL) // Base case  1
      return;
    space += SPACE;           // Increase distance between levels   2
    print2D(r->right, space); // Process right child first 3
    cout << endl;
    for (int i = SPACE; i < space; i++) // 5
      cout << " ";                      // 5.1
    cout << r->val << "\n";             // 6
    print2D(r->left, space);            // Process left child  7
  }

  void printPreorder(TreeNode *r) //(current node, Left, Right)
  {
    if (r == NULL)
      return;
    /* first print data of node */
    cout << r->val << " ";
    /* then recur on left sutree */
    printPreorder(r->left);
    /* now recur on right subtree */
    printPreorder(r->right);
  }

  void printInorder(TreeNode *r) //  (Left, current node, Right)
  {
    if (r == NULL)
      return;
    /* first recur on left child */
    printInorder(r->left);
    /* then print the data of node */
    cout << r->val << " ";
    /* now recur on right child */
    printInorder(r->right);
  }
  void printPostorder(TreeNode *r) //(Left, Right, Root)
  {
    if (r == NULL)
      return;
    // first recur on left subtree
    printPostorder(r->left);
    // then recur on right subtree
    printPostorder(r->right);
    // now deal with the node
    cout << r->val << " ";
  }

  TreeNode *iterativeSearch(int v)
  {
    if (root == NULL)
    {
      return root;
    }
    else
    {
      TreeNode *temp = root;
      while (temp != NULL)
      {
        if (v == temp->val)
        {
          cout << "Value is here presented !" << endl;
          return temp;
        }
        else if (v < temp->val)
        {
          temp = temp->left;
        }
        else
        {
          temp = temp->right;
        }
      }
      return NULL;
    }
  }

  TreeNode *recursiveSearch(TreeNode *r, int val)
  {
    if (r == NULL || r->val == val)
      return r;

    else if (val < r->val)
      return recursiveSearch(r->left, val);

    else
      return recursiveSearch(r->right, val);
  }

  int height(TreeNode *p)
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

  void insertNode(TreeNode *new_node)
  {
    if (root == NULL)
    {
      root = new_node;
      cout << "Value Inserted as root node!" << endl;
    }
    else
    {
      TreeNode *temp = root;
      while (temp != NULL)
      {
        if (new_node->val == temp->val)
        {
          cout << "Value Already exist,"
               << "Insert another value!" << endl;
          return;
        }

        else if ((new_node->val < temp->val) && (temp->left == NULL))
        {
          temp->left = new_node;
          cout << "Value Inserted to the left!" << endl;
          break;
        }

        else if (new_node->val < temp->val)
        {
          temp = temp->left;
        }

        else if ((new_node->val > temp->val) && (temp->right == NULL))
        {
          temp->right = new_node;
          cout << "Value Inserted to the right!" << endl;
          break;
        }

        else
        {
          temp = temp->right;
        }
      }
    }
  }
  /* Print nodes at a given level */
  void printGivenLevel(TreeNode *r, int level)
  {
    if (r == NULL)
      return;
    else if (level == 0)
      cout << r->val << " ";
    else // level > 0
    {
      printGivenLevel(r->left, level - 1);
      printGivenLevel(r->right, level - 1);
    }
  }
  void printLevelOrderBFS(TreeNode *r)
  {
    int h = height(r);
    for (int i = 0; i <= h; i++)
      printGivenLevel(r, i);
  }

  TreeNode *minvalNode(TreeNode *node)
  {
    TreeNode *current = node;
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
    {
      current = current->left;
    }
    return current;
  }

  TreeNode *deleteNode(TreeNode *r, int v)
  {
    if (r == NULL)
    {
      return NULL;
    }
    else if (v < r->val)
    {
      r->left = deleteNode(r->left, v);
    }
    else if (v > r->val)
    {
      r->right = deleteNode(r->right, v);
    }
    // if key is same as root's key, then This is the node to be deleted
    else if (v == r->val)
    {
      // node with only one child or no child
      if (r->left == NULL)
      {
        TreeNode *temp = r->right;
        delete r;
        return temp;
      }
      else if (r->right == NULL)
      {
        TreeNode *temp = r->left;
        delete r;
        return temp;
      }
      else
      {
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        TreeNode *temp = minvalNode(r->right);
        // Copy the inorder successor's content to this node
        r->val = temp->val;
        // Delete the inorder successor
        r->right = deleteNode(r->right, temp->val);
        // deleteNode(r->right, temp->val);
      }
    }
    else
    {
      cout << "DELETION VALLUE NOT FOUND " << endl;
    }
    return r;
  }
};

int main()
{
  BST obj;
  int option, val;

  do
  {
    cout << "What operation do you want to perform? "
         << " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Search Node" << endl;
    cout << "3. Delete Node" << endl;
    cout << "4. Print/Traversal BST vals" << endl;
    cout << "5. Height of Tree" << endl;
    cout << "6. Clear Screen" << endl;
    cout << "0. Exit Program" << endl;

    cin >> option;
    // Node n1;
    TreeNode *new_node = new TreeNode();

    switch (option)
    {
    case 0:
      break;
    case 1:
      cout << "INSERT" << endl;
      cout << "Enter val of TREE NODE to INSERT in BST: ";
      cin >> val;
      new_node->val = val;
      // obj.root= obj.insertRecursive(obj.root,new_node);
      obj.insertNode(new_node);
      cout << endl;
      break;

    case 2:
      cout << "SEARCH" << endl;
      cout << "Enter val of TREE NODE to SEARCH in BST: ";
      cin >> val;
      // new_node = obj.iterativeSearch(val);
      new_node = obj.recursiveSearch(obj.root, val);
      if (new_node != NULL)
      {
        cout << "val found" << endl;
      }
      else
      {
        cout << "val NOT found" << endl;
      }
      break;
    case 3:
      cout << "DELETE" << endl;
      cout << "Enter val of TREE NODE to DELETE in BST: ";
      cin >> val;
      obj.deleteNode(obj.root, val);
      break;
    case 4:
      cout << "PRINT 2D: " << endl;
      obj.print2D(obj.root, 5);
      cout << endl;
      cout << "Print Level Order BFS: \n";
      // obj.order(obj.root);
      cout << endl;
      //	      cout <<"PRE-ORDER: ";
      //	      obj.printPreorder(obj.root);
      //	      cout<<endl;
      //	      cout <<"IN-ORDER: ";
      //	      obj.printInorder(obj.root);
      //	      cout<<endl;
      //	      cout <<"POST-ORDER: ";
      //	      obj.printPostorder(obj.root);
      break;
    case 5:
      cout << "TREE HEIGHT" << endl;
      cout << "Height : " << obj.height(obj.root) << endl;
      break;
    case 6:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}
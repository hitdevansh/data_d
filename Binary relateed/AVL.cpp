#include<iostream>
#define SPACE 10
using namespace std;
class TreeNode {
  public:
    int val;
  TreeNode * left;
  TreeNode * right;
  int height;
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

class BST {
  public:
    TreeNode * root;
  BST() {
    root = NULL;
  }
  bool isTreeEmpty() {
    if (root == NULL) {
      return true;
    } else {
      return false;
    }
  }
  TreeNode* LLRotation(TreeNode *p) {
    TreeNode* pl = p->left;
    TreeNode* plr = pl->right;
 
    pl->right= p;
    p->left = plr;
 
    // Update height
    p->height = height(p);
    pl->height = height(pl);
 
    // Update root
    if (root == p){
        root = pl;
    }
    return pl;
}
 
TreeNode* RRRotation(TreeNode *p) {
    TreeNode* pr = p->right;
    TreeNode* prl = pr->right;
 
    p->right = pr->left;
    pr->left = p;
 
    // Update heightSS
    p->height = height(p);
    pr->height = height(pr);
 
    // Update root
    if (root == p){
        root = pr;
    }
    return pr;
}
 
TreeNode* LRRotation(TreeNode *p) {
    TreeNode* pl = p->left;
    TreeNode* plr = pl->right;
 
    pl->right = plr->left;
    p->left = plr->right;
 
    plr->left = pl;
    plr->right = p;
 
    // Update height
    pl->height = height(pl);
    p->height = height(p);
    plr->height = height(plr);
 
    // Update root
    if (p == root){
        root = plr;
    }
    return plr;
}



// This code is contributed by shubhamsingh10

TreeNode* RLRotation(TreeNode *p) {
    TreeNode* pr = p->right;
    TreeNode* prl = pr->left;
 
    pr->left = prl->right;
    p->right = prl->left;
 
    prl->right = pr;
    prl->left = p;
 
    // Update height
    pr->height = height(pr);
    p->height = height(p);
    prl->height = height(prl);
 
    // Update root
    if (root == p){
        root = prl;
    }
    return prl;
}
   int BalanceFactor(TreeNode *p) {
    int hl;
    int hr;
    cout<<"Balance factor run for "<<p->val<<endl;
    hl = height(p->left);
    hr = height(p->right);
    return hl - hr;}
    

  TreeNode * insertRecursive(TreeNode *r, TreeNode *new_node)
	{
		if(r==NULL)
		{
			r=new_node;
			cout <<"Insertion successful"<<endl;
      r->height=1;
			return r;
		}
		if(new_node->val < r->val)
		{
			r->left = insertRecursive(r->left,new_node);
		}
		else if (new_node->val > r->val)  
		{
			r->right = insertRecursive(r->right,new_node);
		}
	   else
	   {
	     	cout << "No duplicate vals allowed!" << endl;
	     	return r; 
		}
    // Update height
    
    r->height = height(r);
    // cout<<"hello "<<r->val<<endl;
    // Balance Factor and Rotation
    /*First this will check for recurcive function of this then this again call main function 
     so basically this wwill go to dipper for insert and when came back so it will again check
     from dipper to outside*/ 
    if (BalanceFactor(r) == 2 && BalanceFactor(r->left) == 1) {
        cout<<"So here we need rotaion for "<<r->val<<endl;
        return LLRotation(r);
    } else if (BalanceFactor(r) == 2 && BalanceFactor(r->left) == -1){
        cout<<"So here we need rotaion for "<<r->val<<endl;
        return LRRotation(r);
    } else if (BalanceFactor(r) == -2 && BalanceFactor(r->right) == -1){
        cout<<"So here we need rotaion for "<<r->val<<endl;
        return RRRotation(r);
    } else if (BalanceFactor(r) == -2 && BalanceFactor(r->right) == 1){
        cout<<"So here we need rotaion for "<<r->val<<endl;
        return RLRotation(r);
    }
 return r;
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
    print2D(r -> left, space);   }

  void printPreorder(TreeNode * r) 
  {
    if (r == NULL)
      return;
    cout << r -> val << " ";
    /* then recur on left sutree */
    printPreorder(r -> left);
    /* now recur on right subtree */
    printPreorder(r -> right);
  }

  void printInorder(TreeNode * r) //  (Left, current node, Right)
  {
    if (r == NULL)
      return;
    /* first recur on left child */
    printInorder(r -> left);
    /* then print the data of node */
    cout << r -> val << " ";
    /* now recur on right child */
    printInorder(r -> right);
  }
  void printPostorder(TreeNode * r) //(Left, Right, Root)
  {
    if (r == NULL)
      return;
    // first recur on left subtree 
    printPostorder(r -> left);
    // then recur on right subtree 
    printPostorder(r -> right);
    // now deal with the node 
    cout << r -> val << " ";
  }

  TreeNode * iterativeSearch(int v) {
    if (root == NULL) {
      return root;
    } else {
      TreeNode * temp = root;
      while (temp != NULL) {
        if (v == temp -> val) {
          cout<<"Value is here presented !"<<endl;
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

  TreeNode * recursiveSearch(TreeNode * r, int val) {
    if (r == NULL || r -> val == val)
      return r;

    else if (val < r -> val)
      return recursiveSearch(r -> left, val);

    else
      return recursiveSearch(r -> right, val);
  }

int height(TreeNode *p) {
    int x;
    int y;
    if (p == nullptr){
        return 0;
    }
    x = height(p->left);
    y = height(p->right);
    return x > y ? x + 1 : y + 1;
}
 void order(TreeNode *r)
{
  while(r!=NULL){
    if(r==nullptr){return ;}
    else{cout<<r->val<<" ,";
    order(r->left);
    order(r->right);
}
break;
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

  TreeNode * minvalNode(TreeNode * node) {
    TreeNode * current = node;
    /* loop down to find the leftmost leaf */
    while (current -> left != NULL) {
      current = current -> left;
    }
    return current;
  }

  TreeNode * deleteNode(TreeNode * r, int v) {
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
    else if(r->val==v){
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
        // Delete the inorder successor 
        // r -> right = deleteNode(r -> right, temp -> val);
        r->right=deleteNode(r->right, temp->val); 
      }
    }
      // Update height
    r->height = height(r);
    if (BalanceFactor(r) == 2 && BalanceFactor(r->left) == 1) {  // L1 Rotation
    // Balance Factor and Rotation
        cout<<"So here we need rotaion for "<<r->val<<endl;
        return LLRotation(r);
    } else if (BalanceFactor(r) == 2 && BalanceFactor(r->left) == -1){  // L-1 Rotation
        
        cout<<"So here we need rotaion for "<<r->val<<endl;
        return LRRotation(r);
    } else if (BalanceFactor(r) == -2 && BalanceFactor(r->right) == -1){  // R-1 Rotation
        
        cout<<"So here we need rotaion for "<<r->val<<endl;
        return RRRotation(r);
    } else if (BalanceFactor(r) == -2 && BalanceFactor(r->right) == 1){  // R1 Rotation
        
        cout<<"So here we need rotaion for "<<r->val<<endl;
        return RLRotation(r);
    } else if (BalanceFactor(r) == 2 && BalanceFactor(r->left) == 0){  // L0 Rotation
        cout<<"So here we need rotaion for "<<r->val<<endl;
        return LLRotation(r);
    } else if (BalanceFactor(r) == -2 && BalanceFactor(r->right) == 0){  // R0 Rotation
        cout<<"So here we need rotaion for "<<r->val<<endl;
        return RRRotation(r);
    }
    return r;
  }

};

int main() {
  BST obj;
  int option, val;

  do {
    cout << "What operation do you want to perform? " <<
      " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Search Node" << endl;
    cout << "3. Delete Node" << endl;
    cout << "4. Print/Traversal BST vals" << endl;
    cout << "5. Height of Tree" << endl;
    cout << "6. Clear Screen" << endl;
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
	      obj.root= obj.insertRecursive(obj.root,new_node);
	      cout<<endl;
    		break;
      
    case 2:
      cout << "SEARCH" << endl;
      cout << "Enter val of TREE NODE to SEARCH in BST: ";
      cin >> val;
      //new_node = obj.iterativeSearch(val);
      new_node = obj.recursiveSearch(obj.root, val);
      if (new_node != NULL) {
        cout << "val found" << endl;
      } else {
        cout << "val NOT found" << endl;
      }
      break;
    case 3:
      cout << "DELETE" << endl;
      cout << "Enter val of TREE NODE to DELETE in BST: ";
      cin >> val;
      new_node = obj.iterativeSearch(val);
      if (new_node != NULL) {
        obj.root=obj.deleteNode(obj.root, val);
        cout << "val Deleted" << endl;
      } else {
        cout << "val NOT found" << endl;
      }
      break;
    case 4:
      cout << "PRINT 2D: " << endl;
      obj.print2D(obj.root, 5);
      cout << endl;
      cout << "Print Level Order BFS: \n";
      obj.order(obj.root);
      cout << endl;
      cout <<"PRE-ORDER: ";
      obj.printPreorder(obj.root);
      cout<<endl;
      cout <<"IN-ORDER: ";
      obj.printInorder(obj.root);
      cout<<endl;
      cout <<"POST-ORDER: ";
      obj.printPostorder(obj.root);
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

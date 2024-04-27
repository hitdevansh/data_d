#include <iostream>
using namespace std;
class node
{
public:
  int data;
  node *left = NULL;
  node *right = nullptr;
  int height;
};
node *root1 = nullptr;
int height(node *node1)
{
  //cout << "Height called ! " << endl;
  if (node1 == NULL)
    return 0;
  else
  {
    int left_side;
    int right_side;
    left_side = height(node1->left);
    right_side = height(node1->right);
    if (left_side > right_side)
    {
      return left_side + 1;
    }
    else
      return right_side + 1;
  }
}
   node* LRRotation(node *p) {
    node* pl = p->left;
    node* plr = pl->right;
 
    pl->right = plr->left;
    p->left = plr->right;
 
    plr->left = pl;
    plr->right = p;
 
    // Update height
    pl->height = height(pl);
    p->height = height(p);
    plr->height = height(plr);
 
    // Update root
    if (p == root1){
        root1 = plr;
    }
    return plr;
}
node* RLRotation(node *p) {
    node* pr = p->right;
    node* prl = pr->left;
 
    pr->left = prl->right;
    p->right = prl->left;
 
    prl->right = pr;
    prl->left = p;
 
    // Update height
    pr->height = height(pr);
    p->height = height(p);
    prl->height = height(prl);
 
    // Update root
    if (root1 == p){
        root1 = prl;
    }
    return prl;
}
  node* LLRotation(node *p) {
    cout<<"LL called"<<endl;
    node* pl = p->left;
    node* plr = pl->right;
 
    pl->right= p;
    p->left = plr;
 
    // Update height
     pl->height = height(pl);
    p->height = height(p);
     plr->height = height(plr);
 
    // Update root
    if (root1 == p){
        root1 = pl;
    }
    cout<<"return karu 6u"<<endl;
    return pl;
}
int bf(node *r)
{
  int x, y;
  x = height(r->left);
  y = height(r->right);
  return x - y;
}
node *rrrotation(node *r)
{
  node *pl = r->right;
  node *pll = pl->right;
  r->right = pl->left;
  pl->left = r;
  r->height = height(r);
  pl->height = height(pl);
  pll->height = height(pll);
  if (r == root1)
  {
    root1 = pl;
  }
  return pl;
}
node *insertRecursive(node *r, node *new_node)
{
  if (r == NULL)
  {
    r = new_node;
    r->height = 1;
    cout << "Insertion successful" << endl;
    return r;
  }

  else if (new_node->data < r->data)
  {
    r->left = insertRecursive(r->left, new_node);
  }
  else if (new_node->data > r->data)
  {
    r->right = insertRecursive(r->right, new_node);
  }
  else
  {
    cout << "No duplicate datas allowed!" << endl;
    return r;
  }
  r->height=height(r);
  cout<<r->height;
    if (bf(r) == 2 && bf(r->left) == 1) {
        cout<<"So here we need rotaion for "<<r->data<<endl;
        return LLRotation(r);
    } else if (bf(r) == 2 && bf(r->left) == -1){
        cout<<"So here we need rotaion for "<<r->data<<endl;
        return LRRotation(r);
    } else if (bf(r) == -2 && bf(r->right) == -1){
        cout<<"So here we need rotaion for "<<r->data<<endl;
        return rrrotation(r);
    } else if (bf(r) == -2 && bf(r->right) == 1){
        cout<<"So here we need rotaion for "<<r->data<<endl;
        return RLRotation(r);
    }
  return r;
}

// void printgivenLevel(node * r, int level) {
//   if (r == NULL)
//     return;
//   else if (level == 0)
//     cout << r -> data << " ";
//   else // level > 0
//   {
//     printgivenLevel(r -> left, level - 1);
//     printgivenLevel(r -> right, level - 1);
//   }
// }
// void printLevelOrderBFS(node * r) {
//   int h = height(r);
//   for (int i = 0; i <= h; i++)
//     printgivenLevel(r, i);
// }
void printgivenlevel(node *r, int level)
{
  // cout<<"given level called ! "<<endl;
  if (r == NULL)
    return;
  else if (level == 0)
  {
    // cout<<"output called ! "<<endl;
    cout << r->data << " ";
  }
  else // level > 0
  {    // cout<<"le"<<endl;
    printgivenlevel(r->left, level - 1);
    printgivenlevel(r->right, level - 1);
  }
}
void levelorder(node *root)
{ // cout<<"lo"<<endl;
  int p = height(root);
  // cout<<p;
  for (int i = 0; i <= p; i++)
  { // cout<<"lf"<<endl;
    printgivenlevel(root, i);
  }
}
node *mindata(node *r)
{
  node *temp = r;
  // temp->left=temp->right=nullptr;
  while (r->left != nullptr)
  {
    temp = r->left;
  }
  return temp;
}
node *deletee(node *r1, int data)
{
  //   int data;
  //   cout<<"Enter a data to delete a data "<<endl;
  if (r1 == nullptr)
  {
    return nullptr;
  }
  else if (data < r1->data)
  {
    r1->left = deletee(r1->left, data);
  }
  else if (data > r1->data)
  {
    r1->right = deletee(r1->right, data);
  }
  else
  {
    if (r1->right == nullptr)
    {
      node *t2 = r1->left;
      delete r1;
      return t2;
    }
    else if (r1->left == nullptr)
    {
      node *t2 = r1->right;
      delete r1;
      return t2;
    }
    else
    {
      node *t2 = mindata(r1->right);
      r1->data = t2->data;
      r1->right = deletee(r1->right, r1->data);
    }
  }
  return r1;
}
void print2D(node *r, int space)
{
  if (r == NULL)
    return;
  space += 10;
  print2D(r->right, space);
  cout << endl;
  for (int i = 10; i < space; i++)
    cout << " ";
  cout << r->data << "\n";
  print2D(r->left, space);
}

int main()
{
  int p;
  do
  {
    cin >> p;
    if (p == 1)
    {
      int data;
      cin >> data;
      node *new_node = new node;
      new_node->data = data;
      root1 = insertRecursive(root1, new_node);
      // cout<<root1->data<<endl;
    }
    /* code */
    else if (p == 2)
    {
      levelorder(root1);
    }
    else if (p == 3)
    {
      cout << "Enter a data delte" << endl;
      int data;
      cin >> data;
      root1 = deletee(root1, data);
    }
    else if (p == 4)
    {
      // cout<<"Enter a data delte"<<endl;
      // int data;
      // cin>>data;
      // root1=deletee(root1,data);
      print2D(root1, 10);
    }
    else
    {
      return 0;
    }
  } while (p != 0);
  return 0;
}

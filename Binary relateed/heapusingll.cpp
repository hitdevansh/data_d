#include <iostream>
using namespace std;
class queue;
class HeapNode;
class nodequeue
{
  public:
  HeapNode* data;
  nodequeue* next;
  nodequeue(HeapNode* v)
  {
      data=v;
      next=nullptr;
  }
  
};
class queue{
public:
nodequeue *front=nullptr;
nodequeue *rear=nullptr;
void enque(HeapNode* val);
void deque();
int empty();
HeapNode * front1(){return front->data;}
};
HeapNode * mainroot=NULL;
void queue:: enque(HeapNode* val)
{
    nodequeue* n=new nodequeue(val);
    if(front==nullptr)
    {
        front=rear=n;
        return;
    }
    rear->next=n;
    rear=n;
}

void queue:: deque()
{
    if(front==nullptr)
    {   rear=nullptr;
        cout<<"queue is empty ";
        return;
    }
    nodequeue* temp=front;
    front=front->next;
    delete(temp);
}

int queue:: empty()
{
    if(front==nullptr)
    return 1;
    return 0;
}

class HeapNode{
    public:
    int data;
    HeapNode* left;
    HeapNode* right;
    HeapNode* parent;
    HeapNode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

class Heap{
    public:
    HeapNode* root;
    Heap()
    {
        root = NULL;
    }
    HeapNode* lastparent()
    {
    queue q;
    q.enque(root);
    HeapNode* temp;
    while(!q.empty())
    {
        temp = q.front1();
        q.deque();
        if(temp->left && temp->right)
        {
            q.enque(temp->left);
            q.enque(temp->right);
        }
        else
        {
            break;
        }
    }
    return temp;
}
    void displaylevelorder()
{   cout<<"it is called "<<endl;
    if(root==NULL)
    return ;
    queue q;
    q.enque(root);
    while(!q.empty())
    {
        HeapNode *n=q.front->data;
        cout<<" "<<n->data<<"---";
        q.deque();
        if(n->left)
        {
            q.enque(n->left);
        }
         if(n->right)
        {
            q.enque(n->right);
        }  
    }
}
void print2D(HeapNode *r, int space)
{
    if (r == NULL) // Base case  1
        return;
    space =space + 10;            // Increase distance between levels   2
    print2D(r->right, space); // Process right child first 3
    cout << endl;
    for (int i = 10; i < space; i++) // 5
        cout << " ";                    // 5.1
    cout << r->data << "\n";            // 6
    print2D(r->left, space);          // Process left child  7
}
    void upHeapify(HeapNode* temp)
    {
        if(temp->parent == NULL)
        {
            return;
        }
        if(temp->parent->data < temp->data)
        {
            swap(temp->parent->data,temp->data);
            upHeapify(temp->parent);
        }
    }
    void add(int data)
    {
        HeapNode* newnode = new HeapNode(data);
        cout<<"Inserting: "<<data<<"\n";

        if(root == NULL)
        {
            root = newnode;
            return;
        }

        HeapNode* lpar = lastparent();

        if(lpar->left == NULL)
        {
            lpar->left = newnode;
            newnode->parent = lpar;
        }
        else
        {
            lpar->right = newnode;
            newnode->parent = lpar;
        }
        upHeapify(newnode);

    }

    void inorder(HeapNode* he)
    {
        if(he == NULL)
        {
            return;
        }
        inorder(he->left);
        cout<<he->data<<" ";
        inorder(he->right);
    }

    void print()
    {
        cout<<"Printing the data of the Heap: ";
        HeapNode* temp = root;
        inorder(temp);
        cout<<endl; 
    }
    bool isEmpty()
    {
        if(root == NULL)
        {
            return true;
        }
        else
        return false;
    }
    HeapNode* lastnode()
    {
        queue q;
        q.enque(root);
        HeapNode* last;
        while(!q.empty())
        {
            last = q.front1();
            q.deque();
            if(last->left)
            {
                q.enque(last->left);
            }
            if(last->right)
            {
                q.enque(last->right);
            }
        }

        return last;
    }

    void donwHeapify(HeapNode* he)
    {
        HeapNode* largest = he;

        if( he->left && he->left->data > largest->data)
        {
            largest = he->left;
        }

        if(he->right && he->right->data > largest->data)
        {
            largest = he->right;
        }

        if(largest != he)
        {
            swap(largest->data,he->data);
            donwHeapify(largest);
        }
    }

    void remove()
    {
        if(isEmpty())
        {
            cout<<"Heap is empty\n";
            return;
        }
        cout<<"Deleting: "<<root->data<<endl;
    

        HeapNode* last = lastnode();
        if(last == root)
        {
            delete last;
            root = NULL;
            return;
        }
        swap(root->data, last->data);
        HeapNode* pr = last->parent;

        if(pr->left == last)
        {
            delete last;
            pr->left = NULL;
        }
        else{
            delete last;
            pr->right = NULL;
        }

        donwHeapify(root);

    }

};
int main() {
    Heap h;
    int p=0;
    do
    {   cout<<endl<<"Enter a data to perform a "<<endl
    <<"Enter a data 1 to add "<<endl
    <<"Enter a data 2 to delete "<<endl
    <<"Enter a data 3 display level order"<<endl
    <<"Enter 0 to exit "<<endl;
        cin>>p;
        switch (p)
        {
        case 1:
            /* code */
            cout<<"Enter a data to add in this heap "<<endl;
            int  data;
            cin>>data;
            h.add(data);
            break;
        case 2:
            h.remove();
            break;

        case 3:
            h.displaylevelorder();
            break;
        case 4:
            h.print2D(h.root,10);
            break;

        case 0:
           return 0;
        default:
        cout<<"choose a proper value"<<endl;
            break;
        }
    
    
    } while (p!=0);
}
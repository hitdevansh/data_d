#include<iostream>
using namespace std;
class heapnodenode;
class nodequeue;
class queue;
class heapnode{
    public:
    int data;
    heapnode * right=nullptr;
    heapnode *left =nullptr;
    heapnode *parent=nullptr;
    // heap(){}
    heapnode(int val)
    {
        data =val;
        left=nullptr;
        right=nullptr;
        parent=nullptr;
    }
};
void swap(int &x,int &y){
    int temp=x;
    x=y;
    y=temp;
}
class nodequeue
{
    public:
    heapnode * data;
    nodequeue * next=nullptr;
    nodequeue(heapnode *v ){
        data=v;
        next=nullptr;
    }
};
class queue{
    public:
    nodequeue * front=nullptr;
    nodequeue * rear=nullptr;
    heapnode * front1(){return front->data;}
    void enque(heapnode * dt)
    {   nodequeue * n=new nodequeue(dt);
        if(front==nullptr){//rear=nullptr;
        front=rear=n;
        return ;}
        rear->next=n;
        rear=n;
    }
    void deque(){
    if(front==nullptr)
    {   rear=nullptr;
        cout<<"queue is empty ";
        return;
    }
    nodequeue* temp=front;
    front=front->next;
    delete(temp);}

    int empty()
    {
        if(front==nullptr){return 1;}
        return 0;
    }
};
class heap
{   public:
    heapnode *root;
    heap(){root=nullptr;}
    heapnode * heaplast()
    {
        queue q;
        q.enque(root);
        while(!q.empty())
        {
            heapnode * temp=q.front1();
            q.deque();
            if(temp->left && temp->right)
            {
                q.enque(temp->left);
                
                q.enque(temp->right);
            }
            else{
                return temp;
            }
        }
    }
    void levelorder()
    {
        if(root==nullptr){return ;}
        queue q;
         q.enque(root);
        while(!q.empty())
        {
            heapnode *n=q.front->data;
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
    void add(int data)
    {
        heapnode * nd=new heapnode(data);
        if(root==nullptr)
        {
            root=nd;
            return ;
        }
        heapnode * lpar=heaplast();
        if(lpar->left==nullptr)
        {
            lpar->left=nd;
            nd->parent=lpar;
        }
        else
        {
            lpar->right=nd;
            nd->parent=lpar;
        }
        upheap(nd);
    }
    void upheap(heapnode *temp)
    {
        if(temp->parent==nullptr){return ;}
        if(temp->parent->data < temp->data)
        {
            swap(temp->parent->data,temp->data);
            upheap(temp->parent);
        }
    }
};

int main()
{

return 0;
}
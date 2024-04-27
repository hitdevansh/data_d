// #include <iostream>
// using namespace std;
// class queue;
// class node;
// class nodequeue;
// class node
// {
// public:
//     int data;
//     bool color;
//     node *left;
//     node *right;
//     node(int data)
//     {
//         this->data = data;
//         color = 0;
//         left = right = nullptr;
//     }
// };
// class nodequeue
// {
// public:
//     node *data;
//     nodequeue *next;
//     nodequeue(node *v)
//     {
//         data = v;
//         next = nullptr;
//     }
// };
// class queue
// {
// public:
//     nodequeue *front = nullptr;
//     nodequeue *rear = nullptr;
//     void enque(node *val)
//     {
//         nodequeue *new_node=new nodequeue(val);
//         if(front==nullptr)
//         {front=rear=new_node;
//         return ;}
//         rear->=new_node;
//         rear=new_node;
//     }
//     void deque(){
//         if(front==nullptr)
//         {rear=nullptr;
//         cout<<"queue is empty "<<endl;
//         return ;}
//         nodequeue* temp=front;
//         front=front->next;
//         delete(temp);
//     }
//     int empty(){
//     if(front==nullptr)return 1;
//     return 0;}
// };
// node * insert(node * root,int data)
// {   cout<<"HII"<<endl;
//     if(root==0){root=new node(data);
//     cout<<" Inserted "<<root<<" index have "<<root->data<<endl;
//     return root;}
//     if(root->data<data){root->right=insert(root->right,data);}
//     else{root->left=insert(root->left,data);}
//     return root;
// }
// void displaylevel(node *root)
// {
//     cout<<"level order called! "<<endl;
//     if(root==nullptr){return ;}
//     queue q;
//     q.enque(root);
//     while (!q.empty())
//     {
//         /* code */
//         node *a=q.front->data;
//         cout<<a->data<<" "<<endl;
//         q.deque();
//         if(a->right){q.enque(a->right);}
//          if(a->left)
//          {
//             q.enque(a->left);
//         }
//     }
    
// }
// node * mainroot=nullptr;
// int height(node *root)
// {
//     int x;
//     int y;
//     if(root==nullptr){return 0;}
//     x=height(root->left);
//     y=height(root->right);
//     return x>y?x+1:y+1;}
// node * makeredblack(node *root,int data)
// {
//     if(root==nullptr){return nullptr;}
//     if(root && (root->data==data) && (root==mainroot))
//     { cout<<"a"<<endl;
//             mainroot->color=1;
//             return root;}
//     else if(((root->left && root->left->data==data) || (root->right && root->right->data==data)) && root==mainroot){
//     cout<<"b"<<endl;
//     return root;}

// }
// int main()
// {

//     return 0;
// }
#include<iostream>
using namespace  std;
int main(){}
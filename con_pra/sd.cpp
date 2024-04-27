//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
     struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        Node *prev=NULL;
        Node *curr=head;
        Node *agal=head->next;
        while(agal!=NULL)
        {
            curr->next=prev;
            prev=curr;
            curr=agal;
            agal=agal->next;

        }
        curr->next=prev;
        head=curr;
        return head;
    }
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head->next==NULL){return true;}
        Node *slow = head;
        Node * fast=head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
          slow=slow->next;
          fast=fast->next->next;
        }
        // cout<<slow->data<<endl;
        slow->next=reverseList(slow->next);
        Node * temp2=slow->next;
        Node * temp=head;
        while(temp2!=0){
          if(!(temp2->data==temp->data)){return false;}
          temp2=temp2->next;
          temp=temp->next;
        }
        slow->next=reverseList(slow->next);
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends
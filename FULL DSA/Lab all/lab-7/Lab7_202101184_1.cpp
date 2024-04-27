
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};

class linklist
{
	public:
	node *head=NULL;
	void inverse(node *&head);
	void apend(node *&head,int v);
	void display(node *&head);
	
};
void linklist :: inverse(node *&head)
	{	node *current=head;
		node *prev=NULL;
		node *next=NULL;
		while(current!=NULL){
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;}
		head=prev;
	}
void linklist :: apend(node *&head, int v)
{
    node *newdata = new node();
    newdata->data = v;
    if (head == NULL)
    {
        head = newdata;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newdata;
}


void linklist :: display(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{	linklist l1;
    while (1)
    {	
        int ch;
        cout <<endl<<"Enter your choice " << endl;
        cout << "Enter 1. for the insertion at the end of the linked list: - \n Enter 2. to reverse "<<endl <<" Enter 4. for the display the elements:-"
                  << "\n Enter 0. to quit the program:- " << endl;
        cin >> ch;
        if (ch == 0)
        {
            exit(0);
        }

        else if (ch == 1)
        {
            cout << endl
                 << "Enter your data to store at end " << endl;
            int end;
            cin >> end;
            l1.apend(l1.head, end);
        }
	else if(ch==2)
	{ l1.inverse(l1.head);}

        else if (ch == 4)
        {
            l1.display(l1.head);
        }

      
        else{cout<<"please enter a valid choice "<<endl;}
    }
    return 0;
}

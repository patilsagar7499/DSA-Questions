#include<iostream>
using namespace std;
class Node{
public:
 int data;
 Node* next;
 Node(int val)
 {
   this->data=val;
   this->next=NULL;
 }
};

 void insert(Node* &head,int val,int pos)
 {
    Node* n=new Node(val);
    if(pos==1)
    {
        n->next=head;
        head=n;
    }
    else{
        Node* temp=head;
        for(int i=1;i<pos-1;i++)
        {
           temp=temp->next;
        }
        n->next=temp->next;
        temp->next=n;
    }
 }

 void insertAtLast(Node* &head,int val)
 {
    Node* n=new Node(val);
    if(head==NULL)
    {
        head=n;
        n->next=NULL;
    }
    else
    {
        Node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
        n->next=NULL;

    }
 }
 void display(Node* head)
 {
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
 }
 
int main()
{
   
   Node* head =NULL;
   insertAtLast(head,1);
   display(head);
   insertAtLast(head,2);
   display(head);
   insertAtLast(head,3);
   display(head);
}


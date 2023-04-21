#include<iostream>
using namespace std;
class Node{
public:
 int data;
 Node* next,*prev;
 Node(int val)
 {
   this->data=val;
   this->next=NULL;
   this->prev=NULL;
 }
};
 void create(Node* &head,int val)
 {
    Node* n=new Node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
    n->next=NULL;
 }
 int deletee(Node* &head,int pos)
 {
    Node* temp=head;
    int x;
    if(pos==1)
    {
        head=head->next;
        head->prev=NULL;
        x=temp->data;
        delete temp;
        return x;
    }
    else{
        for(int i=1;i<pos;i++)
        {
            temp=temp->next;
        }
        temp->prev->next=temp->next;
        if(temp->next)
        temp->next->prev=temp->prev;
        x=temp->data;
        delete temp;
        return x;
    }
 }
 void reverse(Node* &head)
 {
    Node* temp=head;
    while(temp)
    {
        Node* x=temp->next;
        temp->next=temp->prev;
        temp->prev=x;
        temp=temp->prev;
        if(temp->next=NULL)
        head=temp;
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
 void insert(Node*& head,int pos,int val)
 {
    Node* n=new Node(val);
    Node* temp=head;
    if(pos==1)
    {
       n->next=head;
       n->prev=NULL;
       head->prev=n;
       head=n;
    }
    else
    {
        for(int i=1;i<pos-1;i++)
        {
            temp=temp->next;    
        }
        n->next=temp->next;
        n->prev=temp;
        if(temp->next)
        temp->next->prev=n;
        temp->next=n;
    }
 }
int main()
{
   
   Node* head =NULL;
   create(head,1);
   create(head,2);
   create(head,3);
   display(head);
   insert(head,1,10);
   display(head);
   insert(head,3,11);
   display(head);
   insert(head,6,12);
   display(head);
   cout<<deletee(head,1)<<endl;
   display(head);
   cout<<deletee(head,3)<<endl;
   display(head);
   reverse(head);
   display(head);
//    recdisplay(head);
//    revrecdisplay(head);
}

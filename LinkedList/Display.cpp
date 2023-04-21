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
    n->next=NULL;
 }
 void display(Node* head)
 {
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
 }
 void recdisplay(Node* head)
 {
    Node* temp=head;
    if(temp!=NULL)
    {
        cout<<temp->data<<"->";
        recdisplay(temp->next);
    }
    else
    cout<<"NULL"<<endl;
 }
 void revrecdisplay(Node* head)
 {
    Node* temp=head;
    if(temp==NULL)
    cout<<"NULL->";
    else if(temp!=NULL)
    {
        revrecdisplay(temp->next);
        cout<<temp->data<<"->";
    }
 } 
int main()
{
   
   Node* head =NULL;
   create(head,1);
   create(head,2);
   create(head,3);
   display(head);
//    recdisplay(head);
//    revrecdisplay(head);
}

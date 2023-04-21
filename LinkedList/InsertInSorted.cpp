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
        n->next=NULL;
        return;
    }
    else{
    Node* temp=head;
    while(temp->next!=NULL&&temp->next->data<n->data)
    {
        temp=temp->next;
    }
    n->next=temp->next;
    temp->next=n;
    }
     Node* temp=head;
     int count=0;
    while(temp->next!=NULL&&temp->next->data<head->data)
    {
        temp=temp->next;
        count++;
    }
    if(count>0){
    Node* x=head;
    head=head->next;
    x->next=temp->next;
    temp->next=x;}
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
 
int main()
{
   
   Node* head =NULL;
   create(head,10);
   create(head,5);
   create(head,2);
   create(head,9);
   create(head,7);
   display(head);
}

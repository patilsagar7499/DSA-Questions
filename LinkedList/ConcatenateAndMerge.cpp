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
 
};Node* third=NULL;

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
 void concate(Node* &head1,Node* &head2)
 {
    third=head1;
    while(head1->next!=NULL)
    {
       head1=head1->next; 
    }
    head1->next=head2;
 }
 void merge(Node* &head1,Node* &head2)
 {
   Node* last=NULL;
   if(head1->data<head2->data)
   {
      third=last=head1;
      head1=head1->next;
      third->next=NULL;
   }
   else{
      third=last=head2;
      head2=head2->next;
      third->next=NULL;
   }
   while(head1&&head2)
   {
      if(head1->data<head2->data)
      {
         last->next=head1;
         last=head1;
         head1=head1->next;
         last->next=NULL;
      }
      else{
         last->next=head2;
         last=head2;
         head2=head2->next;
         last->next=NULL;
      }
   }
  if(head1)last->next=head1;
   if(head2)last->next=head2;
   
   
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
   
   Node* head1 =NULL;
   create(head1,1);
   create(head1,3);
   create(head1,5);
   display(head1);
   Node* head2 =NULL;
   create(head2,2);
   create(head2,4);
   create(head2,6);
   display(head2);
   //concate(head1,head2);
   merge(head1,head2);
   display(third);
}

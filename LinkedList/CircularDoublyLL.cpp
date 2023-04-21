#include<iostream>
using namespace std;
class Node{
public:
 int data;
 Node* next;
 Node* prev;
 Node(int val)
 {
   this->data=val;
   this->next=this;
 }
};
 void create(Node* &head,int val)
 {
    Node* n=new Node(val);
    if(head==NULL)
    {
        head=n;
        n->next=n;
        return;
    }
    Node* temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
    n->next=head;

 }
 void deletee(Node* &head,int pos)
 {
    Node* temp=head;
    if(pos==1)
    {
      //  while(temp->next!=head)
      //   temp=temp->next;
      //  int x=head->data;
      //   if(head==temp)
      //   {
      //       delete head;
      //       head=NULL;
      //   }
      //   else{
      //   temp->next=head->next;
      //   delete head;
      //   head=temp->next;
      //   head->prev=temp;}
      temp->prev->next=temp->next;
      temp->next->prev=temp->prev;
      head=temp->next;
      delete temp;
        return;
    }
    int count=1;
    while(count!=pos-1)
    {
        temp=temp->next;
        count++;
    }
    Node* q=temp->next;
    temp->next=temp->next->next;
    temp->next->next->prev=temp;
    delete q;
    return;
 }
 void display(Node* head)
 {
    Node* temp=head;
    do
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;
    return;
 }
 void insert(Node* &head,int pos,int val)
 {
    Node* n=new Node(val);
    Node* temp=head;
    if(pos==1)
    {
      do{
        temp=temp->next;
      }while(temp->next!=head);
      temp->next=n;
      n->prev=temp;
      n->next=head;
      head=temp->next;
      return;
    }
    int count=1;
    do{
        temp=temp->next;
        count++;
      }while(temp!=head&&count!=pos-1);
      n->next=temp->next;
      temp->next=n;
      n->prev=temp;
    return;
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
   deletee(head,1);
   display(head);
   deletee(head,3);
   display(head);
}

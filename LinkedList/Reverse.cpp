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
 void reverse1(Node*& head,int x)
 {
    int A[x],i=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        A[i]=temp->data;
        temp=temp->next;
        i++;
    }
    temp=head;
    i--;
    while(temp!=NULL)
    {
        temp->data=A[i--];
        temp=temp->next;
    }

 }
 void reverse2(Node* &head)
 {
    Node* p=head;
    Node* q=NULL;
    Node* r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    head=q;
 }
 void reverse3(Node* &head,Node* q,Node* p)
 {
    if(p!=NULL)
    {
        reverse3(head,p,p->next);
        p->next=q;
    }
    else{
        head=q;
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
   create(head,1);
   create(head,2);
   create(head,3);
   display(head);
   //reverse1(head,3);
   //reverse2(head);
   reverse3(head,NULL,head);
   display(head);
}

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
 void createloop(Node* head,int pos)
 {
     Node* p,*q;
     Node* temp=head;int count=1,count1=1;
     while(temp->next!=NULL)
     {
         temp=temp->next;
         count1++;
     }
     temp=head;
     while(temp->next!=NULL&&count<pos)
     {temp=temp->next;
     count++;}
     p=temp;
     if(count==count1)return;
     temp=head;
     while(temp->next!=NULL)
     temp=temp->next;
     temp->next=p;
 }
 int checkloop(Node* head)
 {
    Node *p,*q=head;
    do{
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p && q&& p!=q);
    if(p==q)return 1;
    else return 0;
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

   createloop(head,2);
   //display(head);
   cout<<checkloop(head);

   
}

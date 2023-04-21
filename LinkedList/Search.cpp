#include<iostream>
#include<climits>
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
    cout<<"NULL"<<endl;
 }
 int search(Node* head,int val)
 {
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==val)
        return 1;
        temp=temp->next;
    }
    return 0;
 }
 int recsearch(Node* head,int val)
 {
    Node* temp=head;
    if(temp==NULL)
    return 0;
    else
    {
        if(head->data!=val)
        recsearch(head->next,val);
        else
        return 1;
    }
 }
 int impsearch(Node* &head,int val)
 {
    Node* first=NULL;
    first->next=head;
    Node* q=NULL;
    while(head!=NULL)
    {
        if(val==head->data)
        {
            q->next=head->next;
            head->next=first;
            first=head;
            return 1;
        }
        q=head;
        head=head->next;

    }
    return 0;
 }
 int main()
{
   
   Node* head =NULL;
   create(head,1);
   create(head,2);
   create(head,3);
   create(head,4);
   //cout<<search(head,11);
   //cout<<recsearch(head,2);
   display(head);
   cout<<impsearch(head,1);
   cout<<endl;
   display(head);
}
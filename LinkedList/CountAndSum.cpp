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
 void count(Node* head)
 {
    Node* temp=head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    cout<<"Count:"<<count<<endl;
 }
 int reccount(Node* head)
 {
    if(head==NULL)
    return 0;
    else{
        return reccount(head->next)+1;
    }
 }
 void sum(Node* head)
 {
    Node* temp=head;
    int sum=0;
    while(temp!=NULL)
    {
        sum+=temp->data;
        temp=temp->next;
    }
    cout<<"Sum:"<<sum<<endl;
 }
 int recsum(Node *head)
 {
    if(head==NULL)
    return 0;
    else
    return recsum(head->next)+head->data;
 }
 int main()
{
   
   Node* head =NULL;
   create(head,1);
   create(head,2);
   create(head,3);
   create(head,4);
   //count(head);
   cout<<"Count:"<<reccount(head)<<endl;
   cout<<"Sum:"<<recsum(head)<<endl;
   //sum(head);
   //display(head);
}
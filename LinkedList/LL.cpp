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
 void deletee(Node* &head,int pos)
 {
    Node* temp=head;
    if(pos==1)
    {
        temp=temp->next;
        delete head;
        head=temp;
    }
    else{
        int x=1;
        while(x!=pos-1)
        {
            temp=temp->next;
            x++;
        }

        temp->next=temp->next->next;}
    }
 int length(Node* head)
 {
    Node* temp=head;
    int count=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    return count;
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
   cout<<"Length:"<<length(head)<<endl;
   deletee(head,1);
   display(head);
   cout<<"Length:"<<length(head);
}

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
 void middle1(Node* head)
 {
    Node *temp1=head,*temp2=head;
    while (temp2)
    {
        temp2=temp2->next;
        if(temp2)temp2=temp2->next;
        if(temp2)temp1=temp1->next;
    }
    cout<<temp1->data<<endl;    
 }
 void middle2(Node* head)
 {
    Node* temp=head;
    int count=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    int x=count/2;
    temp=head;
    int y=0;
    while(y!=x)
    {
        temp=temp->next;
        y++;
    }
    cout<<temp->data<<endl;
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
   middle1(head);
   middle2(head);
//    recdisplay(head);
//    revrecdisplay(head);
}

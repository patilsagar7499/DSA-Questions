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
 void duplicate(Node* head)
 {
    Node* temp=head->next;
    while(temp!=NULL)
        {
            if(head->data!=temp->data)
            {
                head=temp;
                temp=temp->next;
            }
            else{
                head->next=temp->next;
                delete temp;
                temp=head->next;
                
            }
            
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
   create(head,3);
   create(head,5);
   create(head,5);
   create(head,5);
   create(head,6);
   create(head,6);
   display(head);
   duplicate(head);
   display(head);
  
}
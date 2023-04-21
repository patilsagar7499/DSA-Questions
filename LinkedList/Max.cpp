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
    cout<<"NULL";
 }
 void maxi(Node* head)
 {
    int maxi=-1;
    while(head!=NULL)
    {
        maxi=max(maxi,head->data);
        head=head->next;
    }
    cout<<"Max:"<<maxi<<endl;
 }
 int recmaxi(Node* head)
 {
    int maxi=INT_MIN;

    if(head==NULL)
    return INT_MIN;

    maxi=recmaxi(head->next);
    
    return maxi>head->data?maxi:head->data;
    
 }
 int main()
{
   
   Node* head =NULL;
   create(head,1);
   create(head,2);
   create(head,3);
   create(head,4);
   //maxi(head);
   cout<<recmaxi(head);
}
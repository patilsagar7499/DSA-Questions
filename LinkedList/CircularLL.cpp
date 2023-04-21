#include<iostream>
using namespace std;
class Node{
public:
 int data;
 Node* next;
};
class CLL{
Node *head;
public:
 void create(int *A,int n)
 {
    Node* t;
    Node* tail;
 
    head = new Node;
 
    head->data = A[0];
    head->next = head;
    tail = head;
 
    for (int i=1; i<n; i++){
        t = new Node;
        t->data = A[i];
        t->next = tail->next;
        tail->next = t;
        tail = t;
    }
 }
 void insert(int pos,int val)
 {
    Node* temp,*p;
    int i;
    if(pos==1)
    {
        temp=new Node;
        temp->data=val;
        if(head==NULL)
        {
            head=temp;
            head->next=head;
        }
        else
        {
            p=head;
            while(p->next!=head)p=p->next;
            p->next=temp;
            temp->next=head;
            head=temp;
        }
    }
    else{
        p=head;
        for(int i=1;i<pos-1;i++)
        p=p->next;
        temp=new Node;
        temp->data=val;
        temp->next=p->next;
        p->next=temp;
    }
 }
 int deletee(int pos)
 {
      Node* temp=head;
      Node* q;
      int x;
      if(pos==1)
      {
        while(temp->next!=head)
        temp=temp->next;
        x=head->data;
        if(head==temp)
        {
            delete head;
            head=NULL;
        }
        else{
        temp->next=head->next;
        delete head;
        head=temp->next;}
      }
      else{
      for(int i=0;i<pos-2;i++)
      {
         temp=temp->next;
      }
      q=temp->next;
      temp->next=q->next;
      x=q->data;
      delete q;
      }
    return x;
 }
 void display()
 {
    Node* p = head;
    do {
        cout << p->data << " -> " << flush;
        p = p->next;
    } while (p != head);
    cout << endl;
 }
};

int main()
{
   CLL c;
   int A[] = {1, 3, 5, 7, 9};
   c.create(A,sizeof(A)/sizeof(A[0]));
   c.display();
   c.insert(1,10);
   c.display();
   c.insert(3,11);
   c.display();
   cout<<c.deletee(1)<<endl;
   c.display();
   cout<<c.deletee(3)<<endl;
   c.display();

}

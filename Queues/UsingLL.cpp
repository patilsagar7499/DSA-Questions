#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    Node(int data)
    {
       this->data=data;
       this->next=NULL;
    }
};
void enqueue(Node* &front,Node* &rear,int x)
    {
        Node* t =new Node(x);
        if(t==NULL)
        cout<<"Queue is full!";
        else{
            if(front==NULL)
            front=rear=t;
            else
            {
                rear->next=t;
                rear=t;
            }
        }
    }
int  dequeue(Node * &front)
{
    int x=-1;
    Node* temp;
    if(front==NULL)
    cout<<"Queue is Empty!";
    else{
        temp=front;
        front=front->next;
        x=temp->data;
        delete temp;
    }
    return x;
}
void display(Node* front)
{
    Node* temp=front;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
  cout<<"NULL"<<endl;
}
int main()
{
    Node* front=NULL;
    Node* rear=NULL;
    enqueue(front,rear,1);
    enqueue(front,rear,2);
    enqueue(front,rear,3);
    display(front);
    cout<<"Deleted:"<<dequeue(front)<<endl;
    display(front);
    cout<<"Deleted:"<<dequeue(front)<<endl;
    display(front);
    cout<<"Deleted:"<<dequeue(front)<<endl;
    display(front);
    cout<<dequeue(front)<<endl;
    return 0;
}

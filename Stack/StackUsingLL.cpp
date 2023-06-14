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
    void push(Node* &top,int val)
    {
        Node* t=new Node(val);
        if(t==NULL)
          cout<<"Stack Overflow";
        else
        {
            t->next=top;
            top=t;
        }
    }
    int pop(Node* &top)
    {
        int x;
        if(top==NULL)
        cout<<"Stack is empty";
        else
        {
            Node* t=top;
            top=top->next;
            x=t->data;
            delete t;
        }
        return x;
    }
    int peek(Node* top,int pos)
    {
        Node* temp=top;
        int count=0;
        while(count<pos-1&&temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        if(temp==NULL)
         return -1;
        else
         return temp->data;
    }
    int stacktop(Node* top)
    {
        if(top)
        return top->data;
        return -1;
    }
    int isempty(Node* top)
    {
        return top?0:1;
    }
    int isfull(Node* top)
    {
        Node* t;
        int r=t?1:0;
        delete (t);
        return r;
    }
    void display(Node* top)
    {
        Node* temp=top;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }

    }
int main()
{
    Node* top=NULL;
    push(top,1);
    push(top,2);
    push(top,3);
    cout<<endl<<peek(top,2)<<endl;
    display(top);
    cout<<endl<<pop(top)<<endl;
    display(top);
    cout<<endl<<peek(top,3)<<endl;
    cout<<"Top:"<<stacktop(top)<<endl;
    cout<<"Empty:"<<isempty(top)<<endl;
    cout<<"Full:"<<isfull(top)<<endl;
   return 0;
}

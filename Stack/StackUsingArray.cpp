#include<iostream>
using namespace std;
class Stack
{
public:
int top;
int size;
int *s;
Stack(int size)
{
    this->size=size;
    this->top=-1;
    this->s=new int[size];
}
~Stack()
{
    delete[] s;
}
int isFull()
{
    if(top==size-1)
    return 1;
    return 0;
}
int isEmpty()
{
    if(top==-1)
    return 1;
    return 0;
}
void push(int x)
{
    if(isFull())
    cout<<"Stack Overflow!"<<endl;
    else{
        top++;
        s[top]=x;
    }
}
int pop()
{
    if(isEmpty())
    cout<<"Stack Underflow!";
    else
    {
        int x=s[top];
        top--;
        return x;
    }
}
void peek(int index)
{
    int x=-1;
    if(top-index+1<0||top-index+1==size)
    cout<<"Invalid Position!"<<endl;
    else
    {
        x=s[top-index+1];
        cout<<x<<endl;
    }
    
}
void display()
{
    for(int i=top;i>=0;i--)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
};
int main()
{
   
   Stack s(4);
   for(int i=1;i<=4;i++)
   {s.push(i);}
   s.display();
   cout<<"Peek:";
   s.peek(2);
   s.display();
   s.push(4);
   s.display();
   cout<<s.pop()<<endl;
   s.display();
   cout<<s.pop()<<endl;
   s.display();
   cout<<s.pop()<<endl;
   s.display(); 
   s.pop();
}

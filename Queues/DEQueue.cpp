#include<iostream>
using namespace std;
class Queue{
    public:
    int size;
    int front;
    int rear;
    int *Q;
Queue(int size)
{
    this->size=size;
    this->front=-1;
    this->rear=-1;
    this->Q=new int[size];
}
~Queue()
{
    delete[] Q;
}
void enqueuerear(int x)
{
    if(rear==size-1)
    cout<<"Queue is Full";
    else
    {
        rear++;
        Q[rear]=x;
    }
}
void enqueuefront(int x)
{
    if(front==-1)
    cout<<"Queue is Full";
    else
    {
        Q[front]=x;
        front--;
    }
}
int dequeuefront()
{
    int x=-1;
    if(front==rear)
    cout<<"Queue is Empty";
    else{
        front++;
        x=Q[front];
    }
    return x;
}
int dequeuerear()
{
    int x=-1;
    if(rear==-1)
    cout<<"Queue is Empty";
    else{
        x=Q[rear];
        rear--;
    }
    return x;
}
void display()
{
    for(int i=front+1;i<=rear;i++)
    cout<<Q[i]<<" ";
}
};
int main()
{
    int x;
   cout<<"Enter size:";
   cin>>x;
   Queue q(x);
   q.enqueuerear(10);
    q.enqueuerear(20);
   q.display();
   cout<<"Deleted->"<<q.dequeuefront()<<endl;
   q.enqueuefront(30);
   q.display();
   cout<<"Deleted->"<<q.dequeuerear()<<endl;
   q.display();
   cout<<"Deleted->"<<q.dequeuefront()<<endl;
   q.display();
   return 0;
}

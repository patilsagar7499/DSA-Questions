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
void enqueue(int x)
{
    if(rear==size-1)
    cout<<"Queue is Full";
    else
    {
        rear++;
        Q[rear]=x;
    }
}
int dequeue()
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
   q.enqueue(10);
   q.enqueue(20);
   q.enqueue(30);
   q.display();
   cout<<"Deleted->"<<q.dequeue()<<endl;
   q.display();
   cout<<"Deleted->"<<q.dequeue()<<endl;
   q.display();
   return 0;
}

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
    if((rear+1)%size==front)
    cout<<"Queue is Full";
    else
    {
        rear=(rear+1)%size;
        Q[rear]=x;
    }
}
int dequeue()
{
    int x=-1;
    if(front==rear)
    cout<<"Queue is Empty";
    else{
        front=(front+1)%size;
        x=Q[front];
    }
    return x;
}
void display()
{
    int i=front+1;
    do{
    cout<<Q[i]<<" ";
    if(i<rear)
    cout<<"<-";
    i=(i+1)%size;
    }while(i!=(rear+1)%size);
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
   cout<<"Deleted->"<<q.dequeue()<<endl;
   q.display();
   q.enqueue(40);
   q.display();
   q.enqueue(50);
   q.enqueue(60);
   q.display();
   cout<<"Deleted->"<<q.dequeue()<<endl;
   q.display();
   return 0;
}

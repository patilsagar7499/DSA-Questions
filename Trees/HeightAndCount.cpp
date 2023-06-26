#include<iostream>
using namespace std;
class Node{
    public:
    Node* lchild;
    int data;
    Node* rchild;
};
class Queue{
    public:
    int size;
    int front;
    int rear;
    Node **Q;
Queue(int size)
{
    this->size=size;
    this->front=-1;
    this->rear=-1;
    this->Q=new Node*[size];
}
~Queue()
{
    delete[] Q;
}
int isempty()
{
    return front==rear;
}
void enqueue(Node* x)
{
    if(rear==size-1)
    cout<<"Queue is Full";
    else
    {
        rear++;
        Q[rear]=x;
    }
}
Node* dequeue()
{
    Node* x=NULL;
    if(front==rear)
    cout<<"Queue is Empty";
    else{
        x=Q[front+1];
        front++;
    }
    return x;
}
};
class Tree{
    
    public:
    Node* root;
    Tree()
    {
        root=NULL;
    }
    void createTree()
    {
        Node *p,*t;
        int x;
        Queue q(100);
        cout<<"Enter root value:";
        cin>>x;
        root=new Node;
        root->data=x;
        root->lchild=root->rchild=NULL;
        q.enqueue(root);
        while(!q.isempty())
        {
            p=q.dequeue();
            cout<<"Enter left child of "<<p->data<<":";
            cin>>x;
            if(x!=-1)
            {
                t=new Node;
                t->data=x;
                t->lchild=t->rchild=NULL;
                p->lchild=t;
                q.enqueue(t);
            }
            cout<<"Enter right child of "<<p->data<<":";
            cin>>x;
            if(x!=-1)
            {
                t=new Node;
                t->data=x;
                t->lchild=t->rchild=NULL;
                p->rchild=t;
                q.enqueue(t);
            }
        }
    }
    
   
    int Height(Node* root)
    {
        int x=0,y=0;
        if(root==0)
        return 0;
        x=Height(root->lchild);
        y=Height(root->rchild);
        if(x>y)
        return x+1;
        else
        return y+1;
    }
    int count(Node* root)
    {
        int x,y;
        if(root!=NULL)
        {
            x=count(root->lchild);
            y=count(root->rchild);
            return x+y+1;
        }
        return 0;
    }
};
int main()
{
    Tree t;
    t.createTree();
    cout<<"Height:"<<t.Height(t.root)<<endl;
    cout<<"Count:"<<t.count(t.root)<<endl;
   return 0;
}

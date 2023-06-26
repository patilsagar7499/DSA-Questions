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
    void Preorder(Node* p)
    {
        if(p)
        {
            cout<<p->data<<" ";
            Preorder(p->lchild);
            Preorder(p->rchild);
        }
    }
    void inorder(Node* p)
    {
        if(p)
        {
            inorder(p->lchild);
            cout<<p->data<<" ";
            inorder(p->rchild);
        }
    }
    void Postorder(Node* p)
    {
        if(p)
        {
            Preorder(p->lchild);
            Preorder(p->rchild);
            cout<<p->data<<" ";
        }
    }
    void Levelorder(Node* p)
    {
        Queue q(100);
        cout<<root->data<<" ";
        q.enqueue(root);
        while(!q.isempty())
        {
            root=q.dequeue();
            if(root->lchild)
            {
                cout<<root->lchild->data<<" ";
                q.enqueue(root->lchild);
            }
            if(root->rchild)
            {
                cout<<root->rchild->data<<" ";
                q.enqueue(root->rchild);
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
};
int main()
{
    Tree t;
    t.createTree();
    cout<<"Preorder:";
    t.Preorder(t.root);
     cout<<endl<<"Inorder:";
    t.inorder(t.root);
     cout<<endl<<"Postorder:";
    t.Postorder(t.root);
    cout<<endl<<"Levelorder:";
    t.Levelorder(t.root);
    cout<<endl<<"Height:"<<t.Height(t.root);
   return 0;
}

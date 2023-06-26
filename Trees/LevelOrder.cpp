#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class Node{
    public:
    Node* lchild;
    int data;
    Node* rchild;
};
class Tree{
    public:
    Node* root;
    Tree()
    {root=NULL;}
    void CreateTree()
    {
        Node*p,*t;
        int x;
        queue<Node*>q;
        root=new Node;
        cout<<"Enter root data:";
        cin>>x;
        root->data=x;
        root->lchild=NULL;
        root->rchild=NULL;
        q.emplace(root);
        while(!q.empty())
        {
            p=q.front();
            q.pop();
            cout<<"Enter left child data of "<<p->data<<":";
            cin>>x;
            if(x!=-1)
            {
                t=new Node;
                t->data=x;
                t->lchild=NULL;
                t->rchild=NULL;
                p->lchild=t;
                q.emplace(t);
            }
            cout<<"Enter right child data of "<<p->data<<":";
            cin>>x;
            if(x!=-1)
            {
                t=new Node;
                t->data=x;
                t->lchild=NULL;
                t->rchild=NULL;
                p->rchild=t;
                q.emplace(t);
            }
        }
    }
    void LevelOrder(Node* p)
    {
        queue<Node*> q;
        cout<<p->data<<" ";
        q.emplace(p);
        while(!q.empty())
        {
            p=q.front();
            q.pop();
            if(p->lchild)
            {
                cout<<p->lchild->data<<" ";
                q.emplace(p->lchild);
            }
            if(p->rchild)
            {
                cout<<p->rchild->data<<" ";
                q.emplace(p->rchild);
            }
        }

       
    }
};
int main()
{Tree t;
t.CreateTree();
cout<<"Levelorder:";
t.LevelOrder(t.root);
   return 0;
}

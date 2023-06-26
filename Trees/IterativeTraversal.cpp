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
    void iterativePreorder(Node* p)
    {
        stack<Node*> stk;
        while(p!=NULL|| !stk.empty())
        {
            if(p!=NULL)
            {
                cout<<p->data<<",";
                stk.emplace(p);
                p=p->lchild;
            }
            else{
                p=stk.top();
                stk.pop();
                p=p->rchild;
            }
        }
        cout<<endl;
    }
    void iterativeInorder(Node* p)
    {
        stack<Node*> stk;
        while(p!=NULL||!stk.empty())
        {
            if(p!=NULL)
            {

                stk.emplace(p);
                p=p->lchild;
            }
            else{
                p=stk.top();
                stk.pop();
                cout<<p->data<<",";
                p=p->rchild;
            }
        }
        cout<<endl;
    }
    void iterativePostorder(Node* p)
    {
        stack<long int> stk;
        long int temp;
        while(p!=NULL||!stk.empty())
        {
            if(p!=NULL)
            {

                stk.emplace((long int)p);
                p=p->lchild;
            }
            else{
               temp=stk.top();
               stk.pop();
               if(temp>0)
               {
                stk.emplace(-temp);
                p=((Node*)temp)->rchild;
               }
               else{
                cout<<((Node*)(-1*temp))->data<<",";
                p=NULL;
               }
            }
        }
        cout<<endl;
    }
};
int main()
{Tree t;
t.CreateTree();
cout<<"Preorder:";
t.iterativePreorder(t.root);
cout<<"Inorder:";
t.iterativeInorder(t.root);
cout<<"Postorder:";
t.iterativePostorder(t.root);
   return 0;
}

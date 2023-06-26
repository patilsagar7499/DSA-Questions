#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class Node{
    public:
    Node* lchild;
    int data;
    Node* rchild;
    Node(){}
    Node(int data)
    {
        lchild=NULL;
        this->data=data;
        rchild=NULL;
    }
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
    int searchInorder(int inArray[],int inStart,int inEnd,int data)
    {
        for(int i=inStart;i<=inEnd;i++)
        {
            if(inArray[i]==data)
            return i;
        }
        return -1;
    }
    Node* generateFromTraversal(int *inorder,int *preorder,int inStart,int inEnd)
    {
        static int preIndex=0;
        if(inStart>inEnd)
        return NULL;
        Node* node=new Node(preorder[preIndex++]);
        if(inStart==inEnd)
        return node;
        int splitIndex=searchInorder(inorder,inStart,inEnd,node->data);
        node->lchild=generateFromTraversal(inorder,preorder,inStart,splitIndex-1);
        node->rchild=generateFromTraversal(inorder,preorder,splitIndex+1,inEnd);
        return node;
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
    
};
int main()
{Tree t;
int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};
Node* T=t.generateFromTraversal(inorder,preorder,0,sizeof(inorder)/sizeof(inorder[0])-1);
t.Preorder(T);
   return 0;
}

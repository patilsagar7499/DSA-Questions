#include<iostream>
#include<stack>
using namespace std;
class Node{
  public:
    Node* lchild;
    int data;
    Node* rchild;
};
class BST{
    
  public:
 
   void Create(Node* &head,int *pre,int n)
    {
        int i=0;
        Node* x=new Node;
        x->data=pre[i++];
        x->lchild=x->rchild=NULL;
        head=x;

        Node* t;
        Node* p=head;
        stack<Node*>stk;

        while(i<n)
        {
            if(pre[i]<p->data)
            {
                t=new Node;
                t->data=pre[i++];
                t->lchild=t->rchild=NULL;
                p->lchild=t;
                stk.push(p);
                p=t;
            }
            else{
                if(pre[i]>p->data&&pre[i]<stk.empty()?32767:stk.top()->data)
                {
                   t=new Node;
                   t->data=pre[i++];
                   t->lchild=t->rchild=NULL;
                   p->rchild=t;
                   p=t;
                }
                else
                {
                    p=stk.top();
                    stk.pop();
                }
            }
        }
    }
    
  void Inorder(Node* head)
  { 
    Node* p=head;
    if(p)
    {
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
  }
};
int main()
{
    Node* head=new Node;
    int pre[]={1,9,2,8,3,7,4,6,5};
    int n=sizeof(pre)/sizeof(pre[0]);
    BST b;
    b.Create(head,pre,n);
    b.Inorder(head);
   return 0;
}

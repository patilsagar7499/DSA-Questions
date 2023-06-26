#include<iostream>
using namespace std;
class Node{
 public:
 Node* lchild;
 int data;
 Node* rchild;
};
class BST
{
 Node* root;
public:
  BST(){root=NULL;}
  Node* getRoot(){return root;}
  void Insert(int key)
  {
     Node* t=root;
    Node* r,*p;
    if(t==NULL)
    {p=new Node;
    p->data=key;
    p->lchild=p->rchild=NULL;
    root=p;
    return;
    }
    
    while(t!=NULL)
    {
        r=t;
        if(key==t->data)
        return;
        else if(key<t->data)
        t=t->lchild;
        else
        t=t->rchild;
    }
    p=new Node;
    p->data=key;
    p->lchild=p->rchild=NULL;
    if(p->data<r->data)
    r->lchild=p;
    else
    r->rchild=p;
  }
  void Inorder(Node *p)
  {
    if(p!=NULL)
    {
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }

  }
};
int main()
{

   BST b;
   b.Insert(2);
   b.Insert(1);
   b.Insert(3);
   b.Inorder(b.getRoot());
   return 0;
}

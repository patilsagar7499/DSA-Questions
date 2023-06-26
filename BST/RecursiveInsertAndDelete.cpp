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
  Node* RecInsert(Node* p,int key)
  {
     Node* t;
     if(p==NULL)
     {
        t=new Node;
        t->data=key;
        t->lchild=t->rchild=NULL;
        root=t;
        return t;
     }
     if(key<p->data)
     p->lchild=RecInsert(p->lchild,key);
     else if(key>p->data)
     p->rchild=RecInsert(p->rchild,key);
     root=t;
     return p;
  }
  int Height(Node* p)
  {
    int x,y;
    if(p==NULL)
    return 0;
    x=Height(p->lchild);
    y=Height(p->rchild);
    return x>y?x+1:y+1;
  }
  Node* InPre(Node* p)
  {
    while ((p&&p->rchild!=NULL))
    {
        p=p->rchild;
    }
    return p;    
  }
  Node* InSucc(Node* p)
  {
    while ((p&&p->lchild!=NULL))
    {
        p=p->lchild;
    }
    return p;    
  }
  Node* Delete(Node* p,int key)
  {
    Node* q;
    if(p==NULL)
    return NULL;
    if(p->lchild==NULL&&p->rchild==NULL)
    {
        if(p==root)
        return NULL;
        delete p;
        return NULL;
    }
    if(key<p->data)
    p->lchild=Delete(p->lchild,key);
    else if(key>p->data)
    p->rchild=Delete(p->rchild,key);
    else{
        if(Height(p->lchild)>Height(p->rchild))
        {
            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=InPre(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);   
        }
    }
    return p;
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
   b.RecInsert(b.getRoot(),50);
   b.RecInsert(b.getRoot(),70);
   b.RecInsert(b.getRoot(),1);
   b.Inorder(b.getRoot());
   cout<<endl;
   b.Delete(b.getRoot(),70);
   b.Inorder(b.getRoot());
   return 0;
}

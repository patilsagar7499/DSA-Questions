#include<iostream>
using namespace std;
class Node{
    public:
    Node* lchild;
    int data;
    Node* rchild;
    int height;
};
class AVL{
public:
Node* root;
AVL(){root=NULL;}
int NodeHeight(Node* p)
{
    int hl,hr;
    hl=(p&&p->lchild)?p->lchild->height:0;
    hr=(p&&p->rchild)?p->rchild->height:0;
    return hl>hr?hl+1:hr+1;
}
int BalanceFactor(Node* p)
{
    int hl,hr;
    hl=(p&&p->lchild)?p->lchild->height:0;
    hr=(p&&p->rchild)?p->rchild->height:0;
    return hl-hr;
}
Node* LLRotation(Node* p)
{
    Node* pl=p->lchild;
    Node* plr=pl->rchild;

    pl->rchild=p;
    p->lchild=plr;

    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);

    if(root==p)
    root=pl;

    return pl;
}
Node* RRRotation(Node* p)
{
    Node* pr=p->rchild;
    Node* prl=pr->lchild;

    pr->lchild=p;
    p->rchild=prl;

    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);

    if(root==p)
    root=pr;

    return pr;
}
Node* LRRotation(Node *p) {
    Node* pl=p->lchild;
    Node* plr=pl->rchild;

    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;

    plr->lchild=pl;
    plr->rchild=p;

    pl->height=NodeHeight(pl);
    p->height=NodeHeight(p);
    plr->height=NodeHeight(plr);

    if(root==p)
    root=plr;
    return plr;
}
 
Node* RLRotation(Node *p) {
    Node* pr=p->rchild;
    Node* prl=pr->lchild;

    pr->lchild=prl->rchild;
    p->rchild=prl->lchild;

    prl->rchild=pr;
    prl->lchild=p;

    pr->height=NodeHeight(pr);
    p->height=NodeHeight(p);
    prl->height=NodeHeight(prl);

    if(root==p)
    root=prl;
    return prl;
}
Node* InPre(Node* p)
{
    while(p&&p->rchild!=NULL)
    p=p->rchild;
}
Node* InSucc(Node* p)
{
    while(p&&p->lchild!=NULL)
    p=p->lchild;
}

Node* rInsert(Node* p,int key)
{
    Node* t;
    if(p==NULL)
    {
        t=new Node;
        t->data=key;
        t->lchild=NULL;
        t->rchild=NULL;
        t->height=1;
        return t;
    }
    if(key<p->data)
        p->lchild=rInsert(p->lchild,key);
    else
        p->rchild=rInsert(p->rchild,key);
    
    p->height=NodeHeight(p);

    if(BalanceFactor(p)==2&&BalanceFactor(p->lchild)==1)
    return LLRotation(p);
    else if(BalanceFactor(p)==-2&&BalanceFactor(p->lchild)==-1)
    return LRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
        return RRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
        return RLRotation(p);
 return p;
    
}
Node* Delete(Node* p,int key)
{
    if(p==NULL)
    return NULL;
    if(p->lchild==NULL&&p->rchild==NULL)
    {
        if(p==root)
        root=NULL;
        delete p;
        return NULL;
    }
    if(key<p->data)
    p->lchild=Delete(p->lchild,key);
    else if(key>p->data)
    p->rchild=Delete(p->rchild,key);
    else
    {
        Node* q;
        if(NodeHeight(p->lchild)>NodeHeight(p->rchild))
        {
            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=InSucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    p->height=NodeHeight(p);

    if(BalanceFactor(p)==2&&BalanceFactor(p->lchild)==1)
    return LLRotation(p);
    else if(BalanceFactor(p)==2&&BalanceFactor(p->lchild)==-1)
    return LRRotation(p);
    else if(BalanceFactor(p)==-2&&BalanceFactor(p->lchild)==-1)
    return RRRotation(p);
    else if(BalanceFactor(p)==-2&&BalanceFactor(p->lchild)==1)
    return RLRotation(p);
    else if(BalanceFactor(p)==2&&BalanceFactor(p->lchild)==0)
    return LLRotation(p);
    else if(BalanceFactor(p)==-2&&BalanceFactor(p->lchild)==0)
    return RRRotation(p);

 return p;
}
void Inorder(Node* p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}
};

int main()
{AVL t;
  int A[]={10,20,30,25,28,27,5};
  for(int i=0;i<sizeof(A)/sizeof(A[0]);i++)
  {
    t.root=t.rInsert(t.root,A[i]);
  }
  t.Inorder(t.root);
  cout<<endl;
  t.Delete(t.root,28);
  t.Inorder(t.root);
   return 0;
}


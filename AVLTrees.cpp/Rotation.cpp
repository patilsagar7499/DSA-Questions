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
{AVL t1;
  //LL Rotation
  t1.root=t1.rInsert(t1.root,30);
  t1.root = t1.rInsert(t1.root, 20);
  t1.root = t1.rInsert(t1.root, 10);
  t1.Inorder(t1.root);
  cout<<endl;
  // RR Rotation
    AVL t2;
    t2.root = t2.rInsert(t2.root, 10);
    t2.root = t2.rInsert(t2.root, 20);
    t2.root = t2.rInsert(t2.root, 30);
   t2.Inorder(t2.root);
   cout<<endl;
  //LR Rotation
   AVL t3;
    t3.root = t3.rInsert(t3.root, 30);
    t3.root = t3.rInsert(t3.root, 10);
    t3.root = t3.rInsert(t3.root, 20);
    t3.Inorder(t3.root);
    cout<<endl;
    AVL t4;
    t4.root = t4.rInsert(t4.root, 10);
    t4.root = t4.rInsert(t4.root, 30);
    t4.root = t4.rInsert(t4.root, 20);
    t4.Inorder(t4.root);
    cout<<endl;
   return 0;
}


#include<iostream>
#include<cmath>
using namespace std;
class Node{
public:
 int coeff;
 int exp;
 Node* next;
};
 void create(Node* &poly)
 {
    Node *t,*last=NULL;
    int num,i;
    cout<<"Enter no. of terms:";
    cin>>num;
    cout<<"Enter each term with coeff and exp"<<endl;
    for(i=0;i<num;i++)
    {
        t=new Node();
        cin>>t->coeff>>t->exp;
        t->next=NULL;
        if(poly==NULL)
        poly=last=t;
        else{
         last->next=t;
         last=t;
        }
    }
 }
 void display(Node* p)
 {
    while(p)
    {
      cout<<p->coeff<<"X"<<p->exp<<"+";
      p=p->next;
    }
    cout<<endl;

 }
long Eval(Node* p,int x)
{
   long val=0;
   while(p)
   {
      val+=p->coeff*pow(x,p->exp);
      p=p->next;
   }
   return val;
}

int main()
{
   Node* poly=NULL;
  create(poly);
  display(poly);
  cout<<Eval(poly,1);
//    recdisplay(head);
//    revrecdisplay(head);
}


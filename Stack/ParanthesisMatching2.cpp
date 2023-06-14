#include<iostream>
#include<cstring>
using namespace std;
class Node{
    public:
    char data;
    Node* next;
    Node(char data)
    {
        this->data=data;
        this->next=NULL;
    }
};
    void push(Node* &top,char val)
    {
        Node* t=new Node(val);
        if(t==NULL)
          cout<<"Stack Overflow";
        else
        {
            t->next=top;
            top=t;
        }
    }
    char pop(Node* &top)
    {
        char x;
        if(top==NULL)
        cout<<"Stack is empty";
        else
        {
            Node* t=top;
            top=top->next;
            x=t->data;
            delete t;
        }
        return x;
    }
    char peek(Node* top,int pos)
    {
        Node* temp=top;
        int count=0;
        while(count<pos-1&&temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        if(temp==NULL)
         return -1;
        else
         return temp->data;
    }
    char stacktop(Node* top)
    {
        if(top)
        return top->data;
        return -1;
    }
    int isempty(Node* top)
    {
        return top?0:1;
    }
    int isfull(Node* top)
    {
        Node* t;
        int r=t?1:0;
        delete (t);
        return r;
    }
    int isBalanced(Node* &top,char *exp)
    {
        for(int i=0;i<strlen(exp);i++)
        {
          if (exp[i] == '('||exp[i] == '{'||exp[i] == '[')
          {push(top,exp[i]);} 
          else if (exp[i] == ')'||exp[i] == '}'||exp[i] == ']')
          {if (isempty(top)){
                return false;
            } else {
                char x=pop(top);
                if(exp[i]-x<1&&exp[i]>2)
                return false;
            }
          }
        }
        return isempty(top) ? true : false;
    }
    void display(Node* top)
    {
        Node* temp=top;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }

    }
int main()
{
    Node* top=NULL;
    char E[] = "{([a+b]*[c-d])/e}";
    cout << isBalanced(top,E) << endl;
     top=NULL;
    char F[] = "{([a+b)*[c-d]]/e}";
    cout << isBalanced(top,F) << endl;
    top=NULL;
    char G[] = "{([a+b)*[c-d])/e}";
    cout << isBalanced(top,G) << endl;
   return 0;
}

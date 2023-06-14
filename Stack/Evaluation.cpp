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
    int isOperand(Node* top,char exp)
    {
        if(exp=='+'||exp=='-'||exp=='*'||exp=='/')
        return 0;
        return 1;
    }
    int pre(Node* top,char exp)
    {
        if(exp=='+'||exp=='-')
        return 1;
        else if(exp=='*'||exp=='/')
        return 2;
        return 0;
    }
    int evaluation(Node* &top,char *postfix)
    {
           int x1,x2,r;
           for(int i=0;postfix[i]!='\0';i++)
           {
            if(isOperand(top,postfix[i]))
            push(top,postfix[i]-'0');
            else{
                x2=pop(top);x1=pop(top);
                switch (postfix[i])
                {
                case '+':r=x1+x2;push(top,r);
                    break;
                case '-':r=x1-x2;push(top,r);
                    break;
                case '*':r=x1*x2;push(top,r);
                    break;
                case '/':r=x1/x2;push(top,r);
                    break;
                default:
                    break;
                }
            }
           }
           return pop(top);
    }
    char* convert(Node* &top,char *infix)
    {
        char* postfix=new char[strlen(infix)+1];
        int i=0,j=0;
        while(infix[i]!='\0')
        {
            if(isOperand(top,infix[i]))
            postfix[j++]=infix[i++];
            else
            {
                if(pre(top,infix[i])>pre(top,top->data))
                push(top,infix[i++]);
                else
                postfix[j++]=pop(top);
            }
        }
        while(top!=NULL&&top->data!='#')
        {
            postfix[j++]=pop(top);
        }
        postfix[j]='\0';
        return postfix;
    }
    
int main()
{
    Node* top=NULL;
    char E[] = "3*5+6/2-4"; 
    push(top,'#');
    char * x=convert(top,E);
    cout<<x<<endl;
    cout<<evaluation(top,x);
    // Node* top=NULL;
    // char *infix= "a+b*c-d/e";
    // push(top,'#');
    // char *postfix1=convert(top,infix);
    // cout <<postfix1;
   return 0;
}

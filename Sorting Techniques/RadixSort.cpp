#include<iostream>
using namespace std;
class Node{
    public:
    Node* next;
    int data;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
void insert(Node** head, int val,int idx)
{
    Node* n=new Node(val);
    if(head[idx]==NULL)
    {
        head[idx]=n;
    }
    else
    {
        Node* temp=head[idx];
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=n;
    }
}
int Delete(Node** head,int val)
{
    Node* temp=head[val];
    head[val]=head[val]->next;
    int x=temp->data;
    delete temp;
    return x;
}
int FindMax(int A[],int n)
{
    int maxi=INT32_MIN;
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,A[i]);
    }
    return maxi;
}
void Radix(int A[],int n)
{
    int max=FindMax(A,n);
    int x=1;
    Node** bins=new Node*[max+1];
    for(int i=0;i<max+1;i++)
    bins[i]=NULL;   
    while(max>x)
    {
        for(int i=0;i<n;i++)
        {
            int y=(A[i]/x)%10;
            insert(bins,A[i],y);
        }
        x=10*x;
    
    int i=0,j=0;
    while(i<max+1)
    {
        while(bins[i]!=NULL)
        A[j++]=Delete(bins,i);
        i++;
    } 
    }
}
int main()
{
    int A[]={237,146,259,348,152,163,235,48,36,62},n=10;
    Radix(A,n);
    for(int i=0;i<n;i++)
    cout<<A[i]<<" ";
   return 0;
}

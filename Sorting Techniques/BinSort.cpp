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
void insert(Node** head, int val)
{
    Node* n=new Node(val);
    if(head[val]==NULL)
    {
        head[val]=n;
    }
    else
    {
        Node* temp=head[val];
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
void BinSort(int A[],int n)
{
    int max=FindMax(A,n);
    Node** bins=new Node*[max+1];
    for(int i=0;i<max+1;i++)
    bins[i]=NULL;
    for(int i=0;i<n;i++)
    insert(bins,A[i]);
    int i=0,j=0;
    while(i<max+1)
    {
        while(bins[i]!=NULL)
        A[j++]=Delete(bins,i);
        i++;
    }
    delete [] bins;
}
int main()
{
    int A[]={1,0,2,9,3,8,4,7,5,6},n=sizeof(A)/sizeof(A[0]);
    BinSort(A,n);
    for(int i=0;i<n;i++)
    cout<<A[i]<<" ";
   return 0;
}

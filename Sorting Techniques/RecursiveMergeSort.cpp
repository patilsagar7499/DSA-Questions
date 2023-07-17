#include<iostream>
using namespace std;
void Merge(int A[],int l,int mid,int h)
{
    int i,j,k;
    int B[h+1];
    i=l,j=mid+1,k=l;
    while (i<=mid&&j<=h)
    {
        if(A[i]<A[j])
        B[k++]=A[i++];
        else
        B[k++]=A[j++];
    }
    for(;i<=mid;i++)
    B[k++]=A[i];
    for(;j<=h;j++)
    B[k++]=A[j];
    for(i=l;i<=h;i++)
    A[i]=B[i];    
}
void RecMerge(int A[],int l,int h)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        RecMerge(A,l,mid);
        RecMerge(A,mid+1,h);
        Merge(A,l,mid,h);
    }
}
int main()
{
    int A[]={1,0,2,9,3,8,4,7,5,6},n=10;
    RecMerge(A,0,n);
    for(int i=0;i<n;i++)
    cout<<A[i]<<" ";
   return 0;
}

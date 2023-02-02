#include<iostream>
using namespace std;
void Union()
{
     int i=0,j=0,k=0;
    int A[]={1,2,3,4,5};
    int B[]={3,4,5,6,7};
    int C[10];
    while(i<size(A)&&j<size(B))
    {
        if(A[i]<B[j])
        C[k++]=A[i++];
        else if(A[i]>B[j])
        C[k++]=B[j++];
        else
        {
        C[k++]=A[i++];
        j++;
        }
    }
    for(;i<size(A);i++)
    {
        C[k++]=A[i];
    }
    for(;j<size(B);j++)
    {
        C[k++]=B[j];
    }
    for(int i=0;i<k;i++)
    cout<<C[i]<<" ";
    cout<<endl;
}
void Intersection()
{
    int i=0,j=0,k=0;
    int A[]={1,2,3,4,5};
    int B[]={3,4,5,6,7};
    int C[10];
    while(i<size(A)&&j<size(B))
    {
        if(A[i]<B[j])
        i++;
        else if(A[i]>B[j])
        j++;
        else
        {
          C[k++]=A[i++];
          j++;
        }
    }
    
    for(int i=0;i<k;i++)
    cout<<C[i]<<" ";
    cout<<endl;
}
void Difference()
{
    int i=0,j=0,k=0;
    int A[]={1,2,3,4,5};
    int B[]={3,4,5,6,7};
    int C[10];
    while(i<size(A)&&j<size(B))
    {
        if(A[i]<B[j])
        C[k++]=A[i++];
        else if(A[i]>B[j])
        C[k++]=B[j++];
        else
        {
          i++;
          j++;
        }
    }
    for(;i<size(A);i++)
    {
        C[k++]=A[i];
    }
    for(int i=0;i<k;i++)
    cout<<C[i]<<" ";
}
int main()
{
    Union();
    Intersection();
    Difference();
}
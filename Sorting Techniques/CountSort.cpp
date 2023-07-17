#include<iostream>
using namespace std;
int FindMax(int A[],int n)
{
    int maxi=INT32_MIN;
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,A[i]);
    }
    return maxi;
}
void CountSort(int A[],int n)
{
   int x=FindMax(A,n);
   int C[x+1];
   for(int i=0;i<x+1;i++)
   C[i]=0;
   for(int i=0;i<n;i++)
   C[A[i]]++;
   int i=0,j=0;
   while(i<x+1)
   {
    if(C[i]>0)
    {
        A[j++]=i;
        C[i]--;
    }
    else i++;
   }
}
int main()
{
   int A[]={1,0,2,9,3,8,4,7,5,6},n=10;
   CountSort(A,n);
   for(int i=0;i<n;i++)
   cout<<A[i]<<" ";
   return 0;
}

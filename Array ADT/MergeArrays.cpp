//Improve this code
#include<iostream>
using namespace std;
int main()
{
    int A[5]={1,2,3,4,5};
    int B[5]={6,7,8,9,10};
    int C[10];
    int i=0,j=0,k=0;
 
    while(i<size(A)&&j<size(B))
    {
        if(A[i]<B[j])
        C[k++]=A[i++];
        else
        C[k++]=B[j++];
    }
    for(;i<size(A);i++)
     C[k++]=A[i];
    for(;j<size(B);j++)
     C[k++]=B[j]; 
   for(int i=0;i<10;i++)
   cout<<C[i]<<" ";

}
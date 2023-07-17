#include<iostream>
using namespace std;
void BubbleSort(int A[],int n)
{int flag;
   for(int i=0;i<n-1;i++)
   {flag=0;
    for(int j=0;j<n-i-1;j++)
    {
        if(A[j]>A[j+1])
        {
            int temp=A[j];
            A[j]=A[j+1];
            A[j+1]=temp;
            flag=1;
        }
    }
    if(flag==0) break;
   }
}
int main()
{
   int A[]={1,9,2,8,3,7,4,6,5},n=9;
   BubbleSort(A,n);
   for(int i=0;i<9;i++)
   cout<<A[i]<<" ";
   return 0;
}

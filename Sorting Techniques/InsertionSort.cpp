#include<iostream>
using namespace std;
void InsertionSort(int A[],int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int x=A[i];
        while(j>=0&&A[j]>x)
        {
             A[j+1]=A[j];
             j--;
        }
        A[j+1]=x;
    }
}
int main()
{
    int A[]={1,0,2,9,3,8,4,7,5,6},n=10;
    InsertionSort(A,n);
    for(int i=0;i<10;i++)
    cout<<A[i]<<" ";
   return 0;
}

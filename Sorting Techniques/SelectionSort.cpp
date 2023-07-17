#include<iostream>
using namespace std;
void SelectionSort(int A[],int n)
{int i,j,k;
    for(i=0;i<n-1;i++)
    {
        for(j=k=i;j<n;j++)
        {
            if(A[k]>A[j])
            {
                k=j;
            }
        }
        int temp=A[i];
            A[i]=A[k];
            A[k]=temp;
    }
}
int main()
{
    int A[]={1,0,2,9,3,8,4,7,5,6},n=10;
    SelectionSort(A,n);
    for(int i=0;i<10;i++)
    cout<<A[i]<<" ";
   return 0;
}

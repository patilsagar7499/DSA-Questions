#include<iostream>
using namespace std;
void ShellSort(int A[],int n)
{
    int gap,i,j;
    for(gap=n/2;gap>=1;gap/=2)
    {
        for(i=gap;i<n;i++)
        {
           int temp=A[i];
           j=i-gap;
           while(j>=0 && A[j]>temp)
           {
            A[j+gap]=A[j];
            j=j-gap;
           }
           A[j+gap]=temp;
        }
    }
}
int main()
{int A[]={1,0,2,9,3,8,4,7,5,6},n=sizeof(A)/sizeof(A[0]);
    ShellSort(A,n);
    for(int i=0;i<n;i++)
    cout<<A[i]<<" ";
   return 0;
}

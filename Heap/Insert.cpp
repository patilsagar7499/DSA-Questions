#include<iostream>
using namespace std;
void insert(int A[],int n)
{
    int temp,i=n;
    temp=A[n];
    while(i>0&&temp>A[i % 2 == 0 ? (i/2)-1 : i/2])
    {
        A[i]=A[i % 2 == 0 ? (i/2)-1 : i/2];
        i=i % 2 == 0 ? (i/2)-1 : i/2;
    }
    A[i]=temp;
}
void print(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
}
int main()
{
    int a[]={45,35,15,30,10,12,6,5,20,50};
    insert(a,9);
    print(a,sizeof(a)/sizeof(a[0]));
   return 0;
}

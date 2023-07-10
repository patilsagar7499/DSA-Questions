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
void create(int A[],int n)
{
    
    int i;
    for(i=0;i<n;i++)
    insert(A,i);
    print(A,7);
}

int main()
{int A[]={10,20,30,25,5,40,35};
    create(A,7);
   return 0;
}

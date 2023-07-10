#include<iostream>
using namespace std;
void insert(int A[],int n)
{
    int temp,i=n;
    temp=A[i];
    while(i>1&&temp>A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}
void Delete(int A[],int n)
{
    int x,i,j,temp,val;
    val=A[1];
    x=A[n];
    A[1]=A[n];
    A[n]=val;
    i=1;j=2*i;
    while(j<=n-1)
    {
        if(j<n-1 && A[j+1]>A[j])
        j=j+1;
        if(A[i]<A[j])
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i=j;
            j=2*j;
        }
        else
        break;
    }
    
}
int main()
{
    int a[]={0,45,35,15,30,10,12,6,5,20,50};
    for(int i=2;i<=10;i++)
    insert(a,i);

    for(int i=10;i>1;i--)
    Delete(a,i);
    // print(a,sizeof(a)/sizeof(a[0]));
    for(int i=1;i<=10;i++)
    cout<<a[i]<<" ";
   return 0;
}

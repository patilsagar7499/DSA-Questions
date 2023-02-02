#include<iostream>
using namespace std;
class Array{

int *A;
int size;
int length;

public:
Array(int size)
{
    size=size;
}
void create()
{
    cout<<"Enter no. of elements:";
    cin>>length;
    for(int i=0;i<length;i++)
    {
        cout<<"Enter:";
        cin>>A[i];
    }
}
int isSorted()
{
   for(int i=0;i<length-1;i++)
   {
       if(A[i]>A[i+1])
       return 0;
   }
   return 1;
}
void insertSort(int x)
{
    int i=length-1;
    if(length==size)
    return;
    while(i>=0&&A[i]>x)
    {
        A[i+1]=A[i];
        i--;
    }
    A[i+1]=x;
    length++;
}
void rearrange()
{
    int i=0;
    int j=length-1;
    while(i<j)
    {
        while(A[i]<0)i++;
        while(A[j]>=0)j--;
        if(i<j)
        {
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
}
void display()
{
    for(int i=0;i<length;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
};
int main()
{
   Array arr(10);
    arr.create();
//    cout<<arr.isSorted();
//    cout<<endl;
//    arr.display();
//    arr.insertSort(1);
//    arr.display();
   arr.rearrange();
   arr.display();
}
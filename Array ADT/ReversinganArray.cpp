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
        cout<<"Enter element:";
        cin>>A[i];
    }
}
void reverse1()
{
    int i,j;
    int *B;
     B=new int[length];
     for( i=length-1,j=0;i>=0;i--,j++)
     {
        B[j]=A[i];
     }
     for(int i=0;i<length;i++)
     {
         A[i]=B[i];
     }
}
void reverse2()
{
    for(int i=length-1,j=0;i>=j;i--,j++)
    {
       int temp=A[i];
       A[i]=A[j];
       A[j]=temp;
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
    arr.display();
    //arr.reverse1();
    arr.reverse2();
    arr.display();
}
#include<iostream>
using namespace std;
class Array{
int x;
int A[100];
public:
void create()
{
    
    cout<<"No. of elements:";
    cin>>x;
    cout<<"Enter sorted array:"<<endl;
    for(int i=0;i<x;i++)
    {
        cout<<"Enter:";
        cin>>A[i];
    }
}
 void duplicate()
{
   
   int previous=0;
   for(int i=0;i<x-1;i++)
   {
       if(A[i]==A[i+1]&&A[i]!=previous)
       {
           cout<<A[i]<<" ";
           previous=A[i];
       }
   }
   cout<<endl;
}
void Noofduplicate()
{
   for(int i=0;i<x-1;i++)
   {
       if(A[i]==A[i+1])
       {
           int j=i+1;
           while(A[j]==A[i])j++;
           cout<<A[i]<<"->"<<j-i<<" times.";
           i=j-1;
       }
   }
}
};
int main()
{
    Array arr;
    int n;
    do{
    cout<<"Enter 1)Just to find duplicate ,2)Find duplicate and no. of repetation ,3)Exit:";
    cin>>n;
   
    switch(n)
    {
        case 1:
        arr.create();
        arr.duplicate();
        break;
        case 2:
        arr.create();
        arr.Noofduplicate();
        break;
    }
    }while(n!=3);
}
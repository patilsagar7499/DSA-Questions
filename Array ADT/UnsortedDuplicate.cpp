#include<iostream>
using namespace std;
class Array{
int n;
int A[100];
public:
void create()
{
   cout<<"Enter no. of elements";
   cin>>n;
   for(int i=0;i<n;i++)
   {
       cout<<"Enter:";
       cin>>A[i];
   }
}
void withouthashtable()
{
for(int i=0;i<n-1;i++)
{
    int count=1;
    if(A[i]!=-1){
    for(int j=i+1;j<n;j++)
    {
      if(A[i]==A[j])
      {
          count++;
            A[j]=-1;
      }

    }
    if(count>1)
    {cout<<A[i]<<"->"<<count<<"times"<<endl;}
    }
}
}
void withhashtable()
{
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,A[i]);
    }
    int idx[maxi+1];
    for(int i=0;i<maxi+1;i++)
    {
        idx[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        idx[A[i]]++;
    }
    for(int i=0;i<maxi+1;i++)
    {
        if(idx[i]>1)
        cout<<A[i]<<"->"<<idx[i]<<"times"<<endl;
    }
}
};
int main()
{
    Array arr;
    int x;
    do{
    cout<<"Enter 1)Without hashtable ,2)With hashtable ,3)Exit:";
    cin>>x;
    switch (x)
    {
    case 1:
    arr.create();
    arr.withouthashtable();
    break;

    case 2:
    arr.create();
    arr.withhashtable();
    break;
    }
     
    }while(x!=3);
}
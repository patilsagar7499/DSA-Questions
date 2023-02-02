#include<iostream>
using namespace std;
class Array{
int n;
int A[100];
int s;
public:
void create()
{
   cout<<"Enter no. of elements:";
   cin>>n;
   for(int i=0;i<n;i++)
   {
       cout<<"Enter:";
       cin>>A[i];
   }
   cout<<"Enter sum:";
   cin>>s;
}
void withoutHashing()
{ 
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(A[i]+A[j]==s)
            {
                cout<<A[i]<<"&"<<A[j]<<endl;
            }
        }
    }
}
void withHashing()
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
        if(idx[s-A[i]]==1)
        cout<<A[i]<<"&"<<s-A[i]<<endl;
        idx[A[i]]=1;
    }
}
};
int main()
{
    Array arr;
    int x;
    do{
    cout<<"Enter 1)Without hashing ,2)With hashing ,3)Exit:";
    cin>>x;
    switch (x)
    {
    case 1:
    arr.create();
    arr.withoutHashing();
    break;

    case 2:
    arr.create();
    arr.withHashing();
    break;
    }
     
    }while(x!=3);
}
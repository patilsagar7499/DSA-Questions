#include<iostream>
using namespace std;
int main()
{   //Specially used for unsorted
    //T.c=O(n)
    int n;
    cout<<"Enter no. of elements:";
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter:";
        cin>>A[i];
    }
    int maxi=INT_MIN;
    int mini=INT_MAX;
    for(int i=0;i<n;i++)
    {
         maxi=max(maxi,A[i]);
         mini=min(mini,A[i]);
    }
    int idx[maxi];
    for(int i=mini;i<=maxi;i++)
    {
        idx[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        idx[A[i]]=1;
    }
    for(int i=mini;i<=maxi;i++)
    {
        if(idx[i]==0)
        cout<<i<<" ";
    }
}
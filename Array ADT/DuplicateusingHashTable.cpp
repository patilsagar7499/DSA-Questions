#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no. of elements:";
    cin>>n;
    int a[n];
    cout<<"Enter elements in sorted array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter:";
        cin>>a[i];
    }
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,a[i]);
    }
    int idx[maxi+1];
    for(int i=0;i<maxi+1;i++)
    {
        idx[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        idx[a[i]]++;
    }
    for(int i=0;i<maxi+1;i++)
    {
        if(idx[i]>1)
        cout<<a[i]<<"->"<<idx[a[i]]<<" times";
    }
}
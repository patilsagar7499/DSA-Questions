#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no.of elements:";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Element:";
        cin>>a[i];
    }
    int max=a[0],min=a[0];
    for(int i=1;i<n;i++)
    {
        if(min>a[i])
        min=a[i];
        if(max<a[i])
        max=a[i];
    }
    cout<<"Max:"<<max<<" Min:"<<min;
}
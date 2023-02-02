#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no. of elements:";
    cin>>n;
    int a[n];
    cout<<"Enter elements in sorted order"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter:";
        cin>>a[i];
    }
    int s;
    cout<<"Enter sum:";
    cin>>s;
    int i=0,j=n-1;
    while(i<j)
    {
        if(a[i]+a[j]==s){
        cout<<a[i]<<"&"<<a[j]<<endl;
        i++;
        j--;}
        else if(a[i]+a[j]<s)
        i++;
        else
        j--;

    }
}
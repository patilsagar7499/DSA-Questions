#include<iostream>
using namespace std;
int main()
{
    char a[5]={'A','B','C','D','E'};
    char b[]={'A','B','C','D','E'};
    char c[5]={65,66,67,68,69};
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
    for(int i=0;i<5;i++)
    {
        cout<<b[i]<<" ";
    }
    for(int i=0;i<5;i++)
    {
        cout<<c[i]<<" ";
    }
}
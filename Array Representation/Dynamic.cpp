#include<iostream>
using namespace std;
int main()
{
    int a[5]={1,2,3,4,5};
    int *p;
    p=new int[5];
    for(int i=0;i<5;i++)
    {
        p[i]=2*i;
    }
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<p[i]<<" ";
    }
    delete []p;
}
#include<iostream>
using namespace std;
int main()
{
    int a[5]={1,2,3,4,5};
    int b[5];
    int c[5]={1,2};
    int d[5]={0};
    int e[]={1,2,3,4,5,6};
    cout<<a[2]<<" "<<2[a]<<" "<<*(a+2)<<" "<<&(a[2])<<endl;
    for(int i=0;i<5;i++)
    {cout<<b[i]<<" "<<c[i]<<" "<<d[i]<<" "<<e[i];;
    cout<<endl;}
}
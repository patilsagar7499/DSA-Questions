#include<iostream>
using namespace std;
int *function(int n)
{
    int *p;
    p=new int[n];
    return p;
}
int main()
{
    int *a;
    a=function(5);
    cout<<*a<<" ";
}
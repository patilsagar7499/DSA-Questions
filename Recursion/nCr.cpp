#include<iostream>
using namespace std;
// int fact(int n)
// {
//     if(n==0)
//     return 1;
//     return fact(n-1)*n;
// }
// int fun(int n,int r)
// {
//    int num=fact(n);
//    int den=fact(r)*fact(n-r);
//    return num/den;
// }

int fun(int n,int r)
{
    if(r==0||n==r)
    return 1;
    return fun(n-1,r-1)+fun(n-1,r);
}
int main()
{
   cout<<fun(4,3);
}
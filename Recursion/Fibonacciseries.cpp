#include<iostream>
using namespace std;
// int fun(int n)
// {
//     if(n<=1)
//     return n;
//     return fun(n-2)+fun(n-1);
// }

// int fun(int n)
// {
//     int t0=0,t1=1,s;
//     if(n<=1)
//      return n;
//     for(int i=2;i<=n;i++)
//     {
//         s=t0+t1;
//         t0=t1;
//         t1=s;
//     }
//     return s;
// }
int F[10];
int fun(int n)
{
    if(n<=1)
      return n;
    if(F[n-2]==-1)
      F[n-2]=fun(n-2);
    if(F[n-1]==-1)
      F[n-1]=fun(n-1);
    return F[n-2]+F[n-1];
}
int main()
{
    for(int i=0;i<10;i++)
      F[i]=-1;
   cout<<fun(6);
}
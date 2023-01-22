#include<iostream>
using namespace std;
 int fun(int n)
 {
     if(n==0)
     return 1;
     return fun(n-1)*n;
 }
// int fun(int n)
// {
//    int p=1;
//    for(int i=1;i<=n;i++)
//    {
//        p=p*i;
//    }
//    return p;
// }
int main()
{
    cout<<fun(5);
}
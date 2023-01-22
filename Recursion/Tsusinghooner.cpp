#include<iostream>
using namespace std;
double fun(int x,int n)
{
    static double s;
    if(n==0)
     return s;
    s=1+x*s/n;
    return fun(x,n-1);
}

// double fun(int x,int n)
// {
//     static double s;
//     for(;n>0;n--)
//     {
//         s=1+x*s/n;
//     }
//     return s;
// }

// double fun(int x,int n)
// {
//     double s=1,num=1,den=1;
//     for(int i=1;i<n;i++)
//     {
//         num*=x;
//         den*=i;
//         s+=num/den;
//     }
//     return s;
// }

int main()
{
    cout<<fun(2,10);
}

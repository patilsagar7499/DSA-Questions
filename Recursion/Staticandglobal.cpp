#include<iostream>
using namespace std;
//for global write here-int x=0;
int fun(int n)
{
    static int x=0;//static
    if(n>0)
    {
        x++;
        return fun(n-1)+x;
    }
}
int main()
{
    int a=5;
 cout<<fun(a)<<" ";
}
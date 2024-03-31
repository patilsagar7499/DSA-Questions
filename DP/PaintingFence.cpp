#include<iostream>
using namespace std;
int solve(int n,int k)
{
    if(n==1)
    return k;
    if(n==2)
    return k*k;

    int ans=solve(n-2,k)*(k-1)+solve(n-1,k)*(k-1);
    return ans;
}
int main()
{
    int n,k;
    cout<<"Enter:";
    cin>>n>>k;
    cout<<solve(n,k);
   return 0;
}

#include<iostream>
using namespace std;
int solve(int n)
{
    if(n==0)
    return 0;
    int ans=n;
    for(int i=1;i*i<=n;i++)
    {
        ans=min(ans,1+solve(n-i*i));
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;
    cout<<solve(n);
   return 0;
}

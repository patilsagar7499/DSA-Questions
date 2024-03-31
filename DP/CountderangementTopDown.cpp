#include<iostream>
#include<vector>
using namespace std;
int solve(int n,vector<int>&dp)
{
    if(n==1)
    return 0;
    if(n==2)
    return 1;
    if(dp[n]!=-1)
    return dp[n];

    dp[n]=(n-1)*(solve(n-2,dp)+solve(n-1,dp));
    return dp[n];
}
int main()
{
   int n;
   cout<<"Enter:";
   cin>>n;
   vector<int> dp(n+1,-1);
   cout<<solve(n,dp);
   return 0;
}

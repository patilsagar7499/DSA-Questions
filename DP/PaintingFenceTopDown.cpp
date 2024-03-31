#include<iostream>
#include<vector>
using namespace std;
int solve(int n,int k,vector<int>&dp)
{
    if(n==1)
    return k;
    if(n==2)
    return k*k;
    if(dp[n]!=-1)
    return dp[n];

    dp[n]=solve(n-2,k,dp)*(k-1)+solve(n-1,k,dp)*(k-1);
    return dp[n];
}
int main()
{
   int n,k;
   cout<<"Enter:";
   cin>>n>>k;
   vector<int>dp(n+1,-1);
  cout<<solve(n,k,dp);
   return 0;
}

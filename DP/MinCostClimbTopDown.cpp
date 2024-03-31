#include<iostream>
#include<vector>
using namespace std;
int solve(int cost[],int n,vector<int>&dp)
{
    if(n==0)
    return cost[0];
    if(n==1)
    return cost[1];

    //Step3:Check if present in Dp
    if(dp[n]!=-1)
    return dp[n];

    //Step2:Store in Dp
    dp[n]=cost[n]+min(cost[n-1],cost[n-2]);
    return dp[n];
}
int main()
{int n;
 cout<<"Enter no. of stairs:";
 cin>>n;
 int cost[n];
 for(int i=0;i<n;i++)
 {
    cout<<"Enter:";
    cin>>cost[i];
 }
 
 //Step1:Create Dp 
 vector<int> dp(n+1,-1);
 int ans=min(solve(cost,n-1,dp),solve(cost,n-2,dp));
 cout<<ans;
   return 0;
}

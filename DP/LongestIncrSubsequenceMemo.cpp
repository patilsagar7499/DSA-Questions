#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&s,int n,int curr,int prev,vector<vector<int>>&dp)
{
    if(curr==n)return 0;
    if(dp[curr][prev+1]!=-1)return dp[curr][prev+1];

    int take=0;
    if(prev==-1||s[curr]>s[prev])
    take=1+solve(s,n,curr+1,curr,dp);
    int nottake=solve(s,n,curr+1,prev,dp);

    dp[curr][prev+1]=max(take,nottake);
    return dp[curr][prev+1];
}
int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<int> s(n);
    cout<<"Enter elements:";
    for(int i=0;i<n;i++)
    cin>>s[i];
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    cout<<solve(s,n,0,-1,dp);
   return 0;
}

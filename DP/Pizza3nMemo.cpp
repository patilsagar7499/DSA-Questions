#include<iostream>
#include<vector>
using namespace std;
int solve(int Index,int endIndex,vector<int>&v,int n,vector<vector<int>>&dp)
{
    if(n==0||Index>endIndex)
    return 0;
    if(dp[Index][n]!=-1)return dp[Index][n];
    int take=v[Index]+solve(Index+2,endIndex,v,n-1,dp);
    int nottake=solve(Index+1,endIndex,v,n,dp);
    dp[Index][n]=max(take,nottake);
    return dp[Index][n];
}
int main()
{
int n;
cout<<"Enter n:";
cin>>n;
vector<int>v(n);
cout<<"Enter:";
for(int i=0;i<n;i++)
cin>>v[i];
vector<vector<int>>dp1(n,vector<int>(n,-1));
int case1=solve(0,n-2,v,n/3,dp1);
vector<vector<int>>dp2(n,vector<int>(n,-1));
int case2=solve(1,n-1,v,n/3,dp2);
cout<<max(case1,case2);
return 0;
}
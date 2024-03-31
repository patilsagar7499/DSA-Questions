#include<iostream>
#include<vector>
using namespace std;
int solve(int dice,int face,int target,vector<vector<int>>&dp)
{
    if(target<0)return 0;
    if(dice!=0&&target==0)return 0;
    if(dice==0&&target!=0)return 0;
    if(dice==0&&target==0)return 1;
    if(dp[dice][target]!=-1)return dp[dice][target];
    int ans=0;
    for(int i=1;i<=face;i++)
    {
        ans=ans+solve(dice-1,face,target-i,dp);
    }
    dp[dice][target]=ans;
    return dp[dice][target];
}
int main()
{
int n,m,x;
cout<<"Enter no. of dice,no. of faces,total sum:";
cin>>n>>m>>x;
vector<vector<int>>dp(n+1,vector<int>(x+1,-1));
cout<<solve(m,n,x,dp);
return 0;
}
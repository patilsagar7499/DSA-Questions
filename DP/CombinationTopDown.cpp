#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&arr,int target,vector<int>&dp)
{
    if(target<0)return 0;
    if(target==0)return 1;
    if(dp[target]!=-1)return dp[target];
    int ans=0;
    for(int i=0;i<arr.size();i++)
    {
        ans+=solve(arr,target-arr[i],dp);
    }
    dp[target]=ans;
    return dp[target];
}
int main()
{
    int n,target;
    cout<<"Enter n and target:";
    cin>>n;
    cin>>target;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {cout<<"Enter:";
    cin>>arr[i];}
    vector<int> dp(target+1,-1);
    cout<<solve(arr,target,dp);
   return 0;
}

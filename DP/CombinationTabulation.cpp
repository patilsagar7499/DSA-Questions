#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&arr,int target)
{
    vector<int>dp(target+1,0);
    dp[0]=1;
    for(int i=1;i<=target;i++){
    for(int j=0;j<arr.size();j++)
    {
        if(i-arr[j]>=0)
        dp[i]+=dp[i-arr[j]];
    }
    }
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
    cout<<solve(arr,target);
   return 0;
}

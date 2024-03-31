#include<iostream>
#include<vector>
using namespace std;
int solve(int cost[],int n)
{
    //Step1:Create Dp
    vector<int> dp(n+1);

    //Step2:Base Case Analysis
    dp[0]=cost[0];
    dp[1]=cost[1];

    //Step3:
    for(int i=2;i<n;i++)
    {
        dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
    }
    return min(dp[n-1],dp[n-2]);
}
int main()
{
 int n;
 cout<<"Enter no. of stairs:";
 cin>>n;
 int cost[n];
 for(int i=0;i<n;i++)
 {
    cout<<"Enter:";
    cin>>cost[i];
 }
  int ans=solve(cost,n);
  cout<<ans;
   return 0;
}

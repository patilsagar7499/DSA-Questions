#include<iostream>
#include<vector>
using namespace std;
int solve(int n)
{
    vector<int>dp(n+1,INT32_MAX);
    dp[0]=0;
    for(int i=1;i<=n;i++){
    for(int j=1;j*j<=n;j++)
    {
        if(i-j*j>=0)
        dp[i]=min(dp[i],1+dp[i-j*j]);
    }
    }
    return dp[n];
}
int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;
    cout<<solve(n);
   return 0;
}

#include<iostream>
#include<vector>
using namespace std;
int solve(int n,int x,int y,int z)
{
    vector<int>dp(n+1,-1);
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
       if(i-x>=0&&dp[i-x]!=-1)
       dp[i]=max(dp[i],dp[i-x]+1);
       if(i-y>=0&&dp[i-y]!=-1)
       dp[i]=max(dp[i],dp[i-y]+1);
       if(i-z>=0&&dp[i-z]!=-1)
       dp[i]=max(dp[i],dp[i-z]+1);
    }
    if(dp[n]<0)
    return 0;
    else
    return dp[n];
}
int main()
{
   int n;
   cout<<"Length:";
   cin>>n;
   int x,y,z;
   cout<<"X,Y,Z:";
   cin>>x>>y>>z;
   cout<<solve(n,x,y,z);
   return 0;
}

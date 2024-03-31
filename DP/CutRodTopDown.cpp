#include<iostream>
#include<vector>
using namespace std;
int solve(int n,int x,int y,int z,vector<int>&dp)
{
    if(n==0)
    return 0;
    if(n<0)
    return INT32_MIN;

    //Step3
    if(dp[n]!=-1)
    return dp[n];

    int a=solve(n-x,x,y,z,dp)+1;
    int b=solve(n-y,x,y,z,dp)+1;
    int c=solve(n-z,x,y,z,dp)+1;

    //Step2
    dp[n]=max(a,max(b,c));

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

   //Step1
   vector<int> dp(n+1,-1);
   int ans=solve(n,x,y,z,dp);
   if(ans<0)
   cout<<0;
   else
   cout<<ans;
   return 0;
}

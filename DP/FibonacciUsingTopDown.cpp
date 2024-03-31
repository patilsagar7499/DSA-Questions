#include<iostream>
#include<vector>
using namespace std;
int fib(int n,vector<int>& dp)
{
    if(n<=1)
    return n;
    
    //step3:If already stored then directly returning 
    if(dp[n]!=-1)
    return dp[n];

    //step2:Storing in Dp
    dp[n]=fib(n-1,dp)+fib(n-2,dp);
    return dp[n];
}
int main()
{
    int n;
    cout<<"Enter:";
    cin>>n;

    //Step1:Create Dp
    vector<int> dp(n+1);
    for(int i=0;i<=n;i++)
      dp[i]=-1;
    cout<<fib(n,dp);
   return 0;
}

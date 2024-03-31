#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&num,int n,vector<int>&dp)
{
    if(n<0)
    return 0;
    if(n==0)
    return num[0];

    //Step3
    if(dp[n]!=-1)
    return dp[n];

    int incl=solve(num,n-2,dp)+num[n];
    int excl=solve(num,n-1,dp);

    //Step2
    dp[n]=max(incl,excl);
    return dp[n];
}
int main()
{
   int n;
   cout<<"Enter n:";
   cin>>n;
   vector<int> num(n);
   cout<<"Enter:";
   for(int i=0;i<n;i++)
   cin>>num[i];

   //Step1
   vector<int> dp(n,-1);
   cout<<"O/p:"<<solve(num,n-1,dp);
   return 0;
}

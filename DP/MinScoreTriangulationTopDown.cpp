#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&v,int i,int j,vector<vector<int>>&dp)
{
if(i+1==j)return 0;
if(dp[i][j]!=-1)return dp[i][j];
int mini=INT32_MAX;
for(int k=i+1;k<j;k++)
{
  mini=min(mini,v[i]*v[j]*v[k]+solve(v,i,k,dp)+solve(v,k,j,dp));
}
dp[i][j]=mini;
return dp[i][j];
}
int main()
{
   int n;
   cout<<"Enter no. of edges:";
   cin>>n;
   vector<int> v(n);
   cout<<"Enter weight of vertices:";
   for(int i=0;i<n;i++)
   {
    cin>>v[i];
   }  
   vector<vector<int>> dp(n,vector<int>(n,-1));
   cout<<solve(v,0,n-1,dp);
   return 0;
}

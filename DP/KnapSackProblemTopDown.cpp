#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>&w,vector<int>&v,int capacity,int index,vector<vector<int>>&dp)
{
    if(index==0)
    {
        if(w[0]<=capacity)
        return v[0];
        else
        return 0;
    }
    if(dp[index][capacity]!=-1)
    return dp[index][capacity];
    int include=0;
    if(w[index]<=capacity)
    {
        include=v[index]+solve(w,v,capacity-w[index],index-1,dp);}
        int exclude=solve(w,v,capacity,index-1,dp);
        dp[index][capacity]=max(include,exclude);
        return dp[index][capacity];
}
int main()
{
  int W,n;
  cout<<"Enter weight:";
  cin>>W;
  cout<<"Enter no. of items:";
  cin>>n;
  vector<int> w(n),v(n);
  for(int i=0;i<n;i++)
  {
    cout<<"Enter w["<<i<<"]:";
    cin>>w[i];
    cout<<"Enter v["<<i<<"]:";
    cin>>v[i];
  }
  vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
  cout<<solve(w,v,W,n-1,dp);
   return 0;
}

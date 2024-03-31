#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&ob,int currlane,int currpos,vector<vector<int>>&dp)
{
    int n=ob.size();
   if(currpos==n)return 0;
   if(dp[currlane][currpos]!=-1)return dp[currlane][currpos];
   if(currlane!=ob[currpos+1]) return solve(ob,currlane,currpos+1,dp);
   else
   {
    int ans=INT32_MAX;
    for(int i=1;i<=3;i++)
    {
        if(currlane!=i&&ob[currpos]!=i)
        {
            ans=min(ans,1+solve(ob,i,currpos,dp));
        }
        dp[currlane][currpos]=ans;
    }
    return dp[currlane][currpos];
   }
   
}
int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<int> ob(n);
    cout<<"Enter:";
    for(int i=0;i<n;i++)
    cin>>ob[i];
    vector<vector<int>> dp(4,vector<int>(n,-1));
    cout<<solve(ob,2,0,dp);
   return 0;
}

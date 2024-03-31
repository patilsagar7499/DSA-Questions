#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int> &num,int x,vector<int>& dp)
{
    //Base Case
    if(x==0)
    return 0;
    if(x<0)
    return INT32_MAX;
    if(dp[x]!=-1)
    return dp[x];
    int mini=INT32_MAX;
    for(int i=0;i<num.size();i++)
    {
        int ans=solve(num,x-num[i],dp);
        if(ans!=INT32_MAX)
        {
            mini=min(mini,1+ans);
        }
    }
    dp[x]=mini;
    return mini;
}
int main()
{
    int n,x;
    cout<<"Enter n:";
    cin>>n;
    cout<<"Enter x:";
    cin>>x;
    vector<int> dp(x+1,-1);
   vector<int> num(n);
   cout<<"Enter:";
   for(int i=0;i<n;i++)
   cin>>num[i];
   int ans=solve(num,x,dp);
   if(ans!=INT32_MAX)
   cout<<"O/p:"<<ans;
   else
   cout<<-1;
   return 0;
}

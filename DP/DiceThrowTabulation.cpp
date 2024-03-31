#include<iostream>
#include<vector>
using namespace std;
int solve(int dice,int face,int target)
{
    vector<vector<int>>dp(dice+1,vector<int>(target+1,0));
    dp[0][0]=1;
    for(int d=1;d<=dice;d++)
    {
        for(int t=1;t<=target;t++)
        {int ans=0;
        for(int k=1;k<=face;k++)
        {   if(t-k>=0)
            ans=ans+dp[d-1][t-k];}
         dp[d][t]=ans;
        }
        
    }
    return dp[dice][target];
}
int main()
{
int n,m,x;
cout<<"Enter no. of dice,no. of faces,total sum:";
cin>>n>>m>>x;
cout<<solve(m,n,x);
return 0;
}
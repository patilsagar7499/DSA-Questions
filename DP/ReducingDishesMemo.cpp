#include<iostream>
#include<vector>
using namespace std;
int sort(vector<int>&v,int n)
{
   int i,j,k;
    for(i=0;i<n-1;i++)
    {
        for(j=k=i;j<n;j++)
        {
            if(v[k]>v[j])
            {
                k=j;
            }
        }
        int temp=v[i];
            v[i]=v[k];
            v[k]=temp;
    }
}
int solve(vector<int>&v,int index,int time,vector<vector<int>>&dp)
{
    int n=v.size();
    if(index>n)return 0;
    if(dp[index][time]!=-1)return dp[index][time];
    int include=v[index]*(time+1)+solve(v,index+1,time+1,dp);
    int exclude=solve(v,index+1,time,dp);
    return dp[index][time]=max(include,exclude);
}
int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<int>v(n);
    cout<<"Enter:" ;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v,n);
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    cout<<solve(v,0,0,dp);
   return 0;
}

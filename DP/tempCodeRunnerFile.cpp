#include<iostream>
#include<vector>
using namespace std;
int solve(int a[4][5],int i,int j,int &maxi,vector<vector<int>>&dp)
{
    if(i>3||j>4)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int right=solve(a,i,j+1,maxi,dp);
    int diagonal=solve(a,i+1,j+1,maxi,dp);
    int down=solve(a,i+1,j,maxi,dp);

    if(a[i][j]==1)
    {
       dp[i][j]=1+min(right,min(diagonal,down));
       maxi=max(maxi,dp[i][j]);
       return dp[i][j];
    }
    else return dp[i][j]=0;
}
int main()
{
    int a[4][5]={{1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,0,0}};
    vector<vector<int>> dp(4,vector<int>(5,-1));
    int maxi=0;
    solve(a,0,0,maxi,dp);
    cout<<maxi;
   return 0;
}

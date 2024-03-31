#include<iostream>
#include<vector>
using namespace std;
int solve(int a[4][5],int &maxi)
{
    int row=4;
    int col=5;

    vector<vector<int>>dp(row+1,vector<int>(col+1,0));
    for(int i=row-1;i>=0;i--)
    {
        for(int j=col-1;j>=0;j--)
        {
          int right=dp[i][j+1];
          int diagonal=dp[i+1][j+1];
          int down=dp[i+1][j];

          if(a[i][j]==1)
         {
          dp[i][j]=1+min(right,min(diagonal,down));
          maxi=max(maxi,dp[i][j]);
         }
          else  dp[i][j]=0;
        }
    }
    
    return dp[0][0];

    
}
int main()
{
    int a[4][5]={{1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,0,0}};
    int maxi=0;
    solve(a,maxi);
    cout<<maxi;
   return 0;
}

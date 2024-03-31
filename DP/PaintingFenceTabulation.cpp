#include<iostream>
#include<vector>
using namespace std;
int solve(int n,int k)
{  
    vector<int>dp(n+1);
    dp[1]=k;
    dp[2]=k*k;

    for(int i=3;i<=n;i++)
    {
        dp[i]=dp[i-2]*(k-1)+dp[i-1]*(k-1);
    }
    return dp[n];
}
int main()
{
   int n,k;
   cout<<"Enter:";
   cin>>n>>k;
  cout<<solve(n,k);
   return 0;
}

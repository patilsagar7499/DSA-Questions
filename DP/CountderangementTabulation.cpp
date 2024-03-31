#include<iostream>
#include<vector>
using namespace std;
int solve(int n)
{
    vector<int> dp(n+1);
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=n;i++)
    {
        dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
    }
    return dp[n];
}
int main()
{
    int n;
    cout<<"Enter:";
    cin>>n;
    cout<<solve(n);
   return 0;
}

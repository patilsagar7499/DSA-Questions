#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&ob)
{
   int n=ob.size()-1;
   vector<vector<int>> dp(4,vector<int>(n,1e9));
   dp[0][n]=0;
   dp[1][n]=0;
   dp[2][n]=0;
   dp[3][n]=0;

   for(int currpos=n-1;currpos>=0;currpos--){
    for(int currlane=1;currlane<=3;currlane++)
    {
        if(currlane!=ob[currpos+1]) dp[currlane][currpos]=dp[currlane][currpos+1];
        else
        {
            int ans=1e9;
            for(int i=1;i<=3;i++)
            {
                if(currlane!=i&&ob[currpos]!=i)
                {
                    ans=min(ans,1+dp[i][currpos+1]);
                }
                dp[currlane][currpos]=ans;
            }
            }
   }
   }
    return min(dp[2][0],min(1+dp[1][0],1+dp[3][0]));
  
   
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
    cout<<solve(ob);
   return 0;
}

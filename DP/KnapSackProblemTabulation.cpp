#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>&w,vector<int>&v,int capacity,int n)
{
    vector<vector<int>>dp(n,vector<int>(capacity+1,0));
    for(int i=0;i<=n;i++){
        if(w[0]<=capacity)
        dp[0][i]=v[0];
        else
        dp[0][i]=0;
    }

    for(int index=1;index<n;index++)
    {
        for(int i=0;i<=capacity;i++)
        {
            int include=0;
            if(w[index]<=i)
            include=v[index]+dp[index-1][i-w[index]];
            int exclude=dp[index-1][i];
            dp[index][i]=max(include,exclude);
        }
    }
    return dp[n-1][capacity];
    
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
  cout<<solve(w,v,W,n);
   return 0;
}

#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&v)
{ int n=v.size();
vector<vector<int>> dp(n,vector<int>(n,0));

for(int i=n-1;i>=0;i--)
{
    for(int j=i+2;j<n;j++)
    {
        int mini=INT32_MAX;
       for(int k=i+1;k<j;k++)
       {
        mini=min(mini,v[i]*v[j]*v[k]+dp[i][k]+dp[k][j]);
       }
       dp[i][j]=mini;
    }
}
return dp[0][n-1];
}
int main()
{
   int n;
   cout<<"Enter no. of edges:";
   cin>>n;
   vector<int> v(n);
   cout<<"Enter weight of vertices:";
   for(int i=0;i<n;i++)
   {
    cin>>v[i];
   }  
   
   cout<<solve(v);
   return 0;
}

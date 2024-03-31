#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int> num,int x)
{
    vector<int> dp(x+1,INT32_MAX);
    dp[0]=0;
    for(int i=1;i<=x;i++)
    { //Solve for every amount fig. from 1 to x 
        for(int j=0;j<num.size();j++)
        {
            if(i-num[j]>=0&&dp[i-num[j]]!=INT32_MAX)
            dp[i]=min(dp[i],1+dp[i-num[j]]);
        }
    }
    if(dp[x]==INT32_MAX)
    return -1;
    return dp[x];
}
int main()
{
    int n,x;
    cout<<"Enter n:";
    cin>>n;
    cout<<"Enter x:";
    cin>>x;
   vector<int> num(n);
   cout<<"Enter:";
   for(int i=0;i<n;i++)
   cin>>num[i];
   cout<<"O/p:"<<solve(num,x);
   return 0;
}

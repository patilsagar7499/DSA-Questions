#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int> &num)
{
    int n=num.size();
    vector<int> dp(n,0);
    dp[0]=num[0];
    dp[-1]=dp[-2]=0;
    for(int i=1;i<n;i++)
    {
        int incl=dp[i-2]+num[i];
        int excl=dp[i-1];
        dp[i]=max(incl,excl);
    }
    return dp[n-1];
}
int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;
   vector<int> num(n);
   cout<<"Enter:";
   for(int i=0;i<n;i++)
   cin>>num[i];
   cout<<"O/p:"<<solve(num);

   return 0;
}

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
int solve(vector<int>&v)
{
    int n=v.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int index=n-1;index>=0;index--)
    {
        for(int time=index;time>=0;time--)
        {
          int include=v[index]*(time+1)+dp[index+1][time+1];
          int exclude=dp[index+1][time];
          dp[index][time]=max(include,exclude);
        }
    }
    return dp[0][0];
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
    cout<<solve(v);
   return 0;
}

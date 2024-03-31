#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&s,int n,int curr,int prev)
{
    if(curr==n)return 0;

    int take=0;
    if(prev==-1||s[curr]>s[prev])
    take=1+solve(s,n,curr+1,curr);
    int nottake=solve(s,n,curr+1,prev);

    return max(take,nottake);
}
int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<int> s(n);
    cout<<"Enter elements:";
    for(int i=0;i<n;i++)
    cin>>s[i];
    cout<<solve(s,n,0,-1);
   return 0;
}

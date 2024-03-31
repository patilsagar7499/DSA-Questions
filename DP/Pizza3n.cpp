#include<iostream>
#include<vector>
using namespace std;
int solve(int Index,int endIndex,vector<int>&v,int n)
{
    if(n==0||Index>endIndex)
    return 0;
    int take=v[Index]+solve(Index+2,endIndex,v,n-1);
    int nottake=solve(Index+1,endIndex,v,n);
    return max(take,nottake);
}
int main()
{
int n;
cout<<"Enter n:";
cin>>n;
vector<int>v(n);
cout<<"Enter:";
for(int i=0;i<n;i++)
cin>>v[i];
int case1=solve(0,n-2,v,n/3);
int case2=solve(1,n-1,v,n/3);
cout<<max(case1,case2);
return 0;
}
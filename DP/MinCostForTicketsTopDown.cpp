#include<iostream>
#include<vector>
using namespace std;
int solve(int n,int d[],int c[],int index,vector<int>&dp)
{
    if(index>=n)
    return 0;
    if(dp[index]!=-1)return dp[index];

    int option1=c[0]+solve(n,d,c,index+1,dp);

    int i;
    for(i=index;i<n&&d[i]<d[index]+7;i++);
    int option2=c[1]+solve(n,d,c,i,dp);

    for(i=index;i<n&&d[i]<d[index]+30;i++);
    int option3=c[2]+solve(n,d,c,i,dp);

    dp[index]=min(option1,min(option2,option3));
    return dp[index];
}
int main()
{
int n;
cout<<"Enter n:";
cin>>n;
int d[n],c[3];
cout<<"Enter days:";
for(int i=0;i<n;i++)
cin>>d[i];
cout<<"Enter costs:";
for(int i=0;i<3;i++)
cin>>c[i];
vector<int>dp(n+1,-1);
cout<<solve(n,d,c,0,dp);
   return 0;
}

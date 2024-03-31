#include<iostream>
#include<vector>
using namespace std;
int solve(int n,int d[],int c[])
{
    vector<int>dp(n+1,INT32_MAX);
    dp[n]=0;
    
    for(int k=n-1;k>=0;k--){

    int option1=c[0]+dp[k+1];

    int i;
    for(i=k;i<n&&d[i]<d[k]+7;i++);
    int option2=c[1]+dp[i];

    for(i=k;i<n&&d[i]<d[k]+30;i++);
    int option3=c[2]+dp[i];

    dp[k]=min(option1,min(option2,option3));
    }
    return dp[0];
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
cout<<solve(n,d,c);
   return 0;
}

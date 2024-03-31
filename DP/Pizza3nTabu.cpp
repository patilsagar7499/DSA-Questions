#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&v,int k)
{
    vector<vector<int>>dp1(k+2,vector<int>(k+2,0));
    vector<vector<int>>dp2(k+2,vector<int>(k+2,0));
    for(int Index=k-2;Index>=0;Index--){
        for(int n=1;n<=k/3;n++){
            int take=v[Index]+dp1[Index+2][n-1];
            int nottake=dp1[Index+1][n];
            dp1[Index][n]=max(take,nottake);
             }
    }
    for(int Index=k-1;Index>=1;Index--){
        for(int n=1;n<=k/3;n++){
            int take=v[Index]+dp2[Index+2][n-1];
            int nottake=dp2[Index+1][n];
            dp2[Index][n]=max(take,nottake);
             }
    }
    return max(dp1[0][k/3],dp2[1][k/3]);
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
cout<<solve(v,n);
return 0;
}
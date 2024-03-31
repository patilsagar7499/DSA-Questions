#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&v,int k)
{
    vector<int>prev1(k+2,0);
    vector<int>curr1(k+2,0);
    vector<int>next1(k+2,0);
    for(int Index=k-2;Index>=0;Index--){
        for(int n=1;n<=k/3;n++){
            int take=v[Index]+next1[n-1];
            int nottake=curr1[n];
            prev1[n]=max(take,nottake);
             }
             next1=curr1;
             curr1=prev1;
    }
    vector<int>prev2(k+2,0);
    vector<int>curr2(k+2,0);
    vector<int>next2(k+2,0);
    for(int Index=k-1;Index>=1;Index--){
        for(int n=1;n<=k/3;n++){
            int take=v[Index]+next2[n-1];
            int nottake=curr2[n];
            prev2[n]=max(take,nottake);
             }
             next2=curr2;
             curr2=prev2;
    }
    return max(curr1[k/3],curr2[k/3]);
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
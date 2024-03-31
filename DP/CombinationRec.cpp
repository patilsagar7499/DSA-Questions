#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&arr,int target)
{
    if(target<0)return 0;
    if(target==0)return 1;
    int ans=0;
    for(int i=0;i<arr.size();i++)
    {
        ans+=solve(arr,target-arr[i]);
    }
    return ans;
}
int main()
{
    int n,target;
    cout<<"Enter n and target:";
    cin>>n;
    cin>>target;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {cout<<"Enter:";
    cin>>arr[i];}
    cout<<solve(arr,target);
   return 0;
}

#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&w,vector<int>&v,int index,int capacity)
{
    if(index==0)
    {
        if(w[0]<=capacity)
        return v[0];
        else 
        return 0;
    }
    int include=0;
    if(w[index]<=capacity)
    {
        include=v[index]+solve(w,v,index-1,capacity-w[index]);}
        int exclude=solve(w,v,index-1,capacity);
        int ans=max(exclude,include);
        return ans;
    
}
int main()
{
  int W,n;
  cout<<"Enter weight:";
  cin>>W;
  cout<<"Enter no. of items:";
  cin>>n;
  vector<int> w(n),v(n);
  for(int i=0;i<n;i++)
  {
    cout<<"Enter w["<<i<<"]:";
    cin>>w[i];
    cout<<"Enter v["<<i<<"]:";
    cin>>v[i];
  }
  cout<<solve(w,v,n-1,W);
   return 0;
}

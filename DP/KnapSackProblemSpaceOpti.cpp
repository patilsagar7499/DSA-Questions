#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>&w,vector<int>&v,int capacity,int n)
{
    vector<int>prev(capacity+1,0);
    vector<int>curr(capacity+1,0);
    for(int i=w[0];i<=capacity;i++){
        if(w[0]<=capacity)
        prev[i]=v[0];
        else
        prev[i]=0;
    }

    for(int index=1;index<n;index++)
    {
        for(int i=0;i<=capacity;i++)
        {
            int include=0;
            if(w[index]<=i)
            include=v[index]+prev[i-w[index]];
            int exclude=prev[i];
            curr[i]=max(include,exclude);
        }
        prev=curr;
    }
    return prev[capacity];
    
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
  cout<<solve(w,v,W,n);
   return 0;
}

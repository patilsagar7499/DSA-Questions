#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>&w,vector<int>&v,int capacity,int n)
{
    vector<int>curr(capacity+1,0);
    for(int i=w[0];i<=capacity;i++){
        if(w[0]<=capacity)
        curr[i]=v[0];
        else
        curr[i]=0;
    }

    for(int index=1;index<n;index++)
    {
        for(int i=capacity;i>=0;i--)
        {
            int include=0;
            if(w[index]<=i)
            include=v[index]+curr[i-w[index]];
            int exclude=curr[i];
            curr[i]=max(include,exclude);
        }
    }
    return curr[capacity];
    
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

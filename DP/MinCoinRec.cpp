#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &num,int x)
{
    if(x==0)
    return 0;
    if(x<0)
    return INT32_MAX;
    int mini=INT32_MAX;
    for(int i=0;i<num.size();i++)
    {
        int ans=solve(num,x-num[i]);
        if(ans!=INT32_MAX)
        {
            mini=min(mini,1+ans);
        }
    }
    return mini;
}

int main()
{
    int n,x;
    cout<<"Enter n:";
    cin>>n;
    cout<<"Enter x:";
    cin>>x;
   vector<int> num(n);
   cout<<"Enter:";
   for(int i=0;i<n;i++)
   cin>>num[i];
   cout<<"O/p:"<<solve(num,x);
   return 0;
}

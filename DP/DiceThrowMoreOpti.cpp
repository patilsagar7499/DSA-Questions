#include<iostream>
#include<vector>
using namespace std;
int solve(int dice,int face,int target)
{
    vector<int>prev(target+1,0);
    vector<int>curr(target+1,0);
    prev[0]=1;
    for(int d=1;d<=dice;d++)
    {
        for(int t=1;t<=target;t++)
        {int ans=0;
        for(int k=1;k<=face;k++)
        {   if(t-k>=0)
            ans=ans+prev[t-k];}
         curr[t]=ans;
        }
        prev=curr;
    }
    return curr[target];
}
int main()
{
int n,m,x;
cout<<"Enter no. of dice,no. of faces,total sum:";
cin>>n>>m>>x;
cout<<solve(m,n,x);
return 0;
}
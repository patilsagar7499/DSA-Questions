#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&ob,int currlane,int currpos)
{
    int n=ob.size();
   if(currpos==n)return 0;
   if(currlane!=ob[currpos+1]) return solve(ob,currlane,currpos+1);
   else
   {
    int ans=INT32_MAX;
    for(int i=1;i<=3;i++)
    {
        if(currlane!=i&&ob[currpos]!=i)
        {
            ans=min(ans,1+solve(ob,i,currpos));
        }
    }
    return ans;
   }
   
}
int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<int> ob(n);
    cout<<"Enter:";
    for(int i=0;i<n;i++)
    cin>>ob[i];
    cout<<solve(ob,2,0);
   return 0;
}

#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&ob)
{
   int n=ob.size()-1;
   vector<int>curr(4,INT32_MAX);
   vector<int>next(4,INT32_MAX);
   next[0]=0;
   next[1]=0;
   next[2]=0;
   next[3]=0;

   for(int currpos=n-1;currpos>=0;currpos--){
    for(int currlane=1;currlane<=3;currlane++)
    {
        if(currlane!=ob[currpos+1]) curr[currlane]=next[currlane];
        else
        {
            int ans=1e9;
            for(int i=1;i<=3;i++)
            {
                if(currlane!=i&&ob[currpos]!=i)
                {
                    ans=min(ans,1+next[i]);
                }
                curr[currlane]=ans;
            }
        }
        next=curr;
   }
   }
    return min(next[2],min(1+next[1],1+next[3][0]));
  
   
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
    cout<<solve(ob);
   return 0;
}

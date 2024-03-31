#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&s,int n)
{
    vector<int>Curr(n+1,0);
    vector<int>Next(n+1,0);
    for(int curr =n-1;curr>=0;curr--)
    {
        for(int prev=curr-1;prev>=-1;prev--)
        {        
            int take=0;
            if(prev==-1||s[curr]>s[prev])
            take=1+Next[curr+1];
            int nottake=Next[prev+1];

    Curr[prev+1]=max(take,nottake);
        }
        Next=Curr;
    }

    return Next[0];
}
int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<int> s(n);
    cout<<"Enter elements:";
    for(int i=0;i<n;i++)
    cin>>s[i];
    cout<<solve(s,n);
   return 0;
}

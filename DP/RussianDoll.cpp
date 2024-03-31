#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int>a,pair<int,int>b)
{
    if(a.first==b.first)
    {return a.second>b.second;}
    return a.first<b.first;
}
int solve(vector<pair<int,int>>&s,int n)
{
    vector<int>Curr(n+1,0);
    vector<int>Next(n+1,0);
    for(int curr =n-1;curr>=0;curr--)
    {
        for(int prev=curr-1;prev>=-1;prev--)
        {        
            int take=0;
            if(prev==-1||s[curr].second>s[prev].second)
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
 vector<pair<int,int>>v;
 for(int i=0;i<n;i++)
 {
    int x,y;
    cin>>x>>y;
    v.push_back({x,y});
 }
 sort(v.begin(),v.end(),comp);
 cout<<solve(v,n);
return 0;
}
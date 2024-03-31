#include<bits/stdc++.h>
using namespace std;
bool check(vector<int>base,vector<int>newBox)
{
    if(newBox[0]<base[0]&&newBox[1]<base[1]&&newBox[2]<base[2])
    return true;
    else
    return false;
}
int solve(vector<vector<int>>&s,int n)
{
    vector<int>Curr(n+1,0);
    vector<int>Next(n+1,0);
    for(int curr =n-1;curr>=0;curr--)
    {
        for(int prev=curr-1;prev>=-1;prev--)
        {        
            int take=0;
            if(prev==-1||check(s[curr],s[prev]))
            take=s[curr][2]+Next[curr+1];
            int nottake=Next[prev+1];

    Curr[prev+1]=max(take,nottake);
        }
        Next=Curr;
    }

    return Next[0];
}
int maxHeight(vector<vector<int>>&v)
{
    for(auto &a:v)
    {
        sort(a.begin(),a.end());
    }
    sort(v.begin(),v.end());
    return solve(v,v.size());
}
int main()
{
    int n;
    cout<<"Enter n";
    cin>>n;
    vector<vector<int>>v(n,vector<int>(3));
    cout<<"Enter:";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
          cin>>v[i][j];
        }
    }
    cout<<maxHeight(v);
return 0;
}
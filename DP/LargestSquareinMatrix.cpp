#include<iostream>
using namespace std;
int solve(int a[4][5],int i,int j,int &maxi)
{
    if(i>3||j>4)
    return 0;

    int right=solve(a,i,j+1,maxi);
    int diagonal=solve(a,i+1,j+1,maxi);
    int down=solve(a,i+1,j,maxi);

    if(a[i][j]==1)
    {
       int ans=1+min(right,min(diagonal,down));
       maxi=max(maxi,ans);
       return ans;
    }
    else return 0;
}
int main()
{
    int a[4][5]={{1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,0,0}};
    int maxi=0;
    solve(a,0,0,maxi);
    cout<<maxi;
}

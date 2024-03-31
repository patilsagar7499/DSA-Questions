#include<iostream>
#include<vector>
using namespace std;
int solve(int a[4][5],int &maxi)
{
    int row=4;
    int col=5;

    vector<int>curr(col+1,0);
    vector<int>next(col+1,0);
    for(int i=row-1;i>=0;i--)
    {
        for(int j=col-1;j>=0;j--)
        {
          int right=curr[j+1];
          int diagonal=next[j+1];
          int down=next[j];

          if(a[i][j]==1)
         {
          curr[j]=1+min(right,min(diagonal,down));
          maxi=max(maxi,curr[j]);
         }
          else  curr[j]=0;
        }
        next=curr;
    }
    
    return curr[0];

    
}
int main()
{
    int a[4][5]={{1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,0,0}};
    int maxi=0;
    solve(a,maxi);
    cout<<maxi;
   return 0;
}

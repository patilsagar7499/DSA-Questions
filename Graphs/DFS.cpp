#include<iostream>
using namespace std;

void DFS(int i,int A[][8],int n)
{
    static int vi[8] {0};
    if(vi[i]==0)
    {
        cout<<i<<" ";
        vi[i]=1;
        for(int v=1;v<n;v++)
        {
            if(A[i][v]==1&&vi[v]==0)
            DFS(v,A,n);
        }
    }
}
int main()
{
    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
    DFS(4,A,8);
   return 0;
}

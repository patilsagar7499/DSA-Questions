#include<iostream>
#include<vector>
using namespace std;
int solve(int n,int k)
{  
    int prev2=k;
    int prev1=k*k;

    for(int i=3;i<=n;i++)
    {
        int curr=prev2*(k-1)+prev1*(k-1);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
int main()
{
   int n,k;
   cout<<"Enter:";
   cin>>n>>k;
  cout<<solve(n,k);
   return 0;
}

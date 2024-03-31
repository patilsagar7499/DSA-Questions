#include<iostream>
using namespace std;
int solve(int n,int x,int y,int z )
{
    if(n==0)
    return 0;
    if(n<0)
    return INT32_MIN;
    int a=solve(n-x,x,y,z)+1;
    int b=solve(n-y,x,y,z)+1;
    int c=solve(n-z,x,y,z)+1;

    return max(a,max(b,c));
}
int main()
{
   int n;
   cout<<"Length:";
   cin>>n;
   int x,y,z;
   cout<<"X,Y,Z:";
   cin>>x>>y>>z;
   int ans=solve(n,x,y,z);
   if(ans<0)
   cout<<0;
   else
   cout<<ans;
   return 0;
}

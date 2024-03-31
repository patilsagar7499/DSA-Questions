#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&v,int i,int j)
{
if(i+1==j)return 0;
int mini=INT32_MAX;
for(int k=i+1;k<j;k++)
{
  mini=min(mini,v[i]*v[j]*v[k]+solve(v,i,k)+solve(v,k,j));
}
return mini;
}
int main()
{
   int n;
   cout<<"Enter no. of edges:";
   cin>>n;
   vector<int> v(n);
   cout<<"Enter weight of vertices:";
   for(int i=0;i<n;i++)
   {
    cin>>v[i];
   }  
   cout<<solve(v,0,n-1);
   return 0;
}

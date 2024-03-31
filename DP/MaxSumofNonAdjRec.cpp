#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int> &num,int n)
{
   if(n<0)
   return 0;
   if(n==0)
   return num[0];
   int incl=solve(num,n-2)+num[n];
   int excl=solve(num,n-1);
   return max(incl,excl);
}
int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;
   vector<int> num(n);
   cout<<"Enter:";
   for(int i=0;i<n;i++)
   cin>>num[i];
   cout<<"O/p:"<<solve(num,n-1);
   return 0;
}

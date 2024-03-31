#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int> &num)
{
    int n=num.size();
    int prev2=0;
    int prev1=num[0];
    for(int i=1;i<n;i++)
    {
        int incl=prev2+num[i];
        int excl=prev1;
        int ans=max(incl,excl);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
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
   cout<<solve(num);
   return 0;
}

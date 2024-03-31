#include<iostream>
using namespace std;
int main()
{
 int n;
 cout<<"Enter no. of stairs:";
 cin>>n;
 int cost[n];
 for(int i=0;i<n;i++)
 {
    cout<<"Enter:";
    cin>>cost[i];
 }
 int prev2=cost[0];
 int prev1=cost[1];
 for(int i=2;i<n;i++)
 {
    int curr=cost[i]+min(prev1,prev2);
    prev2=prev1;
    prev1=curr;
 }
 cout<<min(prev1,prev2);
   return 0;
}

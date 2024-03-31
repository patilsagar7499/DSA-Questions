#include <bits/stdc++.h>
using namespace std;
int solve(int n,int days[],int cost[])
{
  int ans=0; 
  queue<pair<int,int>> month;
  queue<pair<int,int>> week;

  for(int i=0;i<n;i++)
  {
    int day=days[i];
    //Step1:remove expired days
    while(!month.empty()&&month.front().first+30<=day)
    month.pop();
    while(!week.empty()&&week.front().first+7<=day)
    week.pop();

    //Step2:add cost for current day
    week.push(make_pair(day,ans+cost[1]));
    month.push(make_pair(day,ans+cost[2]));

    //Step3:ans update
    ans=min(ans+cost[0],min(week.front().second,month.front().second));
  }
  return ans;
}
int main()
{
   int n;
cout<<"Enter n:";
cin>>n;
int days[n],cost[3];
cout<<"Enter days:";
for(int i=0;i<n;i++)
cin>>days[i];
cout<<"Enter costs:";
for(int i=0;i<3;i++)
cin>>cost[i];
cout<<solve(n,days,cost);
   return 0;
}

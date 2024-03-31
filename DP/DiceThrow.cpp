#include<iostream>
using namespace std;
int solve(int dice,int face,int target)
{
    if(target<0)return 0;
    if(dice!=0&&target==0)return 0;
    if(dice==0&&target!=0)return 0;
    if(dice==0&&target==0)return 1;
    int ans=0;
    for(int i=1;i<=face;i++)
    {
        ans=ans+solve(dice-1,face,target-i);
    }
    return ans;
}
int main()
{
int n,m,x;
cout<<"Enter no. of dice,no. of faces,total sum:";
cin>>n>>m>>x;
cout<<solve(m,n,x);
return 0;
}
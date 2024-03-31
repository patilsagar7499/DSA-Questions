#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter:";
    cin>>n;
    int prev1=1;
    int prev2=0;
    int count;
    if(n==0)cout<<0;
    else{
        for(int i=2;i<=n;i++)
        {
            count=prev1+prev2;
            prev2=prev1;
            prev1=count;
        }
        cout<<prev1;
    }
   return 0;
}

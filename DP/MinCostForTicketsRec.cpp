#include<iostream>
using namespace std;
int solve(int n,int d[],int c[],int index)
{
    if(index>=n)return 0;

    //1 day pass
    int option1=c[0]+solve(n,d,c,index+1);

    int i;
    //7 day pass
    for(i=index;i<n&&d[i]<d[index]+7;i++);
    int option2=c[1]+solve(n,d,c,i);

    //30 day pass
    for(i=index;i<n&&d[i]<d[index]+30;i++);
    int option3=c[2]+solve(n,d,c,i);

    return min(option1,min(option2,option3));
}
int main()
{int n;
cout<<"Enter n:";
cin>>n;
int d[n],c[3];
cout<<"Enter days:";
for(int i=0;i<n;i++)
cin>>d[i];
cout<<"Enter costs:";
for(int i=0;i<3;i++)
cin>>c[i];
cout<<solve(n,d,c,0);
   return 0;
}

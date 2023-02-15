#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no. of letters:";
    cin>>n;
    char a[n];
    cout<<"Enter:";
    cin>>a;
    long int h=0,x=0;
    for(int i=0;a[i]!='\0';i++)
    {
        x=1;
        x=x<<(a[i]-97);
        if((x&h)>0)
        cout<<a[i]<<" ";
        else
        h=x|h;
    }
}
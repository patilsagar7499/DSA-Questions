#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no. of elements:";
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter:";
        cin>>A[i];
    }
     int diff=A[0];
    cout<<"Missing elements:";
    for(int i=0;i<n;i++)
    {
        if(diff!=A[i]-i)
        {
            while(diff<A[i]-i)
            {
                cout<<diff+i<<" ";
                diff++;
            }
        }
    }
}
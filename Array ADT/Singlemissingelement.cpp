#include<iostream>
using namespace std;
void nnaturalno(int n)
{
   cout<<"Enter starting "<<n<<" natural no.s:"<<endl;
   int A[n];
   for(int i=0;i<n;i++)
   {
     cout<<"Enter:";
     cin>>A[i];
   }
   int sum=0;
   for(int i=0;i<n-1;i++)
   {
       sum=sum+A[i];
   }
   int s=(n*(n+1))/2;
   cout<<"Missing no:"<<s-sum<<endl;
}
void sorted(int n)
{
     cout<<"Enter sorted elements:"<<endl;
     int B[n];
     for(int i=0;i<n;i++)
     {
         cout<<"Enter:";
         cin>>B[i];
     }
     int diff=B[0];
     for(int i=0;i<n;i++)
     {
         if(B[i]-i!=diff)
         {
             cout<<"Missing no:"<<i+diff<<endl;
             break;
         }
         
     }
}

int main()
{
    int n;
    do{
    cout<<"Enter 1)n Natural no., 2)Sorted, 3)Exit:"<<endl;
    cin>>n;
    switch(n)
    {
        
        case 1:
        int x;
        cout<<"Enter no. of terms :";
        cin>>x;
        nnaturalno(x);
        break;
        case 2:
        cout<<"Enter no. of terms :";
        cin>>x;
        sorted(x);
        break;
        
    }
    }while(n!=3);
}
#include<iostream>
using namespace std;
void array(int arr[],int n)
{
   for(int i=0;i<n;i++)
   {
       cout<<arr[i]<<" ";
   }
}
int main()
{
    int a[5]={1,2,3,4,5};
    array(a,5);
}
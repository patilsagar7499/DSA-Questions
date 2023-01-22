#include<iostream>
using namespace std;
 int fun(int n)                   
 {
     if(n==0)
     return 0;
     return fun(n-1)+n;
 }
// int fun(int n){
//  int s=0;
//  for(int i=1;i<=n;i++)
//   {
//   s=s+i;
//   }
//    return s;
// }
int main()                                
{
   cout<<fun(5);
}
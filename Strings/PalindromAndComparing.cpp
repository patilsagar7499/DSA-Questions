#include<iostream>
using namespace std;
void compare(char A[],char B[])
{
   int i,j;
   for(i=0, j=0;A[i]!='\0'&&B[j]!='\0';i++,j++)
   {
       if(A[i]!=B[j])
       break;
   }
   if(A[i]==B[j])cout<<"Equal"<<endl;
   else if(A[i]>B[j])cout<<A<<" is larger than "<<B<<endl;
   else cout<<A<<" is smaller than "<<B<<endl;
   }
void palindrom(char A[])
{
    char temp;
    int i,j;
    for(i=0;A[i]!='\0';i++)
    {}
    i=i-1;
    for(j=0;i>=0;i--,j++)
    {
        if(A[i]!=A[j])
        break;
    }
    if(A[i]==A[j])cout<<"Palindrom";
    else cout<<"Not a Palindrom";

}
int main()
{
  int n1,n2;
  cout<<"Enter the length of two strings:";
  cin>>n1>>n2;
  char A[n1];
  char B[n2];
  cout<<"Enter two strings:";
  cin>>A>>B;
  compare(A,B);
  palindrom(A);
}
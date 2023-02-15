#include<iostream>
using namespace std;
void method1(char A[])
{
    char B[6];
    int i,j;
    for(i=0;A[i]!='\0';i++)
    {
        
    }
        i=i-1;
        for(j=0;i>=0;i--,j++)
        {
           B[j]=A[i];
        }
   
    B[j]='\0';
    cout<<B<<endl;
}
void method2(char A[])
{
    char temp;
    int i,j;
    for(i=0;A[i]!='\0';i++)
    {}
    i=i-1;
    for(j=0;i>j;i--,j++)
    {
       temp=A[i];
       A[i]=A[j];
       A[j]=temp;
    }
    cout<<A;
}
int main()
{
    char A[]="Sagar";
    method1(A);
    method2(A);
}
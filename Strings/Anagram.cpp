#include<iostream>
using namespace std;
void method1(char s[],char p[],int n)
{
   for(int i=0;i<n;i++)
   {
       if(s[i]>=0){
       for(int j=0;j<n;j++)
       {
          if(s[i]==p[j])
          {
              s[i]=-1;
              p[j]=-1;
          }
       }
       }
    int count=0;
    for(int i=0;i<n;i++)
    {
     if(s[i]==-1)
     count++;
    }
   }
   int count=0;
   for(int i=0;i<n;i++)
   {
      if(s[i]==-1)
      count++;
    }
   if(count==n)
       cout<<"Anagram";
       else
       cout<<"NotAnagram";
}
void hashtable(char s[],char p[],int n)
{
    int i;
    int h[26]={0};
    for(i=0;i<n;i++)
    h[s[i]-97]++;
    for(i=0;p[i]!='\0';i++)
    {h[p[i]-97]--;
    if(h[i]-97<0)
    {cout<<"NotAnagram";
     break;}
    }
    if(p[i]=='\0')
    cout<<"Anagram";
}
int main()
{
    int n;
    cout<<"Enter no. of letters:";
    cin>>n;
    char s[n],p[n];
    cout<<"Enter string 1:";
    cin>>s;
    cout<<"Enter string 2:";
    cin>>p;
    //method1(s,p,n);
    hashtable(s,p,n);
}
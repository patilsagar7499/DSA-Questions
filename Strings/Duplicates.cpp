#include<iostream>
using namespace std;
void duplicate1(char s[],int n)
{
      for(int i=0;i<n-1;i++)
      {
          int j=i+1;
          int count=1;
          if(s[i]!=0){
          while(j<n)
          {
              if(s[i]==s[j])
              {
                 count++;
                 s[j]=0;
              }
              j++;
          }
          if(count>1)
          cout<<s[i]<<"->"<<count<<" times.";
          }
      }
}
void hashtable(char s[],int n)
{
     int h[26];
     for(int i=0;i<26;i++)
     {
         h[i]=0;
     }
     for(int i=0;i<n;i++)
     {
         h[s[i]-97]++;
     }
     for(int i=0;i<26;i++)
     {
         if(h[i]>1){
         cout<<char(97+i)<<"->"<<h[i]<<" times.";
         }
     }
}
int main()
{
   int n;
   cout<<"Enter no. of letters:";
   cin>>n;
   char s[n];
   cout<<"Enter string:";
   cin>>s;
   //duplicate1(s,n);
   hashtable(s,n);
}
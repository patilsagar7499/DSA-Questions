#include<iostream>
using namespace std;
int check(char* s)
{
   for(int i=0;s[i]!='\0';i++)
   {
       if(!(s[i]>=65&&s[i]<=90)&&!(s[i]>=97&&s[i]<=122)&&!(s[i]>=48&&s[i]<=57))
       return 0;
   }
   return 1;
}
int main()
{
    char *s="nmfdk3409ndjkdba";
    check(s);
    if(check(s))
    cout<<"Valid";
    else
    cout<<"Not Valid";
}
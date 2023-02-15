#include<iostream>
using namespace std;
int main()
{
    char s[]="My name is Sagar";
    int v=0,c=0;
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
        v++;
        else if((s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122))
        c++;
    }
    cout<<"Vowel:"<<v<<endl;
    cout<<"Consonant:"<<c<<endl;
    int x=1;
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]==' '&&s[i-1]!=' ')
        x++;
    }
    cout<<"Words:"<<x;
}
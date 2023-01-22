#include<iostream>
using namespace std;
int main()
{
    int a=10;
    int &p=a;
    cout<<a<<endl;
    p++;
    cout<<p<<endl;
    cout<<a;
}
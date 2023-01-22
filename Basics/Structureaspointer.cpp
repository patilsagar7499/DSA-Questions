#include<iostream>
using namespace std;
struct Rectangle
{
    int length;
    int breadth;
};
int changelength(Rectangle *r,int l)
{ 
    r->length=l;
  return r->length;  
}
int main()
{
    Rectangle r={10,15};
    cout<<changelength(&r,20);
}
#include<iostream>
using namespace std;
struct Rectangle
{
   int length;
   int breadth;
};
int main()
{
    Rectangle r={10,5};
    cout<<r.length<<" "<<r.breadth<<endl;
    
    Rectangle *p=&r;
    cout<<p->length<<" "<<p->breadth;

    // Rectangle *p;
    // p=new Rectangle;
    // p->length=15;
    // p->breadth=10;
    // cout<<p->length<<" "<<p->breadth;
}
#include<iostream>
using namespace std;
class Rectangle{
 int length;
 int breadth;
 public:
 Rectangle(int l,int b){  //Constructor
   length=l;
   breadth=b;
   cout<<"Initial length:"<<length<<endl;
 }
 int area()
 {
     return length*breadth;
 }
 void changelength(int l)
 {
     length=l;
     cout<<"Final length:"<<length;
 }
};
int main()
{
    Rectangle r(15,10);
    cout<<"Area:"<<r.area()<<endl;
    r.changelength(20);
}
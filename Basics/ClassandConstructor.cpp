#include<iostream>
using namespace std;
class Rectangle
{
private:
    int length;
    int breadth;
public:
    Rectangle(){length=breadth=1;}
    Rectangle(int l,int b);
    int area();
    int setlength(int l);
    int getlength();
    ~Rectangle();    
};

Rectangle::Rectangle(int l,int b)
{
    this->length=l;      //we can directly use length=l;
    this->breadth=b;     //lly we can use breadth=b;
}

int Rectangle::area()
{
    return length*breadth;
}
int Rectangle::setlength(int l)
{
    length=l;
}
int Rectangle::getlength()
{
    cout<<length<<endl;
}
Rectangle::~Rectangle()
{cout<<"Destructor";}
int main()
{
    Rectangle r(15,10);
    cout<<"Area:"<<r.area()<<endl;
    r.setlength(20);
    r.getlength();
}
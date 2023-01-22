#include<iostream>
using namespace std;
template <class T>
class Arithmetic
{
  T length;
  T breadth;
  public:
  Arithmetic(T l,T b);
  T add();
  T sub();
};
template <class T>
Arithmetic<T>::Arithmetic(T l,T b)
{
    length=l;
    breadth=b;
}
template <class T>
T Arithmetic<T>::add()
{
  T c=length+breadth;
  return c;
}
template <class T>
T Arithmetic<T>::sub()
{
T c=length-breadth;
  return c;
}
int main()
{
    Arithmetic<int> a(15,10);
    cout<<"Sum:"<<a.add()<<endl;
    cout<<"Sub:"<<a.sub()<<endl;
    Arithmetic<float> a1(15.5,10.5);
    cout<<"Sum:"<<a1.add()<<endl;
    cout<<"Sub:"<<a1.sub()<<endl;
}
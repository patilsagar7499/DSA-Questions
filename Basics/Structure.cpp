#include<iostream>
using namespace std;
struct Rectangle
{
int length;
int breath;
};
int main( )
{
struct Rectangle r ; // Declaration
// we can also use struct Rectangle r = { 10, 5 } ; Declaration + Initialisation
r.length = 15 ; // Is is used to access a member
r.breath = 10 ;
cout<< " Area of rectangle is:" << r.length * r.breath  ; //Accessing the members

}
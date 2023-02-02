#include<iostream>
using namespace std;
class Array{

int *A;
int size;
int length;

public:
Array(int size)
{
    size=size;
}
void create()
{
    cout<<"Enter no. of elements:";
    cin>>length;
    cout<<"Values of element:";
    for(int i=0;i<length;i++)
    {
        cin>>A[i];
    }
}
void get(int key)
{
    if(key>=0&&key<length)
    cout<<"Element:"<<A[key]<<endl;
}
void set(int key,int value)
{
    if(key>=0&&key<length)
    A[key]=value;
}
void maximum()
{
    int maxi=INT_MIN;
    for(int i=0;i<length;i++)
    {
       maxi=max(maxi,A[i]);
    }
    cout<<"Maximum:"<<maxi<<endl;
}
void minimum()
{
    int mini=INT_MAX;
    for(int i=0;i<length;i++)
    {
       mini=min(mini,A[i]);
    }
    cout<<"Minimum:"<<mini<<endl;
}
void total()
{
   int total=0;
   for(int i=0;i<length;i++)
   {
       total=total+A[i];
   }
   cout<<"Sum:"<<total<<endl;
}
int rectotal(int length)
{
     if(length<0)
     return 0;
     else
     return rectotal(length-1)+A[length];
}
};
int main()
{
  Array arr(10);
  arr.create();
//   int key;
//   cout<<"Enter index: ";
//   cin>>key;
//   arr.get(key);
//   int value;
//   cout<<"Enter the new value at index"<<key<<":";
//   cin>>value;
//   arr.set(key,value);
arr.maximum();
arr.minimum();
//arr.total();
cout<<"Total:";

cout<<arr.rectotal(5);
}
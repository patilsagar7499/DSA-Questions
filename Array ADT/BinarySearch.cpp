#include<iostream>
using namespace std;
class Array{

private:
int *A;
int length;
int size;

public:
Array(int size)
{
    this->size=size;
}
void create()
{
    cout<<"Enter length:";
    cin>>length;
    cout<<"Enter elements:";
    for(int i=0;i<length;i++)
    {
        cin>>A[i];
    }
}
int binarysearch(int key)
{
    int l=0,h=length-1;
    
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(A[mid]==key)
        return mid;
        else if(A[mid]>key)
        h=mid-1;
        else if(A[mid]<key)
        l=mid+1;
    }
    return -1;
}
int recbinarysearch(int l,int h,int key)
{
    
    if(l<=h)
    {
        int mid=(l+h)/2;
        if(A[mid]==key)
        return mid;
        else if(A[mid]>key)
        recbinarysearch(l,mid-1,key);
        else if(A[mid]<key)
        recbinarysearch(mid+1,h,key);
    }
}
void display()
{
    for(int i=0;i<length;i++)
    {
        cout<<A[i]<<" ";
    }
}
};
int main()
{
  Array arr(10);
  arr.create();
  arr.display();
  cout<<endl;
  cout<<"Index:";
  //cout<<arr.binarysearch(3);
  cout<<arr.recbinarysearch(0,5,3);
}
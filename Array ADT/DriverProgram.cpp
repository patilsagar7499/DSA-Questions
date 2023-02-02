#include<iostream>
using namespace std;
class Array{
  int *A;
  int size;
  int length;

  public:
  Array()
  {
    size=10;
    length=0;
    A=new int[10];
  }
  Array(int size)
  {
    size=size;
    length=0;
    A=new int[size];
  }
  ~Array()
  {
    delete []A;
  }
  void insert(int value,int index)
  {
    if(index>=0&&index<=length)
    {
      for(int i=length-1;i>=index;i--)
      {
        A[i+1]=A[i];
      }
      A[index]=value;
      length++;
    }
  }
  int search(int value)
  {
    for(int i=0;i<length;i++)
    {
      if(A[i]==value)
      return 1;
    }
    return 0;
  }
  void sum()
  {
    int sum=0;
    for(int i=0;i<length;i++)
    {
      sum=sum+A[i];
    }
    cout<<sum<<endl;
  }
  void deletee(int index)
  {
     if(index>=0&&index<=length)
     {
       int x=A[index];
       for(int i=index;i<length-1;i++)
       {
         A[i]=A[i+1];
       }
       length--;
     }
  }
  void display()
  {
    for(int i=0;i<length;i++)
    {
      cout<<A[i]<<" ";
    }
    cout<<endl;
  }
};
int main()
{
   Array arr;
   int n;
   do{
   cout<<"Enter:1)Insert,2)Search,3)Sum,4)Delete,5)Display,6)Exit"<<endl;
   cin>>n;
   switch (n)
   {
   case 1:
     int value,key;
     cout<<"Enter element to be inserted and it's index:";
     cin>>value>>key;
     arr.insert(value,key);
     break;
   case 2:
     cout<<"Enter element to be searched:";
     cin>>value;
     cout<<arr.search(value);
     cout<<endl;
     break;
   case 3:
     arr.sum();
     break;
   case 4:
     cout<<"Enter index of which element is to be deleted:";
     cin>>key;
     arr.deletee(key);
     break;
   case 5:
     arr.display();
     break;
   }


   }while(n!=6);
}
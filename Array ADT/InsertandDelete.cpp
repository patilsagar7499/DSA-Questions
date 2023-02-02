#include<iostream>
using namespace std;
class Array{
private:
   int* A;
   int length;
   int size;
public:
   Array(int size)
   {
       this->size=size;
   }
     void create(){
        cout << "Enter number of elements: " << flush;
        cin >> length;
        cout << "Enter the array elements: " << endl;
        for (int i = 0; i < length; i++){
            cout << "Array element: " << i << " = " << flush;
            cin >> A[i];
        }
    }
   void append(Array *arr,int x)
   {
       if(length<size)
       {
           A[length++]=x;
       }
   }
   void insert(Array *arr,int index,int x)
   {
       int i;
       if(index>=0 && index <=length)
       {
           for(i=length;i>index;i--)
           A[i]=A[i-1];
           A[index]=x;
           length++;
       }
   }
   int Delete(Array *arr,int index)
   {
       int x=0;
       if(index>=0&&index<length)
       {
           x=A[index];
           for(int i=index;i<length-1;i++)
           {
               A[i]=A[i+1];
           }
               length--;
           
           return x;
       }
       return 0;
   }
   void Display(Array arr)
   {
       int i;
       cout<<"\nElements are\n";
       for(i=0;i<length;i++)
       cout<<A[i]<<" ";
   }

};
int main()
{
    Array arr(10);
    arr.create();
    arr.append(&arr,10);
    arr.insert(&arr,0,12);
    arr.Display(arr);
    arr.Delete(&arr,2);
    arr.Display(arr);
}
#include<iostream>
using namespace std;
class Array{
private:
int *A;
int size;
int length;
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

void display()
{
    for(int i=0;i<length;i++)
    cout<<A[i]<<" ";
}
int swap(int x1,int x2)
{
    int temp=x1;
    x1=x2;
    x2=temp;
}
int linearsearch(int key)
{
     for(int i=0;i<length;i++)
     {
         if(A[i]==key)
         return i;
         swap(A[i],A[i-1]); //Transposition
         //swap(A[i],A[0]);  move to front
     }
     return -1;
}
};
int main()
{
      Array arr(10);
      arr.create();
      arr.display();
      cout<<"Index:";
      cout<<arr.linearsearch(3);
}
#include<iostream>
using namespace std;
class UpperTri{
   int *A;
   int n;
   public:
   UpperTri()
   {
       n=2;
       A=new int[2*(2+1)/2];
   }
   UpperTri(int n)
   {
       this->n=n;
       A=new int[n*(n+1)/2];
   }
   ~UpperTri()
   {delete []A;}

   void set(int i,int j,int x);
   int get(int i,int j);
   void Display();
   int GetDimension(){return n;}
};
void UpperTri::set(int i,int j,int x)
{
    if(i<=j)
    A[((i-1)*n)-(((i-2)*(i-1))/2)+(j-i)]=x;  //For column representation A[(j*(j-1)/2)+i-1]=x;
}
int UpperTri::get(int i,int j)
{
 if(i<=j)
 return A[((i-1)*n)-(((i-2)*(i-1))/2)+(j-i)];  //For column representation A[(j*(j-1)/2)+i-1];

 else
 return 0;
}
void UpperTri::Display()
 {  int i,j;
  cout<<"Matrix:"<<endl;
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
    {
      if(i<=j)
      cout<<A[((i-1)*n)-(((i-2)*(i-1))/2)+(j-i)] <<" ";  //For column representation A[(j*(j-1)/2)+i-1];
    
      else
      cout<<"0 ";
    }
    cout<<endl;
  }
 }
int main()
{
  int d;
  cout<<"Enter Dimensions:";
  cin>>d;
  UpperTri lm(d);
  int x;
  cout<<"Enter all Elements:";
  for(int i=1;i<=d;i++)
  {
      for(int j=1;j<=d;j++)
      {
          cin>>x;
          lm.set(i,j,x);
      }
  }
lm.Display();
}
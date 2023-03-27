#include<iostream>
using namespace std;
class LowerTri{
   int *A;
   int n;
   public:
   LowerTri()
   {
       n=2;
       A=new int[2*(2+1)/2];
   }
   LowerTri(int n)
   {
       this->n=n;
       A=new int[n*(n+1)/2];
   }
   ~LowerTri()
   {delete []A;}
   
   void create();
   void set(int i,int j,int x);
   int get(int i,int j);
   void Display();
   int GetDimension(){return n;}
};
void LowerTri::create()
{
    cout<<"Enter:";
    int x;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>x;
            if(i==j)
            A[i-1]=x;
        }
    }
}
void LowerTri::set(int i,int j,int x)
{
    if(i>=j)
    A[i*(i-1)/2+j-1]=x;  //For column representation A[n*(j-1)-(j-2)*(j-1)/2+i-j]=x;
}
int LowerTri::get(int i,int j)
{
 if(i>=j)
 return A[i*(i-1)/2+j-1];  //For column representation A[n*(j-1)-(j-2)*(j-1)/2+i-j];

 else
 return 0;
}
void LowerTri::Display()
 {  int i,j;
  cout<<"Matrix:"<<endl;
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
    {
      if(i>=j)
      cout<<A[i*(i-1)/2+j-1] <<" ";  //For column representation A[n*(j-1)-(j-2)*(j-1)/2+i-j];
    
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
  LowerTri lm(d);
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
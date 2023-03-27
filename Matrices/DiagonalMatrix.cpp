#include<iostream>
using namespace std;
class Diagonal{
   int *A;
   int n;
   public:
   Diagonal()
   {
       n=2;
       A=new int[2];
   }
   Diagonal(int n)
   {
       this->n=n;
       A=new int[n];
   }
   ~Diagonal()
   {delete []A;}
   
   void create();
   void set(int i,int j,int x);
   int get(int i,int j);
   void Display();
};
void Diagonal::create()
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
void Diagonal::set(int i,int j,int x)
{
    if(i==j)
    A[i-1]=x;
}
int Diagonal::get(int i,int j)
{
 if(i==j)
 return A[i-1];
 else
 return 0;
}
void Diagonal::Display()
 {  int i,j;
 cout<<"Matrix:";
  for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
    {
      if(i==j)
      cout<<A[i] <<" ";
      else
      cout<<"0 ";
    }
    cout<<endl;
  }
 }
int main()
{
  int n;
  cout<<"Enter order:";
  cin>>n;
  Diagonal m(n);
  m.create();
  m.Display();
  m.set(1,1,5);m.set(2,2,8);m.set(3,3,9),m.set(4,4,12);
  m.Display();
  cout<<m.get(2,2);

}
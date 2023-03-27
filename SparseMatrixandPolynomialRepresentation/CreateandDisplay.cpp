#include<iostream>
using namespace std;
class Element
{
  public:
  int i;
  int j;
  int x;
};
class Sparse
{
  int m;
  int n;
  int num;
  Element *ele;
  public:
  Sparse(int m,int n,int num)
  {
      this->m=m;
      this->n=n;
      this->num=num;
      ele=new Element[this->num];
  }
  ~Sparse()
  {
      delete []ele;
  }
  void read()
  {
      cout<<"Enter elements:";
      for(int i=0;i<num;i++)
      {
          cin>>ele[i].i>>ele[i].j>>ele[i].x;
      }
  }
  void display()
  {
      int k=0;
      for(int i=0;i<m;i++)
      {
          for(int j=0;j<n;j++)
          {
              if(i==ele[k].i&&j==ele[k].j)
              cout<<ele[k++].x<<" ";
              else
              cout<<"0 ";

          }
          cout<<endl;
      }
  }
};
int main()
{
 Sparse s(5,5,5);
 s.read();
 s.display();
 return 0;
}
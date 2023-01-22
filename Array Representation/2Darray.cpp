#include<iostream>
using namespace std;
int main()
{
    int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int *b[3];
    b[0]=new int[3];
    b[1]=new int[3];
    b[2]=new int[3];
    int **c;
    c=new int*[3];
    c[0]=new int [3];
    c[1]=new int [3];
    c[2]=new int [3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        cout<<c[i][j]<<" ";
        cout<<endl;
    }
}
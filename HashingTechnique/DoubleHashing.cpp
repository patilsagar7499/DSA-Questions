#include<iostream>
using namespace std;
int Hash1(int key)
{return key%10;}
int Hash2(int key)
{return 7-(key%7);}
int probe(int H[],int val)
{
    int index1=Hash1(val);
    int index2=Hash2(val);
    int i=0;
    while(H[(index1+i*index2)%10]!=0)
        i++;
    return (index1+i*index2)%10;
}
void insert(int H[],int val)
{
    int index=Hash1(val);
    if(H[index]!=0)
     index=probe(H,val);
    H[index]=val;
}
int search(int H[],int val)
{
    int index1=Hash1(val);
    int index2=Hash2(val);
    int i=0;
    while(H[(index1+i*index2)%10]!=val&&H[(index1+i*index2)%10]!=0)
        i++;
    if(H[(index1+i*index2)%10]==val)    
    return (index1+i*index2)%10;
    else return -1;
}
int main()
{
    int H[10]={0};
    insert(H,5);
    insert(H,25);
    insert(H,15);
    insert(H,35);
    insert(H,95);
    for(int i=0;i<10;i++)
    cout<<H[i]<<" ";
    cout<<endl;
    cout<<search(H,95)<<endl;
    cout<<search(H,11);
   return 0;
}

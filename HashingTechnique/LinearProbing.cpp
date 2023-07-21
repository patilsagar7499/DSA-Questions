#include<iostream>
using namespace std;
int Hash(int key)
{return key%10;}
int probe(int H[],int val)
{
    int index=Hash(val);
    int i=0;
    while(H[(index+i)%10]!=0)
        i++;
    return (index+i)%10;
}
void insert(int H[],int val)
{
    int index=Hash(val);
    if(H[index]!=0)
     index=probe(H,val);
    H[index]=val;
}
int search(int H[],int val)
{
    int index=Hash(val);
    int i=0;
    while(H[(index+i)%10]!=val&&H[(index+i)%10]!=0)
        i++;
    if(H[(index+i)%10]==val)    
    return (index+i)%10;
    else return -1;
}
int main()
{
    int H[10]={0};
    insert(H,12);
    insert(H,15);
    insert(H,25);
    insert(H,26);
    for(int i=0;i<10;i++)
    cout<<H[i]<<" ";
    cout<<endl;
    cout<<search(H,26)<<endl;
    cout<<search(H,11);
   return 0;
}

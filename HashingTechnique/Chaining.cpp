#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
class HashTable{
    public:
    Node** HT;
    HashTable()
    {
        HT=new Node* [10];
        for(int i=0;i<10;i++)
        {
            HT[i]=NULL;
        }
    }
    int hash(int key)
    {return  key%10;}
    void Insert(int key)
    {
           int hIdx=hash(key);
           Node* t=new Node(key);
           if(HT[hIdx]==NULL)
           HT[hIdx]=t;
           else
           {
            Node* p=HT[hIdx];
            Node* q=HT[hIdx];
            while(p&&p->data<key)
            {
                q=p;
                p=p->next;
            }
            if(q==HT[hIdx])
            {
                t->next=HT[hIdx];
                HT[hIdx]=t;
            }
            else
            {
                t->next=q->next;
                q->next=t;
            }
           }
    }
    int Search(int key)
    {
        int hIdx=hash(key);
        Node* p=HT[hIdx];
        while (p)
        {
            if(p->data==key)
            return p->data;
            p=p->next;
        }
        return -1;        
    }
    ~HashTable()
    {
        for(int i=0;i<10;i++)
        {
            Node* p=HT[i];
            while (HT[i])
            {
                HT[i]=HT[i]->next;
                delete p;
                p=HT[i];
            }
            
        }
        delete[] HT;
            }
};
int main()
{
    int A[]={1,5,2,4,3,61,92,72,65,55};
    int n=sizeof(A)/sizeof(A[0]);
    HashTable H;
    for(int i=0;i<n;i++)
    H.Insert(A[i]);
    int key=72;
    int value=H.Search(key);
    cout<<"Key:"<<key<<",Value:"<<value<<endl;
   return 0;
}

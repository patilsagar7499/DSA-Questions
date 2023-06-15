#include<iostream>
#include<stack>
using namespace std;
class queue{
    stack<int> e_stk;
    stack<int> d_stk;
    public:
    void enqueue(int x)
    {
        e_stk.push(x);
    }
    int dequeue()
    {
        int x=-1;
        if(d_stk.empty())
        {
            if(e_stk.empty())
            {
                cout<<"Queue is Empty";
                return x;
            }
            else
            {
                while(!e_stk.empty())
                {
                    d_stk.push(e_stk.top());
                    e_stk.pop();
                }
            }
            
        }
        x=d_stk.top();
        d_stk.pop();
        return x;
    }
};
int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<q.dequeue()<<" ";
    cout<<q.dequeue()<<" ";
    cout<<q.dequeue()<<" ";
   return 0;
}

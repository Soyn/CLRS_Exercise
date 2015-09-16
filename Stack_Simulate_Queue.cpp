#include <iostream>
#include <stack>

/**
* @Brief:This program is to use two stacks to simulate a queue.
* Created by Soyn.15/9/15.
**/


template<class T>
class myQueue
{
public:
    myQueue(){}
    ~myQueue(){}
    void  Enqueue(T t);
    void Dequeue();
    T myFront();
private:
    std :: stack<T> stk, helpStack;
};

template<class T>
void myQueue<T>::Enqueue(T t)
{
    helpStack.push(t);
}

template<class T>
void myQueue<T> :: Dequeue()
{
   if(!stk.empty())
        stk.pop();
    else{
        if(!helpStack.empty())
        {
            while(!helpStack.empty())
            {
                stk.push(helpStack.top());
            }
        }else
        {
            std :: cout << "ERROR pop" << std :: endl;
        }
    }
}

template<class T>
T myQueue<T> :: myFront()
{
        while(!helpStack.empty())
        {
            stk.push(helpStack.top());
            helpStack.pop();
        }
        return stk.top();
}

int main(void)
{
   myQueue<int> a;
   for( int i = 0; i < 10; ++i)
        a.Enqueue(i);
    for(int i= 0; i < 10; ++i)
    {
        std :: cout << a.myFront() << ' ';
        a.Dequeue();
    }


}

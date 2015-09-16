#include<iostream>
#include<queue>

/**
* This program is to use two queues to simulate a stack.
* Created by Soyn.15/9/15.
**/



///<summary> to push a elem into the stack</summary>
///<para name = "elem"> the elem will be pushed into the stack</para name>

template<class T>
class myStack
{
public:
    myStack() {}
    ~myStack() {}
    T top();
    void pop();
    void push(T t);
private:
    std::queue<T> que, helpQueue;
};

template<class T>
T myStack<T> :: top()
{
    //push the element which pop() from the helpQueue, until one last.
    while(helpQueue.size() > 1)
    {
        que.push(helpQueue.front());
        helpQueue.pop();
    }

    T tmp = helpQueue.front();   //reserve the value and return
    que.push(helpQueue.front());
    helpQueue.pop();

    while(que.size() != 0)
    {
        helpQueue.push(que.front());
        que.pop();
    }
    return tmp;
}

template<class T>
void myStack<T>::pop()
{
    while(helpQueue.size() > 1)
    {
        que.push(helpQueue.front());
        helpQueue.pop();
    }
    helpQueue.pop();

    while(que.size() != 0)
    {
        helpQueue.push(que.front());
        que.pop();
    }
}

template<class T>
void myStack<T>::push(T t)
{
    helpQueue.push(t);
}

int main(void)
{
    myStack<int> a;
    for( int i = 0; i < 10; ++i)
        a.push(i);

    for(int i = 0; i < 10; ++i)
    {
        std :: cout << a.top() << std :: endl;
        a.pop();
    }
    return 0;
}

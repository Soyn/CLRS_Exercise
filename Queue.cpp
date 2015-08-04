#include<iostream>

//!
//! define ENQUEUE and DEQUEUE
//! Created by Soyn. 4/8/15.
//!
#define Len 12
int tail, head;

void ENQUEUE(int *Queue,const int &elem)
{

    if( (tail + 1) % Len == head){
        std :: cout << "The Queue overflow!" << std::endl;
    }else{
        Queue[tail % Len] = elem;
        ++tail;
    }
}

int DEQUEUE(int *Queue)
{

    if(head== tail){
        std :: cout << "Queue underflow!" << std::endl;
        return -1;
    }else{
        return Queue[(head++) % Len];
    }
}

void TestENQUEUE(int *Q)
{
    ENQUEUE(Q,15);
    ENQUEUE(Q,6);
    ENQUEUE(Q,9);
    ENQUEUE(Q,8);
    ENQUEUE(Q,4);
    ENQUEUE(Q,17);
    ENQUEUE(Q,3);
    ENQUEUE(Q,5);
}

void TestDEQUEUE(int *Q)
{
     int DeElem;
    do{
        DeElem = DEQUEUE(Q);
        std :: cout << DeElem << " , ";
    }while(DeElem != -1);
}
int main(void)
{
    int Q[Len] = {0};
    head = tail = 6;
    TestENQUEUE(Q);
    TestDEQUEUE(Q);
    return 0;
}

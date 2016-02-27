#ifndef MINQUEUE_H_INCLUDED
#define MINQUEUE_H_INCLUDED
/******************************
*
* Construct the minimum heap.
* Created Time: 30/1/16.
* Ahthor: Soyn.
*
*******************************/

#include <vector>
#include <iostream>
struct node{
    char alpha;
    int frequence;
    node *left, *right;
};
class MinQueue{
public:
    MinQueue(node*, std :: size_t);
    ~MinQueue(){}

    inline int LEFT(const int);
    inline int RIGHT(const int);
    inline int CalculateHeapSize();
    inline node HeapMinimum();
    inline int PARENT(const int);

    void MinHeapify(int);
    node HeapExtractMin();
    void HeapDecreaseKey(int,node&);
    void Exchange(int,int);
    void BuildMinHeap();
    void MinHeapInsert(node&);

    void Print();
private:
    node t = {'0',-1};
    std :: vector<node> vec;
    int HeapSize;
};

#endif // MINQUEUE_H_INCLUDED

#ifndef HUFFMAN_H_INCLUDED
#define HUFFMAN_H_INCLUDED

#include "MinQueue.h"
#include <iostream>
/*************************
*
* Huffman tree head file
* Created Time: 30/1/16.
* Author: Soyn
*
**************************/


class Huffman{
public:
    Huffman(node *t, size_t s) : Q(t,s){}
    void Print();
    ~Huffman(){}
    node* BuildHuffmanTree();
    void MiddleTravel(node *t);
private:
    MinQueue Q;
    node *root;
};



#endif // HUFFMAN_H_INCLUDED

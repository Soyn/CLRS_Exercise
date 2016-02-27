#include "Huffman.h"


void Huffman :: Print()
{
    Q.Print();
}

node * Huffman :: BuildHuffmanTree()
{
    auto s = Q.CalculateHeapSize();
    Q.BuildMinHeap();
    for(size_t i = 1; i < s ; ++i){
        node *InternalNode = new(node);
        node x,y;
        x = Q.HeapExtractMin();
        y = Q.HeapExtractMin();
        InternalNode -> left = &x;
        InternalNode -> right = &y;
        InternalNode -> frequence = (InternalNode -> left -> frequence) + (InternalNode -> right -> frequence);
        Q.MinHeapInsert(*InternalNode);
        Print();
        if((i + 1) == s)
            root = InternalNode;
    }
    return root;
}

void Huffman :: MiddleTravel(node *t)
{
    if(t){
        MiddleTravel(t -> left);
        std :: cout << t -> alpha;
        MiddleTravel(t -> right);
    }
}

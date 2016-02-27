#ifndef BINOMIALHEAP_H_INCLUDED
#define BINOMIALHEAP_H_INCLUDED


#include <vector>

/******************************************
* @Author: Soyn
* @Brief: the header file of binomial heap.
* @CreatedTime: 20/2/16.
*******************************************/

// @Brief: the underlying data structure to store the data.
// Sample usage:
// Node *new_node = new Node();
// new_node -> key = 10;
// new_node -> degree = 1;
// new_node -> child = new_node -> sibling = new_node -> parent = nullptr;
struct Node{
    int key;
    int degree;
    Node *child,*sibling,*parent;
};

// @Brief:the binomial heap, to define an object of binomial heap.
// Sample usage:
// BinomialHeap obj(int_vec);
class BinomialHeap{
public:
    // The default constructor, no return value, to initialize the data member.
    // it will initialize the head_ and int_vec with default
    // initializer of list, and initializes the numbers_ with 0.
    BinomialHeap() : numbers_(0){}

    // The constructor overloaded, takes the vector<int>'s reference to
    // initialize the data member. No return value.
    BinomialHeap(const std :: vector<int>& int_vec) : int_vec_(int_vec), numbers_(int_vec.size()){}
    ~BinomialHeap(){}

    // To create a new heap, return the pointer points the heap head, it's
    // the deconstructor's responsibility to delete the pointer.
    BinomialHeap *MakeBinomialHeap() const;

    // Return the pointer which points to the minimum value in the heap,it's
    // not valid to change the heap.
    Node *BinomialHeapMinimum();

    // No return, to link the two binomial tree to a new binomial tree.
    void BinomialLink(Node&, Node &);

    // Merge two heaps into one heap.
    // Takes the references of two heap, it's the function's responsibility
    // to free the two head after merge-sort complete.
    void BinomialHeapMerge(BinomialHeap &, BinomialHeap &);

    // To merge two heap into one, takes two heap head reference.
    void BinomialHeapUnion(BinomialHeap&, BinomialHeap&);

    // Insert a node into the heap, takes the
    // reference to the node being inserted.
    void BinomialHeapInsert(Node &);

    // Return the pointer points to the minimum key node in the heap,
    // and splits the minimum node from heap.Need user to delete the node.
    // Sample usage:
    // Node *minimum_heap_node = obj_of_BinomialHeap.BinomialHeapExtractMin();
    // ......... // do something
    // delete minimum_heap_node;
    Node *BinomialHeapExtractMin();

    // To decrease the specified key node value in the heap, takes the pointer
    // which points the specified node,and the value it will  decrease to.
    void BinomialHeapDecreaseKey(Node *, int);

    // To delete the specified key node in the heap,
    // takes the pointer which will be deleted.
    void BinomialHeapDelete(Node *DelKey);

    // To sort the head_ list by degree.
    void SortByDegree();
private:
    std :: vector<int> int_vec_;
    Node *head_;
    std :: size_t numbers_; //the numbers of nodes in he heap.
};
#endif // BINOMIALHEAP_H_INCLUDED

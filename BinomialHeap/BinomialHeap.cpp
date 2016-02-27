#include "BinomialHeap.h"
#include <iostream>
#include <algorithm>
#include <iterator>

/***************************************
* @Author: Soyn
* @Brief: the implement of binomial heap
* @CreatedTime: 20/2/2016.
****************************************/

// Return a new head of heap, using default constructor.
BinomialHeap* BinomialHeap :: MakeBinomialHeap() const
{
    BinomialHeap *new_head = new BinomialHeap();
    return new_head;
}

// Return the minimum key-node's pointer in heap.
Node *BinomialHeap :: BinomialHeapMinimum()
{
    Node *minimum_heap_node = head_;
    Node *cur = head_;

    if(cur == nullptr)
        return nullptr;

    while(cur != nullptr){
        if(cur->key < minimum_heap_node->key){
            minimum_heap_node = cur;
        }
        cur = cur->sibling;
    }
    return minimum_heap_node;
}

// Link two binomial tree which have the same degree into one.
// By change the child, sibling and parent pointer to link two binomial
// tree into one.And the new parent's degree
// need to update after link completes.
void BinomialHeap :: BinomialLink(Node &child_node, Node &parent_node)
{
    child_node.parent = &parent_node;
    child_node.sibling = parent_node.child;
    parent_node.child = &child_node;
    ++parent_node.degree;
}

// Sort the head_ list, implement by selected sort.
// Algorithm implement details:
// We need to find the minimum node by degree when we traverse
// the list every, and we split the minimum node from the original list,
// and add it into the sorting list until there is only one node.
// @Note: the origin list's length will minus 1 after the traverse complete.
// And if there is no one needed to be splited, it implies the start node is
// the minimum node.
void BinomialHeap :: SortByDegree()
{
    Node *prev_cur = nullptr, *cur = head_;
    if(cur == nullptr)
        return;
    Node *next_cur = cur->sibling, *start = head_;
    Node *cur_sorting_list = nullptr;
    while(start->sibling){
        Node *minimum_degree_node = start;
        bool exchange = false;

        for(cur = start; cur != nullptr; cur = cur->sibling){
            if(cur->sibling->degree < minimum_degree_node->degree){
                prev_cur = cur;
                next_cur = cur->sibling;
                exchange = true;
            }
        }
        if(exchange){
            Node *current_mini_node = prev_cur->sibling;
            current_mini_node->sibling = nullptr;
            prev_cur->sibling = next_cur;
            if(start != head_){
                cur_sorting_list->sibling = current_mini_node;
                cur_sorting_list = current_mini_node;
            }else{
                cur_sorting_list = head_ = current_mini_node;
            }
        }else{
            cur_sorting_list->sibling = start;
            Node *start_temp = start->sibling;
            start->sibling = nullptr;
            start = start_temp;
        }
    }
}

// To merge the two heap into one by sorting the head list by degree.
// Implement by merge_sort.
// @Note:
// the procedure of merge uses the library algorithm 'insert' which
// returns the iterator refer to the new added. After sorting complete,
// the head1 and head2 will be free.
void BinomialHeap ::BinomialHeapMerge(BinomialHeap &head1, BinomialHeap &head2)
{
    head1.SortByDegree();
    head2.SortByDegree();
    auto cur = head2.head_.begin();
    for(auto iter = head1.head_.begin(); iter != head1.head_.end(); ++iter){
        if((*iter).degree > (*cur).degree){
            iter = head1.head_.insert(iter,*cur);
            ++cur;
        }
    }

    if(cur != head2.head_.end()){
        while( cur != head2.head_.end()){
            head1.head_.push_back(*cur);
        }
    }

    copy(head1.head_.begin(),head1.head_.end(),back_inserter(head_));

    delete &head1;
    delete &head2;

}

// The procedure to union two heap into one binomial heap, and keep the
// properties of binomial heap.
//
// Here is the algorithm implement's brief:
// There are four cases in the procedure.
// @parameter: prev_cur, cur, next_cur denote the node in the list respectively.
//
// Case1: the cur and next_cur's degree are not equal, and cur's
// degree < next's degree, we need only to update these three pointers.
//
// Case2: the degree[cur] , degree[next_cur] and sibling[next_cur] are equal,
// after we update  pointers, we enter into the case3 or case4.
//
// Case3: the cur and next_cur's degree are equal, but key[cur] < key[next_cur],
// and need to link the two binomal tree into ine.
//
// Case4: case4 similar to case3, but the key[cur] > key[next_cur].
//
void BinomialHeap :: BinomialHeapUnion(BinomialHeap &head1, BinomialHeap &head2)
{
    BinomialHeapMerge(head1,head2);
    Node *prev_cur = nullptr;
    Node *cur = &head_[0];
    Node *next_cur = cur->sibling;
    while(next_cur){
        if((cur->degree != next_cur->degree) || ((next_cur->sibling != nullptr)
            && ((next_cur->sibling->degree) == (cur->degree)))){
                prev_cur = cur;  // case1 and case2
                cur = next_cur;
            }else{
                if(cur->key < next_cur->key){  // case3
                    BinomialLink(*next_cur,*cur);
                }else{  // case4
                    if(prev_cur){
                       prev_cur->sibling = next_cur;
                    }
                    BinomialLink(*cur,*next_cur);
                    cur = next_cur;
                }
            }
            cur = next_cur;
    }
}

int main(int argc, char **argv)
{
    return 0;
}


#include "union_sets.h"
#include <iostream>
/*******************************************
* @Author: Soyn
* @Brief: The implement of union sets,
* if you want to check more details, please
* read the CLRS or go to Wiki.
* @CreatedTime: 6/3/16.
*/

// @Brief: the constructor which takes the vector, and invoke the MakeSet()
UnionSets :: UnionSets(std :: vector<char> &char_vec){
    head_ = tail_ = nullptr;
    MakeSet(char_vec);
}
//
// @Brief: Create new set, which represented by head_
// @Implement details: Traverse the vector, and create node whick key_
// is the value in the vector, link all the node and let each node's
// pointer_to_head points to the head_.
//
void UnionSets :: MakeSet(std :: vector<char> &char_vec){
    for(auto iter = char_vec.begin(); iter != char_vec.end(); ++iter){
        Node *new_node = new Node(*iter);
        if(head_){
            tail_ = tail_->next = new_node;
        }else{
            head_ = tail_ = new_node;
        }
        tail_->pointer_to_head = head_;
    }
}

//
// @Brief: link two sets into one set.
// @Implement details: Link the linked_sets after the tail_,
// then change all the pointer_to_head in
// linked_set points to head_.
//
void UnionSets :: Union( UnionSets &linked_set){
    tail_->next = linked_set.head_;

    for(auto iter = linked_set.head_; iter != linked_set.tail_;
    iter = iter->next){
        iter->pointer_to_head = head_;
    }

    tail_ = linked_set.tail_;
    linked_set.tail_->pointer_to_head = head_;
}

//
// @Brief: Find the specified set in the sets
// @Implement details: Just need to traverse the set, but
// note to check the tail.
// @Note: like this for(auto iter = head_; iter <= tail_; iter = iter->next)
// is not allowed.(ps: the sets in storage is not contiguous.)
//
UnionSets* UnionSets :: FindSet(char const &target)
{
    for(auto iter = head_; iter != tail_; iter = iter->next){
        if(iter->key_ == target){
            return this;
        }
    }

    if(tail_->key_ == target){
        return this;
    }
    return nullptr;
}
void UnionSets :: Print()
{
    auto beg = head_;
    do{
        std :: cout << beg->key_ << " behalf node: "<< beg->pointer_to_head->key_<< std :: endl;
        beg = beg -> next;
    }while(beg != tail_);
    std :: cout << beg->key_;
}

Node* UnionSets :: GetHead() const{
    return head_;
}
int main(int argc, char **argv)
{

    return 0;
}

#ifndef UNION_SETS_H_INCLUDED
#define UNION_SETS_H_INCLUDED

#include <vector>
/*********************************
* @Author: Soyn
* @Brief: Implement the union sets
* @CreayedTime: 6/3/16
**********************************/

// @Brief: define the node in the list

struct Node{
    char key_;
    Node *next;
    Node *pointer_to_head;
    Node(char key) : key_(key){};
};

class UnionSets{
public:
    UnionSets() : head_(nullptr), tail_(nullptr){}
    ~UnionSets(){}

    // @Brief: The constructor self-defined.
    // @Param char_vec: The input sequence.
    UnionSets(std :: vector<char> &char_vec);

    // @Brief: Create a new set, which repesented by elem node.
    // @Param elem: the vactor which stores the key.
    // @Return: void
    void MakeSet(std :: vector<char> &char_vec);

    // @Brief: Union two sets into one set.
    // @Param linked_set: the refernce refers to the sets.
    // @Return: void
    void Union(UnionSets &linked_set);

    // @Brief: Find the target set in the sets.
    // @Param target: the target set.
    // @Return: if founded, then retrun the pointer points to
    // the represented node in the set, if not return null.
    UnionSets* FindSet(char const&target);
    Node *GetHead () const;
    void Print();
private:
    Node *head_;
    Node *tail_;
};
#endif // UNION_SETS_H_INCLUDED

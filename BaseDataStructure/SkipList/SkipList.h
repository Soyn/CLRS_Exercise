#ifndef SKIPLIST_H_INCLUDED
#define SKIPLIST_H_INCLUDED

/*
* The head file for skip list
*/

#include <vector>


typedef struct node{
    int value;
    node *Predessor;
    node *Successor;
    node *UpLevel;
    node *DownLevel;
    node(int t) : value(t){}
}Node;

class SkipList{
public:
    // the constructor & destructor
    SkipList(int t);
    ~SkipList(){}
    bool PromoteOrNot();
    Node *Search(int);
    void InsertList(int);
    void DeleteList(int);
    void InsertIntoBottomList();
private:
    Node *InsertedPosition;

    /*for keep the head level*/
    std :: vector<Node*> Heads;
    Node *top;
};
#endif // SKIPLIST_H_INCLUDED

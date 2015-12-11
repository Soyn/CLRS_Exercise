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
    SkipList();
    ~SkipList(){}
    bool PromoteOrNot();
    void PromoteProcess(Node*);
    Node *GetCopyNode(Node*);
    Node *Search(Node*,int);
    void InsertList(int);
    void DeleteList(int);
    void InsertIntoBottomList(Node*);
    inline Node* AddNewLevel();
    void InsertNewNodeInHighLevel(Node*, Node*);

private:

    /*for keep the head level*/
    std :: vector<Node*> Heads;
    Node *entrance;
    size_t level;
};
#endif // SKIPLIST_H_INCLUDED

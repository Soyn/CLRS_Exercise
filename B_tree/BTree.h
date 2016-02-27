#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED

#include <vector>
#include <string>

/**********************************
*
* @Brief: the header file of B-Tree.
* Author: Soyn.
* Created Time: 13/2/16.
*
************************************/

struct BTNode{
    int num;
    std :: vector<std :: string> key;
    bool leaf;
    std :: vector<BTNode*> pBTNode;
};

class BTree{
public:
    BTree(){}
    BTree(int x) :t(x){}
    ~BTree(){}
    void BTreeCreate();
    void BTreeSplitChild(BTNode&,size_t, BTNode&);
    void BTreeInsert(const std :: string &);
    void BTreeInsertNotFull(BTNode&, const std :: string&);
    void Print(BTNode&);
    void Print1();
    inline void DiskWrite();
    inline void DiskRead();
private:
    BTNode *root;
    int t;
};
#endif // BTREE_H_INCLUDED

#include <iostream>
#include "BTree.h"

/************************************
*
* @Brief: The implement of B-Tree.
* Author: Soyn.
* Created Time: 13/2/16.
*
*************************************/

void BTree :: DiskWrite()
{
    std :: cout << "Disk Write Complete." << std :: endl;
}

void BTree :: DiskRead()
{
    std :: cout << "Disk Read Complete." <<std :: endl;
}

void BTree :: BTreeCreate()
{
    BTNode *newNode = new BTNode();
    newNode -> leaf = true;
    newNode -> num = 0;
    DiskWrite();
    root = newNode;
}

///
/// <summary> the procesure to split the child. </summary>
/// <para name = "parents"> the parent node. <para name>
/// <para name = "index"> the subscript of the key in parents, which refers to the childS. </para name>
/// <para name = "child"> the child is full, which will be splited. </para name>
///

void BTree :: BTreeSplitChild(BTNode &parents, size_t index, BTNode &child)
{
    //{ create the new child
    BTNode *newChild = new BTNode();
    newChild -> leaf = child.leaf;
    newChild -> num = t - 1;
    //}

    for(int j = 0; j < t - 1; ++j){
        // copy the t-1 elements' key from child to new child.
        (newChild -> key).push_back((child.key)[j + t]);
    }

    if(!(child.leaf)){
        for( int j = 0; j < t - 1; ++j)
            (newChild -> pBTNode).push_back((child.pBTNode)[j + t]);
    }
    child.num = t - 1;

    if(!parents.pBTNode.empty()){
        parents.pBTNode.resize(parents.pBTNode.size() + 1);
        for(size_t i = parents.num + 1; i <= index; ++i){
            (parents.pBTNode)[i + 1] = (parents.pBTNode)[i];
        }
        (parents.pBTNode)[index + 1] = newChild;
    }else{
        parents.pBTNode.push_back(newChild);
    }
    // add the new child's pointer into the parents' pointer container.
    (parents.pBTNode).push_back(newChild);

    if(parents.num > 0){
        parents.key.resize(parents.num + 1);
        for(size_t j = parents.num; j >= index; --j)
            (parents.key)[j + 1] = (parents.key)[j];
        (parents.key)[index] = child.key[t - 1];
    }else{
        parents.key.push_back((child.key)[t-1]);
    }
    ++(parents.num);
    (child.key).resize(t - 1); // to erase the extra elements which have copyed into the new child already.
}

void BTree :: BTreeInsert(const std :: string &keyWord)
{
    BTNode *r = root;
    if((root -> num) == (2 * t - 1)){
        // if root is full, we need to create a new root.
        BTNode *s = new BTNode();
        root = s;
        s -> leaf = false;
        s -> num = 0;
        (s -> pBTNode).push_back(r);
        BTreeSplitChild(*s,0,*r);
        BTreeInsertNotFull(*s,keyWord);
    }else{
        BTreeInsertNotFull(*r,keyWord);
        Print((*root));
    }

}

void BTree :: BTreeInsertNotFull(BTNode &t, const std :: string &keyWord)
{
    size_t index = t.num - 1;
    if(t.leaf){
        // if t is leaf, we only need to insert the keyWord.
        if( t.num > 0){
        while( (index >= 1) && (keyWord < (t.key)[index]))
            --index;
        (t.key).resize(t.num + 1);
        for(size_t j = t.num; j > index; --j){
            (t.key)[j] = (t.key)[j - 1];
            //std ::cout << t.key[j] << std :: endl;
        }

        if(index > 0){
                (t.key)[index + 1] = keyWord;
        }else{
            if((t.key)[index] < keyWord)
                (t.key)[index + 1] = keyWord;
            else
                (t.key)[index] = keyWord;

        }

        }else{
            (t.key).push_back(keyWord);
        }
        t.num += 1;
    }else{
        // otherwise, we need to find a leaf node to insert our keyword.
        while((index > 0) && ( keyWord < ((t.key)[index])))
            --index;


        BTNode &tChild = *((t.pBTNode)[index]);
        if((tChild.num == (2 * (this -> t)  - 1))){
            BTreeSplitChild(t,index,tChild);

            if( keyWord > t.key[index])
                ++index;
        }
        tChild = *(t.pBTNode)[index];
        BTreeInsertNotFull(tChild, keyWord);

    }

}

void BTree :: Print(BTNode &t)
{


    for( auto e : t.key)
        std :: cout << e << ",";
    std :: cout << std ::endl;
    std :: cout << "t.num: " << t.num << " || ";
    std ::cout << "(t.key).size:" << t.key.size() << std :: endl;
}

int main(int argc, char **argv)
{
    BTree t(4);
    t.BTreeCreate();
    t.BTreeInsert("s");
    t.BTreeInsert("q");
    t.BTreeInsert("o");
    t.BTreeInsert("t");
    return 0;
}

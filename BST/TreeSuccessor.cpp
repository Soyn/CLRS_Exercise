#include <iostream>
#include "BinaryTree/BinaryTree.h"
#include "BinaryTree/Traversal_Recursion.h"
/**
* This is a program to get the successor of a node in specified tree.
* Created by Soyn.17/9/15.
**/
///
/// <summary>the procedure to get the sucessor node's value</summary>
/// <para name = "t">the node in the tree</para name>
/// <para name = "key">the point which points to the node's value we want to return.</ para name>
/// <return var> the node's value</return var>
///

int TreeSuccessor( node* t, node* key)
{
    if(key -> right) // if key's right tree is not NULL, its successor node is the leftest node(i.e. the minmum nod in the tree of key.)
    {
        return Minmum(key -> right);
    }

    node* tmp = key -> parents;

    while(tmp!= NULL && key == tmp -> right)
    {
        key = tmp;
        tmp = tmp -> parents;
    }

    return tmp -> key;
}

int main(int argc, char *argv[])
{

    int a[11] = {15,6,3,2,4,7,13,9,18,17,20};
    node* root = BinaryTree(a,11);
    MiddOrderTraversal(root);
    std :: cout << TreeSuccessor(root, Search(root,15)) << std :: endl;
    return 0;
}

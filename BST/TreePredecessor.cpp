#include <iostream>
#include "BinaryTree/BinaryTree.h"
#include "BinaryTree/Traversal_Recursion.h"

/**
*   This is a program to get the predecessor node of a specified node.
*   Created by Soyn.    21/9/15.
**/

int TreePredecessor(node *t, node* key)
{
    if(key -> left)
    {
        return Maxnum(key -> left);
    }
    node *tmp = key -> parents;
    while(tmp && key == tmp -> left)
    {
        key = tmp;
        tmp = tmp -> parents;
    }
    return tmp -> key;
}

int main(void)
{
    int a[11] = {15,6,3,2,4,7,13,9,18,17,20};
    node* root = BinaryTree(a,11);
    std :: cout << TreePredecessor(root, Search(root,9)) << std :: endl;
    return 0;
}

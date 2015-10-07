#include <iostream>
#include "BinaryTree/BinaryTree.h"
#include "BinaryTree/Traversal_Recursion.h"

/**
*   Insert a node into a binary search tree.
*   Created by Soyn. 21/9/15.
**/
node* TreeInsert(node* t, node* var)
{
    node *prev= NULL, *curr = t;
    while(curr)
    {
        prev = curr;
        if( var -> key < curr -> key)
            curr = curr -> left;
        else
            curr = curr -> right;
    }

    var -> parents = prev;

    if( prev == NULL)
        return var;
    else{
        if( var -> key < prev -> key)
            prev -> left = var;
        else
            prev -> right = var;
    }
    return t;
}
int main(void)
{
      int a[11] = {15,6,3,2,4,7,13,9,18,17,20};
      node* root = BinaryTree(a,11);

      node* insertNode = new node();
      insertNode -> left = insertNode -> right = insertNode -> parents = NULL;
      insertNode -> key = 22;

      root = TreeInsert(root,insertNode);
      MiddOrderTraversal(root); //for test
    return 0;
}

#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include <iostream>
#include <memory>


/**
* Created by Soyn.10/9/15.
* To created a binary tree.
**/
/// <summary>The following is the procedure to create a binary tree.</summary>

typedef struct node
{
    struct node *parents;
    struct node *left;
    struct node *right;
    int key;
} node;

/// <para name = "*a"> the array which stores the tree node.</para name>
/// <para name = "n"> the size of the array</para name>
///
node *BinaryTree( int *a, int n)
{
    node *root = NULL,*prev, *curr,*newnode;
    for( int i = 0; i < n; ++i)
    {
        curr = root;
        newnode = new node();
        newnode -> left = newnode -> right = newnode -> parents = NULL;
        newnode -> key = a[i];
        if(root){
            while(curr){
                prev = curr;
                if( newnode -> key <= curr -> key)
                    curr = curr ->left;
                else
                    curr = curr -> right;
            }

            if( newnode -> key > prev ->key)
            {
                prev -> right = newnode;
                newnode -> parents= prev;
            }else{
                prev -> left = newnode;
                newnode -> parents = prev;
        }
        }
        else
        {
            root =  newnode;
        }
    }
    return root;
}



#endif // BINARYTREE_H_INCLUDED

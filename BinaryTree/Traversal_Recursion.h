#ifndef TRAVERSAL_RECURSION_H_INCLUDED
#define TRAVERSAL_RECURSION_H_INCLUDED

#include "BinaryTree.h"

///
///Created by Soyn.10/9/15.
/// <summary>These functions are used to print the elements in the binary tree, and i use the recursion to complete them.</summary>
/// <para name = "root">the root node of the binary tree.</para name>
///

void PrevOrderTraversal(node *root)
{
    if( root != NULL){
        std :: cout << root -> key << std :: endl;
        PrevOrderTraversal(root -> left);
        PrevOrderTraversal(root -> right);
    }
}

void MiddOrderTraversal(node *root)
{
    if(root != NULL)
    {
        MiddOrderTraversal(root -> left);
        std :: cout << root -> key << std :: endl;
        MiddOrderTraversal(root -> right);
    }
}

void PostOrderTraversal(node *root)
{
    if(root != NULL)
    {
        PostOrderTraversal(root -> left);
        PostOrderTraversal(root -> right);
        std :: cout << root -> key<< std :: endl;
    }
}


#endif // TRAVERSAL_RECURSION_H_INCLUDED

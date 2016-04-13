#ifndef TRAVERSAL_ITERATION_H_INCLUDED
#define TRAVERSAL_ITERATION_H_INCLUDED

#include "BinaryTree.h"
#include <stack>

//
// @Author: Soyn
// @Brief: These functions are used to print the elements in the binary tree,
// and i use the iteration to complete them
// @CreatedTime: 10/9/15.
// Refactor by Soyn at 13/4/16.

void PrevOrderTraversalIter(node *root);
void PostOrderTraversalIter( node *root);
void MiddOrderTraversal_Iter(node *root);
#endif // TRAVERSAL_ITERATION_H_INCLUDED

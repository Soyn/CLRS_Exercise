#ifndef TRAVERSAL_ITERATION_H_INCLUDED
#define TRAVERSAL_ITERATION_H_INCLUDED

#include "BinaryTree.h"
#include <stack>

///
///Created by Soyn.10/9/15.
/// <summary>These functions are used to print the elements in the binary tree, and i use the iteration to complete them.</summary>
/// <para name = "root">the root node of the binary tree.</para name>
///

void PrevOrderTraversal_Iter(node *root)
{
    if( root == NULL) return;

    std :: stack<node*> stk;
    stk.push(root);
    while( !stk.empty())
    {
        node *curr = stk.top();
        stk.pop();
        std :: cout << curr -> key << std :: endl;
        if( curr -> right) stk.push(curr -> right);
        if( curr -> left) stk.push( curr -> left);
    }
}

void PostOrderTraversal_Iter( node *root)
{
    if( root == NULL) return;
    std::stack<node*> stk,helpStack;
    stk.push(root);
    while( !stk.empty())
    {
        node *curr = stk.top();
        stk.pop();
        helpStack.push(curr);
        std :: cout << "push" << curr -> key << std :: endl;
        if(curr -> left) stk.push( curr -> left);
        if( curr -> right )stk.push( curr -> right);
    }

    while( !helpStack.empty())   // In PrevOrderTraversal_Iter(), the order in stack is root ==> right ==> left, if we reverse the order (i.e. left ==> right ==> root) we can get the order we need.
    {
        std :: cout << helpStack.top() -> key<< ' ';
        helpStack.pop();
    }
}
void MiddOrderTraversal_Iter(node *root)
{
    std::stack<node* > stk;
    node *curr = root;
    while( curr != NULL || !stk.empty())
    {
        if( curr != NULL)
            stk.push(curr), curr = curr -> left;
        else
        {
            curr = stk.top();
            stk.pop();
            std :: cout << curr -> key << std :: endl;
            curr = curr -> right;
        }
    }
}
#endif // TRAVERSAL_ITERATION_H_INCLUDED

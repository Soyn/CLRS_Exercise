#include "TraversalIteration.h"
#include <iostream>
/*******************
* @Author: Soyn
* @Brief: Traversing the binary tree iteratively.
* @CreatedTime: 10/9/15.
* Refactor by Soyn at 13/4/16.
********************/

//
// @Brief: The previous order traversal iteratively.
// @Param root: The pointer points to the root of the binary tree.
void PreOrderTraversalIter(node *root)
{
    if(!root)
        return;

    std :: stack<node*> stk;
    stk.push(root);
    while(!stk.empty()){
        node *curr = stk.top();
        stk.pop();
        std :: cout << curr->key << " ";
        if(curr->right)
            stk.push(curr->right);
        if(curr->left)
            stk.push(curr->left);
    }
}

//
// @Brief: The post order traversal iterativeky.
// @Param root: The pointer points to the root of the binary tree.
void PostOrderTraversalIter(node *root)
{
    if(!root)
        return;
    std ::stack<node*> stk, helper_stack;
    helper_stack.push(root);
    while(!helper_stack.empty()){
        node *curr = stk.top();
        stk.push(curr);
        helper_stack.pop();
        if(curr->right)
            helper_stack.push(curr->right);
        if(curr->left)
            helper_stack.push(curr->left);
    }

    // The order of post order traversal is opposite to
    // the previous order traversal.
    while(!stk.empty()){
        std :: cout << stk.top() << std :: endl;
        stk.pop();
    }

}

//
// @Brief: The middle order traversal iteratively.
// @Param root: The pointer points to the root of the binary tree.
void MiddOrderTraversalIter(node *root)
{
    std :: stack<node*> stk;
    node *current = root;
    while(current || !stk.empty()){
        if(current){
            stk.push(current);
            current = current->left;
        }else{
            current = stk.top();
            stk.pop();
            std :: cout << current->key << std :: endl;
            current = current->right;
        }
    }
}

int main(int argc, char **argv)
{
    return 0;
}

#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include <iostream>
#include <memory>

typedef struct node
{
    struct node *parents;
    struct node *left;
    struct node *right;
    int key;
} node;

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
            std :: cout << "root not null\n";
            while(curr){
                prev = curr;
                if( curr -> key <= newnode -> key)
                    curr = curr ->left;
                else
                    curr = curr -> right;
            }

            if( newnode -> key > prev ->key)
            {
                std :: cout << "I'm linked in right-subtree\n";
                prev -> right = newnode;
                newnode -> parents= prev;
            }else{
                std ::cout << "I'm linked in left-subtree\n";
                prev -> left = newnode;
                newnode -> parents = prev;
        }
        }
        else
        {
            std :: cout << "root is NULL\n";
            root =  newnode;
        }
    }
    return root;
}

void freeTree(node *root)   //delete tree
{
    if( root != NULL){
        freeTree( root -> left);
        delete root;
        freeTree( root -> right);
    }
}

void PrevOrderTraversal(node *root)
{
    if( root != NULL){
        std :: cout << root -> key << std :: endl;
        PrevOrderTraversal(root -> left);
        PrevOrderTraversal(root -> right);
    }
}

#endif // BINARYTREE_H_INCLUDED

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

///
/// <summary> create the binary tree.</summary>
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

///
/// <summary>to get the minmum key in the key</summary>
/// <para name = "t"> the node in the tree</para name>
///

int Minmum(node* t)
{
    int Min = t -> key;

    while(t -> left)
    {
        //std :: cout << t -> key << ' ';
        t = t -> left;
        Min = t -> key;
    }
    return Min;
}

///
/// <summary> to get the maximum node in binary tree.</summary>
/// <para name> the root node at the subtree.</para name>
/// <return> the pointer points to the max node.</return>
///

int Maxnum(node* t)
{
    int Max = t -> key;
    while(t -> right)
    {
        t = t -> right;
        Max = t -> key;
    }
    return Max;
}

///
/// <summary>to search the specified value in the tree.</summary>
/// <para name = "t"> the node in the tree</para name>
/// <para name = "key"> the key to search</ para name>
/// <return var> the node address</return var>
///
node * Search(node *t,int key)
{
    while(t)
    {
        if( t -> key == key)
            return t;
        else{
            if( key < t -> key)
                t = t -> left;
            else
                t = t -> right;
        }
}
}

#endif // BINARYTREE_H_INCLUDED

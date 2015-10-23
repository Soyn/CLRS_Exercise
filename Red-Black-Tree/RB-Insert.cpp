#include <iostream>
#include "RB-Insert.h"
/*
* Author: Soyn
* @Brief: the main body to insert a node into the read-black tree
* Created time : 14/10/15.
* */
node n = {-1,NULL,NULL,NULL,"BLACK"};
pNode Nil = &n; // the pointer points to the flag.
///
/// <summary> Print the node</summary>
/// <para name = "t"> the pointer points to the node</para name>
///
//
void Print(pNode t)
{
    if(t != Nil)
    {
        std :: cout << t -> key <<'('<< t -> color << ')'<< std :: endl; 
        Print(t -> left);
        Print(t -> right);
    }
}
///
/// <summary> insert a node into the RB_Tree</summary>
/// <para name = "root"> the pointer points to the RBT's root node</para name>
/// <para name = "t"> the pointer points to the node to be inserted</para name>
///
pNode RB_Insert(pNode root, pNode t)
{
    //*{ the normal procedure to insert a node into the BST
    // PNode <===> node*
    pNode prev = Nil,curr = root;
    while(curr != Nil)
    {
        prev = curr;
        if(curr -> key < t -> key)
            curr = curr -> right;
        else curr = curr -> left;
    }
    t -> parent = prev;
    if( prev == Nil)
    {
        root = t;
        Nil -> left = root; //set the root to be the Nil's left child.
    }
    else
    {
        if(t -> key > prev -> key)
            prev -> right = t;
        else
            prev -> left = t;
    }
    t -> color = "RED";
    //*}
    return root = RB_Insert_Fixup(root,t);
}
///
/// <summary>The procedure to do rotation and recolor to maintain the RB_tree's properties</summary>
/// <para name = "root"> the pointer points to the RBT's root node</para name>
/// <para name = "t"> the pointer points to the node to be inserted</para name>
///
pNode RB_Insert_Fixup(pNode root, pNode t)
{
    while(t -> parent -> color == "RED")
    {
        
        /*
        * the uncle node is the left subtree.
        */
        if((t -> parent) == (t -> parent -> parent -> left))
        {
            pNode unclePNode = t -> parent -> parent -> right;
            // {*Case1:the uncle node's color is red
            if(unclePNode -> color == "RED")
            {
                
                //{* recoloring
                t -> parent -> color = "BLACK";
                unclePNode -> color = "BLACK";
                t -> parent -> parent -> color = "RED";
                t = t -> parent -> parent;
                //*}
            }
            //*}
            else //{* Case2 and Case3: the uncle node's color is black
            {
                
                //{*Case2: uncle node is black and right child
                if(t == (t -> parent -> right))
                {
                     t = t -> parent;
                     root = Left_Rotate(root, t);
                }
                //{*Case3: uncle node is black and the left child
                     t -> parent -> color = "BLACK";
                     t -> parent -> parent -> color = "RED";
                     root = Right_Rotate(root,t -> parent -> parent);
                    //*}
            }
        }
        /*
        * the t's parent  is the right subtree.
        */
        else
        {
            //t -> parent ->parent == left
            pNode uncleNode = t -> parent -> parent -> left;
            //{* Case1:the uncle node is red
            if(uncleNode -> color == "RED")
            {
                //{*recoloring
                t -> parent -> color = "BLACK";
                uncleNode -> color = "BLACK";
                t -> parent -> parent -> color = "RED";
                t = t -> parent -> parent;
                //*}
            }
            //*}
            else// Case2 and Case3:the uncle node's color is black
            {
                //Case2: the parent is the left child.
                if(t == (t -> parent -> left))
                {
                    t = t -> parent;
                    root =  Right_Rotate(root,t);
                }
                //Case3: the parent is the right child
                t -> parent -> color = "BLACK";
                t -> parent -> parent -> color ="RED";
                root = Left_Rotate(root, t -> parent -> parent);
            }
        }
    }
    root -> color = "BLACK";
    return root;
}
///
/// <summary>left rotation</summary>
/// <para name = "root"> the pointer points to the root</para name>
/// <para name = "t"> the pointer points to be insered</para name>
/// introduction:
///                 root                                              root
///                  /                                                /
///                 x                                                y
///                / \             left_rotate(x)                   / \
///              lx   y         ------------------>                x   ry
///                  / \        <------------------               / \
///                 ly  ry         right_rotate(x)               lx  ly
///
pNode Left_Rotate(pNode root, pNode x)
{
    pNode y = x -> right;
    x -> right = y -> left; // turn y's left subtree into t's right subtree.
    if(y -> left != Nil)
        y -> left -> parent = x;
    y -> parent = x -> parent; // link x's parent to y.
    if(x -> parent == Nil)
        root = y;
    else
    {
        if(x == (x -> parent -> left))
            x -> parent -> left = y;
        else
            x -> parent -> right = y;
    }
    y -> left = x; //put x on y's left
    x -> parent = y;
    Nil -> left = root;
    return root;
}
///
/// <summary>right rotation</summary>
/// <para name = "root"> the pointer points to the root</para name>
/// <para name = "t"> the pointer points to be insered</para name>
///
pNode Right_Rotate(pNode root, pNode x)
{

    pNode y = x -> left;
    x -> left = y -> right; // turn y's right subtree into x's left subtree.
    if( y -> right != Nil)
        y -> right -> parent = x;
    y -> parent = x -> parent;
    if(x -> parent == Nil)
        root = y;
    else
    {
        if( x == (x -> parent -> right))
            x -> parent -> right = y;
        else
            x -> parent -> left = y;
    }
    y -> right = x;
    x -> parent = y;
    Nil -> left = root;
    return root;
}
int main(int argc, char *argv[])
{
    node t[] = {
        {41,Nil,Nil,Nil,},
        {38,Nil,Nil,Nil,},
        {31,Nil,Nil,Nil,},
        {12,Nil,Nil,Nil,},
        {19,Nil,Nil,Nil,},
        {8,Nil,Nil,Nil,}
    };
    pNode root = Nil;
    for(int i = 0; i < sizeof(t) / sizeof(t[0]); ++i)
    {
        root = RB_Insert(root, t + i);
    }
    Print(root);
    return 0;
}

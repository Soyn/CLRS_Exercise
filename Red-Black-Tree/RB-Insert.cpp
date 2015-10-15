#include <iostream>
#include "RB-Insert.h"

node n = {-1,NULL,NULL,NULL,"BLACK"};
pNode Nil = &n;

///
/// <summary> insert a node into the RB_Tree</summary>
/// <para name = "root"> the pointer points to the RBT's root node</para name>
/// <para name = "t"> the pointer points to the node to be inserted</para name>
///

void RB_Insert(pNode root, pNode t)
{
    //*{ the normal procedure to insert a node into the BST

    // PNode <===> node*
    pNode prev = Nil;
    pNode curr = root;

    while(curr != Nil)
    {
        prev = curr;
        if(curr -> key < t -> key)
            curr = curr -> right;
        else curr = curr -> left;
    }

    t -> parent = prev;

    if( prev == Nil)
        root = t;
    else
        if(t -> key > prev -> key)
            prev -> right = t;
        else
            prev -> left = t;

    t -> left = t -> right = Nil;
    t -> color = "RED";

    //*}

    RB_Insert_Fixup(root, t);
}

///
/// <summary>The procedure to do rotation and recolor to maintain the RB_tree's properties</summary>
/// <para name = "root"> the pointer points to the RBT's root node</para name>
/// <para name = "t"> the pointer points to the node to be inserted</para name>
///
void RB_Insert_Fixup(pNode root, pNode t)
{
    while(t -> parent -> color == "RED")
    {
        /*
        * the uncle node is the left child.
        */
        if(t -> parent == t -> parent -> parent -> left)
        {
            pNode unclePNode = t -> parent -> parent -> right;
            // Case1:the uncle node's color is red
            if(unclePNode -> color == "RED")
            {
                //{* recoloring
                t -> parent -> color = "BLACK";
                unclePNode -> color = "BLACK";
                t -> parent -> parent -> color = "RED";
                //*}
            }
            else //{* Case2 and Case3: the uncle node's color is black
            {
                //{*Case2: uncle node is black and right child
                if(t == (t -> parent -> right))
                {
                    t = t -> parent;
                    Left_Rotate(root, t);
                }

                //{*Case3: uncle node is black and
                t -> parent -> color = "BLACK";
                t -> parent -> parent -> color = "RED";
                Right_Rotate(root,t -> parent -> parent);
                //*}
            }//*}
        }

        /*
        * the uncle node is the right child.
        */
        else
        {
            //t -> parent ->parent == right
            pNode uncleNode = t -> parent -> parent -> left;

            //{* Case1:the uncle node is red
            if(uncleNode -> color == "RED")
            {
                //{*recoloring
                t -> parent -> color = "BLACK";
                uncleNode -> color = "BLACK";
                t -> parent -> parent -> color = "RED";
                //*}
            }
            //*}
            else// Case2 and Case3:the uncle node's color is black
            {
                //Case2: the parent is the left child.
                if(t == (t -> parent -> left))
                {
                    t = t -> parent;
                    Right_Rotate(root,t);
                }

                //Case3: the parent is the right child

                t -> parent -> color = "BLACK";
                t -> parent -> parent -> color ="RED";
                Left_Rotate(root, t -> parent -> parent);
            }
        }
    }
}

///
/// <summary>left rotation</summary>
/// <para name = "root"> the pointer points to the root</para name>
/// <para name = "t"> the pointer points to be insered</para name>
///
void Left_Rotate(pNode root, pNode t)
{
    pNode y = t -> right;

    t -> right = y -> left; // turn y's left subtree into t's right subtree.

    if(y -> left != Nil)
        y -> left -> parent = t;

    y -> parent = t -> parent; // link x's parent to y.

    if(t -> parent == Nil)
        root = y;
    else
    {
        if(t == (t -> parent -> left))
            t -> parent -> left = y;
        else
            t -> right -> right = y;
    }

    y -> left = t; //put x on y's left
    t -> parent = y;
}

///
/// <summary>right rotation</summary>
/// <para name = "root"> the pointer points to the root</para name>
/// <para name = "t"> the pointer points to be insered</para name>
///

void Right_Rotate(pNode root, pNode t)
{
    pNode y = t -> left;

    t -> left = y -> right; // turn y's right subtree into t's left subtree

    if( y -> right != Nil)
        y -> right -> parent = t;

    y -> parent = t -> parent;

    if(t -> parent == Nil)
        root = y;
    else
    {
        if( t == (t -> parent -> right))
            t -> parent -> right = y;
        else
            t -> parent -> left = y;
    }

    y -> right = t;
    t -> parent = y;
}

int main(int argc, char *argv[])
{
    std :: cout << "Start the RB_tree" << std :: endl;
    return 0;
}

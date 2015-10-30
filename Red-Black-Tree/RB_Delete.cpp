/*************************************************************************
	> File Name: RB_Delete.cpp
    > Author: Soyn
	> @Brief: the main body to delete the node in RBT.
	> Created Time: 28/10/15.
 ************************************************************************/

#include <iostream>
#include "RB_Delete.h"
///
/// <summary>return the minmum node in RBT</summary>
///

pNode Tree_Minmum(pNode t)
{
    if(t -> left == Nil)
        return t;
    Tree_Minmum(t -> left);
}

/// <summary>return the successor node</summary>
///

pNode Tree_Successor(pNode t)
{
    if( t -> right != Nil )
        return Tree_Minmum(t -> right);
    pNode y = t -> parent;
    while( (y != Nil) && (t == ( y -> right )))
    {
        t = y;
        y = y -> parent;
    }
    return y;
}

pNode Tree_Delete_Fixup( pNode root, pNode t )
{
    while( (t != root ) && ( t -> color ) == "BLACK"){
        //{* the t is the left subtree
        if( t == ( t -> parent -> left ) ){
            pNode BrotherNode = t -> parent -> right;
            //{*Case1: the BrotherNode's color is red
            if( BrotherNode -> color == "RED" ){

                BrotherNode -> color = "BLACK";
                t -> parent -> color = "RED";
                Left_Rotate(root, t -> parent);
                BrotherNode = t -> parent -> right;

            } //*}
            //{* Case2: the BrotherNode and its children are all black.
            if( ( BrotherNode -> left -> color == "BLACK" )&& ( BrotherNode ->right -> color == "BLACK" )){
                BrotherNode -> color = "RED";
                t = t -> parent;
            }//*}
            else{
                //{* Case3: the BotherNode and his right is blackk , and its left child is red.
                if( BrotherNode -> right -> color == "BLACK"){

                    BrotherNode -> left -> color = "BLACK";
                    BrotherNode -> color = "RED";
                    Right_Rotate( root, BrotherNode);
                    BrotherNode = t -> parent -> right;

                } //*}

                //{* Case4: BrotherNode's color is black, and its right child is red
                BrotherNode -> color = t -> parent -> color;
                t -> parent -> color = "BLACK";
                BrotherNode -> right -> color = "BLACK";
                Left_Rotate(root, t -> parent);
                t = root;
                //*}
            }
        }
        //*}
        else{
            pNode BrotherNode = t -> parent -> left;

            if( BrotherNode -> color == "RED" ){

                BrotherNode -> color = "BLACK";
                t -> parent -> color = "RED";
                Right_Rotate( root, t -> parent);
                BrotherNode = t -> parent -> left;
            }

            if( (BrotherNode -> left -> color == "BLACK")  &&( BrotherNode -> right -> color == "BLACK") ){
                BrotherNode -> color = "RED";
                t = t -> parent;
            }
            else{
                if( BrotherNode -> right -> color == "BLACK" ){
                    BrotherNode -> right -> color = "BLACK";
                    BrotherNode -> color = "RED";
                    Left_Rotate(root, BrotherNode);
                    BrotherNode = t -> parent -> left;

                }

                BrotherNode -> color = t -> parent -> color;
                t -> parent -> color = "BLACK";
                BrotherNode -> left -> color = "BLACK";
                Right_Rotate( root, t -> parent );
            }
        }
    }
    t  = root;
    t -> color = "BLACK";
    return root;
}


///
/// <summary>to delete the node in red-black tree</summary>
/// <para name = "root">the root of red-black tree</para name>
/// <para name = "t"> the node to be deleted</para name>
///

pNode RB_Delete(pNode root,pNode t)
{
    pNode DelNode;

    //{* get tthe node to delete
    if((t -> left == Nil) || (t -> right == Nil) )
        DelNode = t;
    else
        DelNode = Tree_Successor(t);
    //*}

    pNode PreserveNode;
    if( DelNode -> left != Nil)
        PreserveNode = DelNode -> left;
    else
        PreserveNode = DelNode -> right;

    PreserveNode -> parent = DelNode -> parent; // link the DelNode's parent to PreserveNode

    if( DelNode == Nil )   //if DelNode is the root
        root = PreserveNode;
    else{
        if(DelNode == (DelNode -> parent -> left))
            DelNode -> parent -> left = PreserveNode;
        else
            DelNode -> parent -> right = PreserveNode;
    }

    if(DelNode != t)
        t -> key = DelNode -> key;
    /*
    * if the DelNode's color is black, we must fixup RBT to keep the properties of RBT.
    * */

    if(DelNode -> color == "BLACK")
        root = RB_Delete_Fixup(root, PreserveNode);

    return PreserveNode;
}


#include <iostream>
#include "BinaryTree/BinaryTree.h"
#include "BinaryTree/Traversal_Recursion.h"


/**
* To delete the specified node in BST.
* Created by Soyn.29/9/15.
*/

///
/// <summary>To delete the specified node in BST</summary>
/// <para name = "root">the pointer points to the root of the tree.</para name>
/// <para name = "t">the node in the BST will be deleted.</para name>
///

node *PMinmum(node *t)
{
    if(t -> left)
        return PMinmum(t -> left);
    else
        return t;
}

node* PTreeSuccessor(node* root, node *key)
{
    if(key -> right)
        return PMinmum(key);
    node *tmp = key -> parents;
    while(tmp && key == tmp -> right)
    {
        key = tmp;
        tmp = tmp -> parents;
    }
    return tmp;
}

///
/// <summary>the body to delete the specified node.</summary>
/// <para name = "root">the root of tree</para name>
/// <para name = "t">the node being deleted</para name>
/// <return "node*">the pointer points to the deleted-node.</return>

node* TreeDelete(node *root, node* t)
{
    //@{ get the node we will to delete.
    node *delNode,*delNodeChild;
    if(!(t -> left) || !(t -> right))
        delNode = t;                          //the t only has  one child mostly.
    else{
        delNode = PTreeSuccessor(root, t);     // the t has two childen
    }
    //@}

    if( delNode -> left)
        delNodeChild = delNode -> left;
    else
        delNodeChild = delNode -> right;

    if(x)
        delNodeChild -> parents = delNode -> parents;    //link x's parents to y's parents

    if(!(delNode -> parents))                 //if
        root = delNodeChild;
    else{
        if( delNode == (delNode -> parents -> left))
            delNode -> parents -> left = delNodeChild;
        else
            delNode -> parents -> right = delNodeChild;
    }

    if (delNode != t)
        t -> key = delNode -> key;   //recover the z's key.
    return delNode;
}


int main(void)
{
     int a[8] = {5,3,6,1,4,7,8,9};
     node* root;
     root = BinaryTree(a,8);
     MiddOrderTraversal(root);
     TreeDelete(root,Search(root,6));
     return 0;
}

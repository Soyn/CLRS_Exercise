#ifndef RB_INSERT_H_INCLUDED
#define RB_INSERT_H_INCLUDED


#include <string>

/*
* Author:Soyn
* @Brief: the implement of red-black tree
* Created time: 14/10/15.
*/

///
/// <summary>define the struct</summary>
///
//
struct node
{
    int key;
    node *left, *right, *parent;
    std :: string color;
};

typedef node* pNode;
extern node flag;
extern pNode Nil;     // the pointer points to the flag

pNode RB_Insert_Fixup(pNode, pNode);
pNode RB_Insert(pNode,pNode);
pNode Left_Rotate(pNode,pNode);
pNode Right_Rotate(pNode,pNode);
void Print(pNode);
#endif // RB_INSERT_H_INCLUDED

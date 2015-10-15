#ifndef RBINSERT_H_INCLUDED
#define RBINSERT_H_INCLUDED


#include <string>

/*
* @Brief: the implement of red-black tree
* Created by Soyn.14/10/15.
*/

struct node
{
    int key;
    node *left, *right, *parent;
    std :: string color;
};

#define pNode node*

void RB_Insert_Fixup(pNode, pNode);
void RB_Insert(pNode,pNode);
void Left_Rotate(pNode,pNode);
void Right_Rotate(pNode,pNode);
#endif // RB-INSERT_H_INCLUDED

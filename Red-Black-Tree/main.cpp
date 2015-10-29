#include "RB_Insert.h"
node flag = {-1,NULL,NULL,NULL,"Black"};
pNode Nil = &flag;

int main(void)
{
    node t[] = {
        {41,Nil,Nil,Nil,},
        {38,Nil,Nil,Nil,},
        {31,Nil,Nil,Nil,},
        {12,Nil,Nil,Nil,},
        {19,Nil,Nil,Nil,},
        {8,Nil,Nil,Nil,},
    };
    pNode root = Nil;
    for(int i = 0; i < sizeof(t) / sizeof(t[0]); ++i)
    {
        root = RB_Insert(root, t + i);
    }
    Print(root);
    return 0;

}

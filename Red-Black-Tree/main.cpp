#include <iostream>
#include "RB_Insert.h"



node flag = {-1,NULL,NULL,NULL,"Black"};
pNode Nil = &flag;

pNode SearchNode(pNode t, int key)
{
    if( t != Nil){
        if( t -> key == key )
            return t;
        else{
            if(key < t -> key)
                SearchNode(t -> left, key);
            else
                SearchNode(t -> right, key);
        }
    }else{
        std :: cout << "There is no such value " << key << std :: endl;
        return Nil;
    }
}

int main(void)
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
    for(size_t i = 0; i < sizeof(t) / sizeof(t[0]); ++i)
    {
        root = RB_Insert(root, t + i);
    }
    Print(root);
   // RB_Delete(root,SearchNode(root, 8));
    return 0;

}

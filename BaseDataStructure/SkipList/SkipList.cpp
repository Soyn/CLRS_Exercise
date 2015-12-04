#include <iostream>
#include <memory>
#include <random>
#include "SkipList.h"

/*
* Author: Soyn
* @Brief: the implmention of skip list
* Created Time: 4/12/15
*/

///
/// <summary> to insert the value into the skip list</summary>
/// <para name = 't'> the value being inserted.</para name>
///

void SkipList :: InsertList(int t)
{
    Node *NewNode = new Node(t);
    NewNode -> Predessor = NewNode -> Successor = NULL;

    Node *prev = NULL, *curr;

    if(!Heads.empty()){
        // link the curr with the head of bottom list
        curr = Heads[0];

        while(curr != NULL){
            prev = curr;
            curr = curr -> Successor;
        }
        // insert the node
        prev -> Successor = NewNode;
        NewNode -> Predessor = prev;
    }else{
        Heads.push_back(NewNode);
        top = curr = Heads[0];
    }


    while(true){
        if(PromoteOrNot()){
            /*Level up*/
        }
    }
}

///
/// <summary> to decide promote or not, like flip coin</summary>
///

bool SkipList :: PromoteOrNot(){
    srand(time(NULL));
    return (rand() % 2 == 1);
}

int main(int argc, char **argv)
{

    return 0;
}

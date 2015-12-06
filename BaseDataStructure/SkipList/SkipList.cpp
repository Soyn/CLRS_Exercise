#include <iostream>
#include <memory>
#include <stdlib.h>
#include <time.h>
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

    Node *prev, *curr = NULL;

    if(!Heads.empty()){

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

void SkipList :: InsertIntoBottomList()
{
    Node *head = *Heads.begin(); // the head of bottom list

}
int main(int argc, char **argv)
{
    std :: cout << "Hello World" << std :: endl;
    return 0;
}

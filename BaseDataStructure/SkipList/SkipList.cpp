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
/// <summary> Constructor</summary>
///

SkipList :: SkipList()
{
    //initiailzer the level of skip list
    level = 0;
}

///
/// <summary> to insert the value into the skip list</summary>
/// <para name = 't'> the value being inserted.</para name>
///

void SkipList :: InsertList(int t)
{
    Node *NewNode = new Node(t);
    NewNode -> Predessor = NewNode -> Successor = NULL;

    InsertIntoBottomList(NewNode);

    while(true){
        if(PromoteOrNot()){
            //lucky flip level up
        }else{
            // unlucky

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

///
/// <summary> to insert the node in bottom list</summary>
///
void SkipList :: InsertIntoBottomList(Node *InsertedNode)
{
    Node *head = *Heads.begin(); // the head of bottom list
    Node *pre = NULL, *curr = *head;

    // insert node in bottom list
    if(!Heads.empty()){
        while(curr){
            pre = curr;
            curr = curr -> successor;
        }
    }else{
        entrance = head = curr;
    }
}

///
/// <summary> the process to promote the level</summary>
///
void SkipList :: PromoteProcess()
{
    if( level == 0){  //create the new level
        Node *NewNode  = new Node( (*Heads.begin()) -> value);
        NewNode -> Predecessor = NewNode -> Successor = NULL;
        Heads[0] -> up = NewNode;
        NewNode -> down = Heads[0];
        Heads.push_back(NewNode);
        entrance = Heads[Heads.size() - 1];
    }else{

    }
}
int main(int argc, char **argv)
{
    std :: cout << "Hello World" << std :: endl;
    return 0;
}

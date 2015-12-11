#include <iostream>
#include <memory>
#include <stdlib.h>
#include <time.h>
#include <iterator>
#include "SkipList.h"

/*
* Author: Soyn
* @Brief: the implmention of skip list
* Created Time: 4/12/15
*/

///
/// <summary> Constructor</summary>
///

SkipList :: SkipList(){}

///
/// <summary> to insert the value into the skip list</summary>
/// <para name = 't'> the value being inserted.</para name>
///

void SkipList :: InsertList(int t)
{
    Node *NewNode = new Node(t);
    NewNode -> Predessor = NewNode -> Successor = NULL;

    // insert the bottom list is necessary
    InsertIntoBottomList(NewNode);
    PromoteProcess(NewNode);
}

///
/// <summary> to decide promote or not, like flip coin</summary>
///
bool SkipList :: PromoteOrNot(){
    /*initialize random seed*/
    srand(time(NULL));
    return (rand() % 2 == 1);
}

///
/// <summary> to insert the node in bottom list</summary>
///
void SkipList :: InsertIntoBottomList(Node *InsertedNode)
{
    Node *head = *Heads.begin(); // the head of bottom list
    Node *pre = NULL, *curr = head;

    // insert node in bottom list
    if(!Heads.empty()){
        while(curr){
            pre = curr;
            curr = curr -> Successor;
        }
        pre -> Successor = InsertedNode;
        InsertedNode -> Predessor = pre;
    }else{
        //the Heads is empty, just insert the head node
        entrance = head = curr;
    }
}

///
/// <summary> the process to promote the level</summary>
///
void SkipList :: PromoteProcess(Node* InsertNode)
{
    Node*  LevelUpNode = GetCopyNode(InsertNode);
    InsertNode -> UpLevel = LevelUpNode;
    LevelUpNode -> DownLevel = InsertNode;

    if( PromoteOrNot() ){

        if( Heads.size() == 1 ){ // to create the new level
        entrance =  AddNewLevel();
        InsertNewNodeInHighLevel(Heads.at(0),LevelUpNode);
    }else{

        do{
            auto nextX = std :: next(Heads.begin(), 1);
            if(nextX == Heads.cend()){
                entrance = AddNewLevel();
                InsertNewNodeInHighLevel(*nextX, LevelUpNode);
            }

        }while( PromoteOrNot()&&!Heads.empty());
    }

    }else{
        // if not promote the node, we should delete the memory we use.
        delete LevelUpNode;
    }

}

///
/// <summary> to copy the node</summary>
/// <return> the pointer points to the copy node.</return>
///

Node* SkipList :: GetCopyNode(Node* InitNode)
{
    Node* NewNode = new Node(InitNode -> value);
    NewNode -> Predessor = NewNode -> Successor = NULL;
    NewNode -> DownLevel = InitNode;
    InitNode -> UpLevel = NewNode;
    return NewNode;
}

///
/// <summary> to cretae the new level. </summary>
///

Node* SkipList ::  AddNewLevel()
{
    Heads.push_back(*Heads.begin());
    return *Heads.rbegin();
}

///
/// <summary> Insert the node in the new level.</summary>
///

void SkipList :: InsertNewNodeInHighLevel( Node* LevelHead, Node *LevelUpNode)
{
    Node *curr = LevelHead;
    while( curr -> Successor){
        curr = curr -> Successor;
    }

    curr -> Successor = LevelUpNode;
    LevelUpNode -> Predessor = curr;

}

///
/// <summary> to search the ndoe in skip list</summary>
///
Node* SkipList ::Search(Node *p, int t)
{
    while( true ){
        if( p -> value == t){
            return p;
        }else{
            if( p -> value > t && p -> Successor != NULL){
                Search(p -> Successor, t);
            }else{
                Search( p -> DownLevel -> Predessor, t );
            }
        }
    }
}

///
/// <summary> the processdure to delete the node in skip list</summary>
///

void SkipList :: DeleteList(int t)
{
    Node *pre = NULL, *curr = Heads.at(0);
    // to get pointer we going to delete
    while(curr){
        if( curr -> value == t){
            break;
        }else{
            pre = curr;
            curr = curr -> Successor;
        }
    }
    if( pre == NULL){
        // if delete the head we must move the entrance to its successor
        entrance  = entrance -> Successor;
    }else{
        pre -> Successor = curr -> Successor;
        delete curr;
        while(pre -> UpLevel){
            auto pPre = pre -> UpLevel;
            curr = pPre -> Successor;
            pPre -> Successor = curr -> Successor;
            delete curr;
    }
}
}

int main(int argc, char **argv)
{
    std :: cout << "hello" << std :: endl;
    return 0;
}

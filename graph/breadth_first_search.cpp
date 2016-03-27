#include "breadth_first_search.h"
#include <iostream>
#include <limits>
/*******************
* @Author: Soyn.
* @Brief: The implement of breath-first search.
* @CreatedTime: 26/3/16.
********************/
//
// @Brief: The main procedure of the breadth first search.
// @Algorithm details:
// 1.At first all the vertex are initialized which color is white,
// parents is null and distance is maximum number.
// 2.Then when find a vertex change the color, diatance, parents to white,
// null respectively, and initialze the queue.
// 3.Traverse the adhacent list if color is white and then change the color,
// the distance and parents. and add the new element into the queue.
//
void Graph :: BreadthFirstSearch(AdjacentList root)
{
    for(auto &e : adjacent_list){
        e.Color = white;
        e.parents = nullptr;
        e.distance = std :: numeric_limits<int> :: max();
    }

    root.color = gray;
    root.distance = 0;
    root.parent = nullptr;
    record_queue_.clear();
    record_queue_.push(root);

    while(!record_queue_,empty()){ // while the queue is not empty(i.e. until all the vertex is black.)
        AdjacentList start_vertex = record_queue_.pop();
        for(auto &e : start_vertex.second){
            if(e.color == white){
                e.color = gray;
                e.distance = start.distance + 1;
                e.parents = &start_vertex;
                record_queue_.push(e);
            }
        }
        start_vertex.color = black;
    }

}
void Test()
{

}
int main(int argc, char **argv)
{
    return 0;
}

#include "breadth_first_search.h"
#include <iostream>
#include <memory>
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
void Graph :: BreadthFirstSearch(int root_key)
{
    for(auto &value : adjacent_list_){
        for(auto &element : value.second){
            element.color_ = white;
            element.parents_ = nullptr;
            element.distance_ = std :: numeric_limits<int> :: max();
        }
    }
    std :: shared_ptr<Vertex> root( new Vertex(root_key));

    root->color_ = gray;
    root->distance_ = 0;
    root->parents_ = nullptr;
    Clear();  // clear the queue
    record_queue_.push(*root);

    // while the queue is not empty(i.e. until all the vertex is black.)
    while(!record_queue_.empty()){
        Vertex start_vertex = record_queue_.front();
        std :: cout << start_vertex.key_ << std :: endl;
        record_queue_.pop();
        int index = start_vertex.key_;

        for(auto &element : adjacent_list_[index]){
            if(element.color_ == white)
                element.color_ = gray;
                element.distance_ = start_vertex.distance_ + 1;
                element.parents_ = &start_vertex;
                record_queue_.push(element);
            }
            start_vertex.color_ = black;
        }

    }


void Graph :: Clear()
{
    std :: queue<Vertex> empty;
    std :: swap(record_queue_, empty);
}

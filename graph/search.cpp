#include "search.h"
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
// null respectively, and initialize the queue.
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
    std :: shared_ptr<Vertex> root(new Vertex(root_key));

    root->color_ = gray;
    root->distance_ = 0;
    root->parents_ = nullptr;
    Clear();  // clear the queue
    record_queue_.push(*root);

    // while the queue is not empty(i.e. until all the vertex is black.)
        while(!record_queue_.empty()){
        Vertex start_vertex = record_queue_.front();
        record_queue_.pop();
        int index = start_vertex.key_;

        for(auto &element : adjacent_list_[index]){
            if(element.color_ == white){
                element.color_ = gray;
                element.distance_ = start_vertex.distance_ + 1;
                element.parents_ = &start_vertex;
                record_queue_.push(element);
            }
        }
        start_vertex.color_ = black;
    }
}

//
// @Brief: To clear the queue, ensure the queue is empty before we search.
void Graph :: Clear()
{
    std :: queue<Vertex> empty;
    std :: swap(record_queue_, empty);
}

//
// @Brief: The implement of deepth first search.
// @Algorithm details:
// 1. First, initialize all the vertex with white.
// 2. Then for each vertex in adjacent list, invoke the DeepthVisitFirst.
void Graph :: DeepthFirstSearch()
{
    time_ = 0;
    //
    // initialize all the vertex in adjacent list.
    for(auto &entry : adjacent_list_){
        for(auto &element : entry.second){
            element.color_ = white;
            element.parents_ = nullptr;
        }
    }

    for(auto &entry : adjacent_list_){
        for(auto &element : entry.second){
            if(element.color_ == white){
                DeepthFirstSearchVisit(element);
            }
        }
    }
}


//
// @Brief: The implement of deepth first search visit.
// @Para name start; The start vertex of graph.
// @Algorithm details:
// For each vertex in the adjacent list of start. If its' color is white
// we need to set its' parents. And then invoke next visit until the color is
// not white. Finally set the start's color black which implies the current
// search finshed.
void Graph :: DeepthFirstSearchVisit(Vertex &start)
{
    // While the white vertex is discovered, setting the color gray.
    start.color_ = gray;
    time_ = time_ + 1;
    start.start_time = time_;

    for(auto &entry : adjacent_list_[start.key_]){
        if(entry.color_ == white){
            entry.parents_ = &start;
            std :: shared_ptr<Vertex> next_target(new Vertex(entry.key_));
            DeepthFirstSearchVisit(*next_target);
        }
    }

    start.color_ = black;
    ++time_;
    start.end_time = time_;
}

#ifndef BREADTH_FIRST_SEARCH_H_INCLUDED
#define BREADTH_FIRST_SEARCH_H_INCLUDED

#include <map>
#include <vector>
#include <queue>
#include <algorithm>

/***************************************
* @Aythor: Soyn.
* @Brief: Breadth-first search of Graph.
* @CreatedTime: 26/3/19.
****************************************/
//
// @Brief: Define the enumeration represents the color of node.
enum Color{white, gray, black};

//
// @Brief: Define the vertex data member.
struct Vertex{
    int key_;
    Color color_;
    Vertex *parents_;
    size_t distance_;  // For BFS.
    Vertex(int key) : key_(key), color_(white){}

    size_t start_time; // For DFS.
    size_t end_time;  // For DFS.
};

class Graph{
public:
    using AdjacentList = std :: map<int, std :: vector<Vertex>>;
    Graph(): adjacent_list_(){}
    ~Graph(){}
    //
    // @Brief: The constructor takes AdjacentList.
    Graph(AdjacentList adjacent_list) : adjacent_list_(adjacent_list){}
    //
    // @Brief: Breadth first search.
    // @Note: More algorithm details please go to wiki.
    void BreadthFirstSearch(int root_key);

    //
    // @Brief: Set the record_queue clear.
    void Clear();

    //
    // @Brief: Deepth first search.
    // @Note: More algorithm datails plz go to wiki.
    void DeepthFirstSearch();

    //
    // @Brief: Deepth first search visit.
    // @Note: The help procedure for deepth first search.
    void DeepthFirstSearchVisit(Vertex &start);
private:
    AdjacentList adjacent_list_;
    std :: queue<Vertex> record_queue_;
    size_t time_;
};
#endif // BREADTH_FIRST_SEARCH_H_INCLUDED

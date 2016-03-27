#ifndef BREADTH_FIRST_SEARCH_H_INCLUDED
#define BREADTH_FIRST_SEARCH_H_INCLUDED

#include <map>
#include <vector>
#include <queue>

/********************
* @Aythor: Soyn.
* @Brief: Breadth-first search of Graph.
* @CreatedTime: 26/3/19.
*/
//
// @Brief: Define the enumeration represents the color of node.
enum Color{white, gray, black};

//
// @Brief: Define the vertex data member.
struct Vertex{
    int key;
    Color color;
    Vertex *parents;
    size_t distance;
    Node() : color(white){}
};

class Graph{
public:
    using AdjacentList = std :: map<int, std :: vector<Vertex>>;
    Graph(): adjacent_list(std :: make_pair()){}
    ~Graph(){}
    //
    // @Brief: The constructor takes AdjacentList.
    Graph(AdjacentList adjacent_list) : adjacent_list_(adjacent_list){}
    //
    // @Brief: The breadth first search.
    // @Note: More algorithm details please go to wiki.
    void BreadthFirstSearch(Vertex root);
private:
    AdjacentList adjacent_list_;
    std :: queue<AdjacentList> record_queue_;
};
#endif // BREADTH_FIRST_SEARCH_H_INCLUDED

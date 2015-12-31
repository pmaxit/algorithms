#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

template<class T>
class Graph
{
public:

    // default constructor
    Graph(int n){}

    Graph(){}

    // init
    virtual void init(int n) = 0;

    // Return the number of vertices
    virtual int nodeCount() = 0;

    // Return the current number of edges
    virtual int edgeCount() = 0;

    // Get the value of node with with index v
    virtual T getValue(int v, T val) = 0;

    // Set the value of node with index v
    virtual void setValue(int v, T val) = 0;

    // Get id of object
    virtual int getId(T val) = 0;

    // Adds a new edge from node v to node node w with weight wgt
    virtual void addEdge(int v, int w, int wgt) = 0;

    // Adds a new edge in object format.
    virtual void addEdges(T v, T w, int wgt) = 0;

    // get weight
    virtual int weight(int v, int w) = 0;

    // Removes the edge from graph
    virtual void removeEdge(int v, int w) = 0;

    // Returns an array containing the indices of neighbours of v
    virtual std::vector<int> neighbours(int v) = 0;
};

#endif // GRAPH_H

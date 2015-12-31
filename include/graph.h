#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

using namespace std;
template<class T>
class Graph
{

public:

    // default constructor
    Graph(int n):vertices(n){}

    Graph():vertices(0){}

    // init
    void init(int n){
        vertices = n;
    }

    // Returns an array containing the indices of neighbours of v
    virtual std::vector<int> neighbours(int v) = 0;

    // Check if there is an edge
    virtual bool hasEdge(int v, int w)= 0;

    // Adds a new edge from node v to node node w with weight wgt
    virtual void addEdge(int v, int w, int wgt) = 0;

    // Get the value of node with with index v
    T getValue(int v, T val){
        if(v < objects.size())
            return objects[v];
        else
            return val;
    }

    // Set the value of node with index v
    void setValue(int v, T val){
        objects[v] = val;
    }

    // Get id of object
    int getId(T val){
        typename vector<T>::iterator it = std::find(objects.begin(), objects.end(), val);
        if(it != objects.end())
            return distance(objects.begin(), it);
        else
            return -1;
    }

    int getOrCreateId(T val){
        int v = getId(val);
        if(v == -1){
            v = objects.size();
            objects.push_back(val);
        }
        return v;
    }

    // Adds a new edge in object format.
    void addEdges(T v, T w, int wgt=1){
        int aid = getOrCreateId(v);
        int bid = getOrCreateId(w);

        addEdge(aid, bid, wgt);
    }


    // Check if there is an edge
    bool hasEdges(T &a, T &b){
        int aid = getOrCreateId(a);
        int bid = getOrCreateId(b);

        return hasEdge(aid, bid);
    }

    void print(){
        cout<<"vertices "<<vertices<<endl;
        for(int i=0; i< vertices; i++){
            cout<<"vertices connected to "<<i<<"  "<<getValue(i,"")<<endl;
            vector<int> adj = neighbours(i);
            for(auto it = adj.begin(); it!= adj.end(); it++)
                cout<<*it<<"  ";
            cout<<endl;
        }
    }

    int vertices;

private:
    vector<T> objects;
};

#endif // GRAPH_H

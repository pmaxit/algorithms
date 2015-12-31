#ifndef GRAPHMAP
#define GRAPHMAP

#include "graph.h"
#include <list>

using namespace std;
template<class T>
class GraphVect: public Graph<T>{

    struct Edge{
        int from, to, weight;
        Edge(int from, int to, int weight):from(from), to(to), weight(weight){}
    };

    GraphVect(int n):
        graph(n),Graph<T>(n){

    }

    GraphVect():Graph<T>(){
    }

    void init(int n){
        vertices = n;
        edges = 0;
        graph.reserve(n);
    }

    void addEdge(int a, int b, int wgt){
        graph[a].push_back(Edge(a,b, wgt));

        // if undirected then push reverse edge too
        graph[b].push_back(Edge(b, a, wgt));
    }

    bool hasEdge(int v, int w){
        for(auto it = graph[v].begin(); it != graph[v].end(); it++){
            if(it->to == w)
                return true;
        }
        return false;
    }


    std::vector<int> neighbours(int v){
        vector<int> results;
        for(auto it=graph[v].begin();it != graph[v].end(); it++)
            results.push_back(it->to);

        return results;
    }

private:
    vector<list<Edge> > graph;
};

#endif // GRAPHVECT


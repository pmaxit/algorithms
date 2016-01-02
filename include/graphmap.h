#ifndef GRAPHMAP
#define GRAPHMAP

#include "graph.h"

template<class T>
class GraphMap: public Graph<T>{

public:
    struct Edge{
        int from, to, weight;
        Edge(int from, int to, int weight):from(from), to(to), weight(weight){}
    };

    GraphMap(int n):
        graph(n),Graph<T>(n){

    }

    GraphMap():Graph<T>(){
    }

    void init(int n){
        graph.reserve(n);
        Graph<T>::init();
    }

    void addEdge(int a, int b, int wgt=0){

        graph[a].push_back(Edge(a, b, wgt));

        // if it is undirected then add reverse edge too
        graph[b].push_back(Edge(b, a, wgt));
    }

    bool hasEdge(int v, int w){
        for(auto it = graph[v].begin(); it != graph[v].end(); it++){
            if(it->to == w)
                return true;
        }
        return false;
    }

    vector<int> neighbours(int v){
        vector<int> results;
        for(auto it=graph[v].begin();it != graph[v].end(); it++)
            results.push_back(it->to);

        return results;
    }

private:
    vector<vector<Edge> > graph;
};

#endif // GRAPHMAP

/*
 * GraphMat<string> g(10);
  // declare number of nodes


 g.addEdges("a", "b");

 g.addEdges("b", "c");
 g.addEdges("c", "z");
 g.addEdges("z", "a");

 g.print();
  //cout<<greater1<int>(2,3)<<endl;
 */


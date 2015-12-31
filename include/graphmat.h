#ifndef GRAPHMAT
#define GRAPHMAT

#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;


/* Adjacency Matrix representation
 *
 *
 * Cons: Need to define number of vertices before the start of program.
 * Difficult to add new vertex.
 *
 *  Matrix could be very sparse
 */

template<class T>
class GraphMat : public Graph<T>{

public:
    GraphMat(int n): matrix(n, vector<int>(n, 0) ),
        Graph<T>(n){
    }

    GraphMat(){
    }

    void init(int n){
        matrix.reserve(n);
        Graph<T>::init();
    }   

    void addEdge(int v, int w, int wgt=1){
        if(wgt == 0) return;
        if(v>= Graph<T>::vertices || w>= Graph<T>::vertices) return;
        matrix[v][w] = wgt;

        // if undirected then add a reverse edge too
        matrix[w][v] = wgt;
    }

    bool hasEdge(int v, int w){
        return matrix[v][w] != 0;
    }

    std::vector<int> neighbours(int v){
        vector<int> results;
        for(int i=0; i< Graph<T>::vertices; i++){
            if(matrix[v][i])
                results.push_back(i);
        }
        return results;
    }

private:
    std::vector<std::vector<int> >matrix;
};

#endif // GRAPHMAT


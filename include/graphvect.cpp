#ifndef GRAPHVECT
#define GRAPHVECT

#include <iostream>
#include <vector>
#include <list>
#include "graph.h"

using namespace std;


/* Vector Matrix representation
 *
 * Need to define list of vertices earlier.
 *
 * Sparseness is reduced due to list representation
 */

template<class T>
class GraphVect : public Graph<T>{

public:
    GraphVect(){}

    GraphVect(int n):matrix(n), vertices(n), edges(0){}

    void GraphVect::init(int n){
        matrix.reserve(n);
        vertices = n;
        edges = 0;
    }

    int GraphVect::getId(T val){

    }

    void GraphVect::addEdges(T v, T w, int wgt){

    }

private:
   vector<list<T> >matrix;
   int vertices;
   int edges;
};

#endif // GRAPHMAT


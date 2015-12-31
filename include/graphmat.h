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
        vertices(n), edges(0), Graph<T>(){
    }

    GraphMat():vertices(0), edges(0){
    }

    void init(int n){
        matrix.reserve(n);
        vertices = n;
        edges = 0;
    }

    int nodeCount(){
         return objects.size();
    }

    int edgeCount(){
         return edges;
    }

    T getValue(int v, T def){
        if(v < objects.size())
            return objects[v];
        else
            return def;
    }

    void setValue(int v, T val){
        objects[v] = val;
    }

    int getId(T val){
        typename vector<T>::iterator it = std::find(objects.begin(), objects.end(), val);

        if(it != objects.end())
            return std::distance(objects.begin(), it);
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

    void addEdge(int v, int w, int wgt=1){
        if(wgt == 0) return;
        if(v>=vertices || w>=vertices) return;
        matrix[v][w] = wgt;
        edges+=1;

    }

    void addEdges(T v, T w, int wgt=1){
        int vi = getOrCreateId(v);
        int wi = getOrCreateId(w);
        cout<<"vi "<<vi<<"wi "<<wi<<endl;
        addEdge(vi, wi, wgt);
    }

    int weight(int v, int w){
          return matrix[v][w];
    }

    void removeEdge(int v, int w){
        matrix[v][w] = 0;
        edges-=1;
    }

    std::vector<int> neighbours(int v){
        vector<int> results;
        for(int i=0; i< vertices; i++){
            if(matrix[v][i])
                results.push_back(matrix[v][i]);
        }
        return results;
    }

    void print(){

        for(int i=0; i< matrix.size(); i++){
            cout<<"nodes connected to "<<i<< "  "<<getValue(i, "")<<endl;
            for(int j=0; j < matrix[i].size(); j++){
                if(matrix[i][j] !=0)
                    cout<< j <<"  ";
            }
            cout<<endl;
        }
    }

private:
    std::vector<std::vector<int> >matrix;
    std::vector<T> objects;
    int vertices;
    int edges;
};

#endif // GRAPHMAT


#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef map<int, int> mii;
typedef vector<mii> vmi;


void addEdge(vmi &graph, int v, int w, int weight){
  graph[v][w] = weight;
  // for undirected graph
  graph[w][v] = weight;
}

void print(vmi &graph){
  for(int i=0; i< graph.size(); i++){
    cout<<"neighbours of vertex : "<<i<<endl;
    for(auto it = graph[i].begin(); it != graph[i].end(); it++){
      cout<< it->first<<"  ";
    }
    cout<<endl;
  }
}

int main(int argc, const char *argv[])
{
  vmi graph(10);

  addEdge(graph, 0, 1, 1);
  addEdge(graph, 1, 2, 1);

  print(graph);
  return 0;
}

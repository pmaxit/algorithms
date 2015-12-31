#include <iostream>
#include <string>
#include "graphmat.h"

using namespace std;

int main(int argc, const char *argv[])
{
  GraphMat<string> g(10);
  // declare number of nodes


 g.addEdges("a", "b");

 g.addEdges("b", "c");
 g.addEdges("c", "z");
 g.addEdges("z", "a");

 g.print();
  //cout<<greater1<int>(2,3)<<endl;

    return 0;
}

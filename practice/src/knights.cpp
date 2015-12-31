#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define POS(x, y) x*8 + y


vector<list<int> >graph(64);

vector<pair<int, int> > genLegalMovs(int i, int j, int boardSize){
  
}

void init(int boardSize){
  for(int i=0; i< boardSize; i++){
    for(int j=0; j< boardSize; j++){
      int nodeId = POS(i,j);
      vector<pair<int, int> > newPositions = genLegalMoves(i, j, boardSize);
      for(vector<pair<int, int> >::const_iterator it=newPositions.begin(); it != newPositions.end(); it++){
        int nId = POS(it->first, it->second);
        // add edge
        graph[src].push_back(dest);
      }
    }
  }
}

int findMoves(int p, int q, int r, int s){

  return 0;
}


int main(int argc, const char *argv[])
{
  int n;
  char line[100];
  scanf("%d ", &n);
  while(n--){
    scanf(" %[^\n]",line);
    int res = findMoves(line[0] -'a', line[1] -'0', line[2] - 'a', line[3] -'0');
    printf("%d\n",res);

  }
  return 0;
}



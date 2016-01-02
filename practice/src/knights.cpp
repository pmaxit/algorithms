#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define POS(x, y) x*8 + y

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
vvi graph(64, vi(64, 0));
int moves[][2] = {{-1,-2}, { -1, 2 }, {-2, -1}, {-2, 1},
                  { 1,-2}, {1, 2}, {2, -1}, {2, 1}};


inline bool check(int pos, int boardSize){
  if(pos >=0 && pos < boardSize)
    return true;
  else
    return false;
}

vector< pii > genLegalMoves(int i, int j, int boardSize){
  vector<pii> results;
  for(int k=0; k< 8; k++){
    int x  = i+ moves[k][0];
    int y =  j + moves[k][1];
    if(check(x, boardSize) && check(y, boardSize))
      results.push_back(make_pair(x,y)); 
  }
  return results;
}

void init(int boardSize){
  for(int i=0; i< boardSize; i++){

    for(int j=0; j< boardSize; j++){
      int nodeId = POS(i,j);
      //printf("start move (%d, %d) \n", i, j);
      vector<pii > newPositions = genLegalMoves(i, j, boardSize);
      for(vector<pii>::const_iterator it=newPositions.begin(); it != newPositions.end(); it++){
        int nId = POS(it->first, it->second);
        //printf("move (%d, %d) %d, ", it->first, it->second, nId);
        graph[nodeId][nId] = 1;
      }
      //cout<<endl;
    }
  }
}

int findMoves(int p1, int q1, int r1, int s1){
  int s = POS(p1,q1);
  int t = POS(r1,s1);
  int cnt = 0;
  queue<int> q;
  vector<int> p(64,-1);
  q.push(s);
  
  p[s] = -2;
  while(!q.empty()){
    int v = q.front();
    q.pop();
    
    if(v == t){
      int p1 = p[v];
      while(p1 != -2){
        cnt++;
        p1=p[p1];
      }
      return cnt;
    }
    // get all adjacent vertices
    for(int i=0; i<64; i++){
      if( graph[v][i] !=0 && p[i] == -1){
        p[i] = v;
        // push it into queue
        q.push(i);
      }
    }
  }

  return 0;
}


int main(int argc, const char *argv[])
{
  int n;
  char line[100];
  init(8);

  scanf("%d ", &n);
  while(n--){
    scanf(" %[^\n]",line);
    int res = findMoves(line[0] -'a', line[1] -'1', line[3] - 'a', line[4] -'1');
    printf("%d\n",res);

  }
  return 0;
}



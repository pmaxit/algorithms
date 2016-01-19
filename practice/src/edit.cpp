#include <iostream>
#include <vector>
#include <string>
using namespace std;

int min(int x, int y, int z){
  return min(x, min(y, z));
}

int editDistance(string a, string b, int m, int n){
  if(m == 0 || n == 0)
    return max(m, n);
  
  if(a[m] == b[n])
    return editDistance(a, b, m - 1, n -1);
  else{
    return 1 + min( editDistance( a, b , m , n -1 ) , // addition
                    editDistance( a, b, m -1 , n),    // removal
                    editDistance( a, b, m -1, n - 1)); // replace
  }

}

int editDistanceDP(string a, string b, int m, int n){
  
}

int main(int argc, const char *argv[])
{
  string a="sunday";
  string b = "saturday";
  cout<< editDistance(a, b, a.length(), b.length());
  return 0;
}

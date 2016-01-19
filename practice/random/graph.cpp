#include <iostream>
#include <array>

using namespace std;

int insert(array<int, 100> &a, int val){
  int root = 1;
  while(a[root] != 0){
    if(a[root] > val)
      root = root*2;
    else
      root = root*2 + 1;
  }
  a[root] = val;
  return root;
}

// find lca between a & b
int lca(array<int, 100> &a, int root, int m, int n){
  if(a[root] == 0)
    return 0;

  if(a[root] == m || a[root] == n)
    return root;
  
  // Look for keys in left and right subtrees
  int left = lca(a, root*2, m, n);
  int right = lca(a,root*2+1, m,n);

  if(left && right) return root;
  
  return left? left: right;
}


int main(int argc, const char *argv[])
{
  //using arrays as trees
  array<int, 100> a = {0};
  
  cout<<"inserting at : "<<insert(a, 2)<<" 2 "<<endl;
  cout<<"inserting at : "<<insert(a, 5)<<" 5 "<<endl;
  cout<<"inserting at : "<<insert(a, 8)<<" 8 "<<endl;
  cout<<"inserting at : "<<insert(a, 3)<<" 3 "<<endl;
  cout<<"inserting at : "<<insert(a, 6)<<" 6 "<<endl;
  cout<<"inserting at : "<<insert(a, 4)<<" 4 "<<endl;
  cout<<"inserting at : "<<insert(a, 9)<<" 9 "<<endl;
  cout<<"inserting at : "<<insert(a, 11)<<" 11 "<<endl;
  
  cout<<"lca of : "<<lca(a, 1, 4, 11)<<endl;
  return 0;
}


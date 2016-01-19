#include <queue>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[])
{
  int myints[] = { 10, 20, 30, 5, 15 };
  std::vector<int> v(myints, myints + 5 );

  std::make_heap(v.begin(), v.end());
  cout<< " Initial max heap "<<v.size()<<"  "<<v.capacity()<<endl;
  return 0;
}


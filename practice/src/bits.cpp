#include <iostream>
#include <bitset>
#include <string>
#include <limits.h>

using namespace std;


int main(int argc, const char *argv[])
{
  long n = INT_MAX + 1;
  std::bitset<1000> foo;
  foo[1] = 0;
  foo[2] = 1;

  foo.set(3);
  foo.reset(3);
  //cout<<"foo: "<<foo<<endl;
  return 0;
}

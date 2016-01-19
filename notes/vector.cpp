#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compar(const int &v1, const int &v2){

  return v1 < v2;
}

int main(int argc, const char *argv[])
{
  int a[] = { 1 , 3, 4, 6 , 2, 3, 4, 6 };
  vector<int> v(a , a + sizeof(a)/sizeof(a[0]));

  // sort the vector
  std::sort(v.begin(), v.end());
  
  // iterate over vector. it copies by value
  for(auto i: v){
    cout<<i<<endl;
  }

  for(auto &&i: v){
    cout<<i<<endl;
  }

  // sort the vector with compar function
  std::sort(v.begin(), v.end(), compar);

  // binary search return true or false
  if(std::binary_search(v.begin(), v.end(), 5))
    cout<<" 5 found"<<endl;
  else
    cout<<" 5 not found"<<endl;

  // lower / upper / equal range
  
  
  
  // counting algorithm
  int n =  count(v.begin(), v.end(), 2);  // 1
  int m1 = count_if(v.begin(), v.end(), [](int x){ return x ==2; }); // 1
  int m = count_if(v.begin(), v.end(), [](int x){ return x < 10; }); // 9

  // max / min in array
  // max_element returns the first max element in array
  vector<int>::iterator itr;
  itr = max_element(v.begin()+ 2, v.end());    // range of data from 2nd element till the end
  // to provide own compare function.
  itr = max_element(v.begin(), v.end(), [](int x, int y){ return x%10 < y %10;});

  // minimum element
  itr = min_element(v.begin(), v.end()); // iterator for first minimum element
  
  // min & max element
  minmax_element(v.begin(), v.end(), [](int x, int y){return x < y; }); // it returns a pair of iterator containing
                                                                        // minimum & maximum element
  

  // find algorithm
  itr = find(v.begin(), v.end(), 10);

  itr = find_if(v.begin(), v.end(), [](int x){ return x > 2; });

  itr = find_if_not(v.begin(), v.end(), [](int x){ return x > 2; });

  // search n consecutive elements
  search_n(v.begin(), v.end(), 2, 2); 
  return 0;
}


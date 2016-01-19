#ifndef ALGOSTUFF_HPP
#define ALGOSTUFF_HPP
#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <string>
using namespace std;

template<typename T>
inline void INSERT_ELEMENTS(T &coll, int first, int last){
  for(int i=first; i<=last; i++)
    coll.insert(coll.end(),i);
}

template<typename T>
inline void PRINT_ELEMENTS(const T &a, std::string&& opt=""){
  std::cout<<opt<<"  ";
  for(auto itr: a){
    cout<<itr<<"  ";
  }
  cout<<endl;
}

template<typename T>
inline void PRINT_MAPPED_ELEMENTS(const T&coll, std::string &opt=""){
  std::cout<<opt;
  for(auto itr: coll){
    std::cout<<"["<<itr.first<<","<<itr.second<<"] ";
  }
  std::cout<<endl;
}

void print_lists(const forward_list<int> &l1, const forward_list<int> &l2){
  cout<<" list1: ";
  copy(l1.begin(), l1.end(), ostream_iterator<int>(cout, " "));
  cout<<endl;
  cout<<" list2: ";
  copy(l2.begin(), l2.end(), ostream_iterator<int>(cout, " "));
  cout<<endl;
}

template<typename T1, typename T2>
ostream &operator<<(ostream& out, pair<T1, T2> &val){
  out<<"["<<val.first<<"  ,  "<<val.second<<"]";
  return out;
}

#endif

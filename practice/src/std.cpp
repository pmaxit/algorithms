#include <iostream>
#include <array>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstring>
#include <forward_list>
#include <iomanip>
#include "print.hpp"
using namespace std;

// forward list algorithm find_before
template<typename InputIterator, typename Tp>
inline InputIterator find_before(InputIterator first, InputIterator last, const Tp &val){
  if(first == last)
    return first;

  InputIterator next(first);
  ++next;
  while(next != last && !(*next == val)){
    ++next;
    ++first;
  }
  return first;
}

template<typename InputIterator, typename Pred>
inline InputIterator find_before_if(InputIterator first, InputIterator last, Pred pred){
  if(first == last)
    return first;

  InputIterator next(first);
  ++next;
  while(next != last && !pred(*next)){
    ++next;
    ++first;
  }
  return first;
}


// print hashtable stable
template<typename T>
void printHashtableState(const T& cont){
  // basic layout data
  cout<<" size: "<<cont.size()<<endl;
  cout<<" buckets: "<<cont.bucket_count()<<endl;
  cout<<" load factor: "<<cont.load_factor()<<endl;
  cout<<" max load factor: "<<cont.max_load_factor()<<endl;

  // elements per bucket
  std::cout<< "data: "<<endl;
  for(auto idx=0; idx!= cont.bucket_count(); ++idx){
    cout<<" b[" <<setw(2)<<idx <<"]: ";
    for(auto pos=cont.begin(idx); pos!= cont.end(idx); pos++){
      cout<<pos->first<<endl;
    }
    cout<<endl;
  }
  cout<<endl;
}

int main(int argc, const char *argv[])
{

  /* std Array 
   *
   * 1. It is a constant size container where size needs to be provided at the time of initialization. It can't be changed
   * 2. It can behave as c data array &a[0] is a data pointer.
   */
  
  array<int, 10> a = {11, 22, 33, 44}; // rest of elements will be initalized to zero
  
  // 2nd argument is optimized for rvalue and it needs to be recieved 
  // as && type
  PRINT_ELEMENTS(a,"elements are : ");

  cout<<" sum: "
    << accumulate(a.begin(), a.end(), 0)
    <<endl;

  // negate all elements
  // negate<int> is a class and negate<int>() returns an object who has
  // a member function operator() which behaves as a function.
  // it takes one argument and returns integer.
  
  // transform takes one array elements input and outputs to other
  transform(a.begin(), a.end(), a.begin(), negate<int>());

  PRINT_ELEMENTS(a);

  // array elements to behave as c array
  array<char, 100> s;
  strcpy(&s[0], "hello world");
  PRINT_ELEMENTS(s);
  
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /* VECTOR */
  /* 1. A vector copies its elements into dynamically allocated array
   * 2. Size represents number of elements
   *    & Capacity represents total allocated size.
   * 3. Capacity of vector is important for two important reasons:
   *    a. Reallocation invalidates all references, pointers and iterators for elements of the vector.
   *    b. Reallocation takes time.
   * 4. To avoid reallocation, use reserve() or initialize with size argument.
   *    std::vector<T> v(5);  // creates a vector and initializes it with 5 default values.
   */
  vector<char> v;
  v.push_back('0');
  v.pop_back();
  
  // inserts a copy of elem before iterator position and returns the position of new element
  v.insert(v.end(), '1');
  
  // similary it can insert from other containers
  v.insert(v.end(), s.begin(), s.end());
  PRINT_ELEMENTS(v);
  // Using vectors a c style arrays
  // since data elements in vectors are guranteed in contiguous array
  // &v[i] == &v[0] + i
  v.reserve(41);
  strcpy(&v[0], "hello world");
  PRINT_ELEMENTS(v);

  // using copy algorithm
  copy(v.begin(), v.end(), ostream_iterator<char>(cout, "  "));

  // using swap algorithm
  swap(v[0], v[3]);

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /* class vector<bool>
   *
   * 1. For boolean elements, the C++ standard library 
   * 2. Reserves one bit for element
   * 3. If static size bit vector is used ... bitset . For dynamic, use vector<bool>
   */

    vector<bool> vb;
    vb.push_back(0);
    vb.push_back(1);
    vb.push_back(1);
    vb.back().flip();
    cout<<sizeof(vb)<<endl;
    PRINT_ELEMENTS(vb);
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /* Deque
   * Insertion at front or back does not invalidate pointer. but in middle it may violate
   * insertion and removing at the end is faster.
   * 1. They do not provide functions for capacity and reserve.
   * 2. If they need to grow, they can allocate extra space and attach to current container. Just like linked list.
   * 3. Hence capacity is also not defined.
   */
    
    deque<string> coll;
    coll.assign(3, string("string"));     // it assigns three copies of elements with "string" argument.
    
    coll.push_back("last string");
    coll.push_front("first string");
    PRINT_ELEMENTS(coll);

    /* List
     */

    list<int> list1, list2;

    for (int i = 0; i < 6; i++) {
      list1.push_back(i);
      list2.push_front(i);
    }

    PRINT_ELEMENTS(list1);
    PRINT_ELEMENTS(list2);

    // insert all the elements of list1 before the first element with value 3 of list 2
    list2.splice(find(list2.begin(), list2.end(),3), 
                        list1);                       // source list

    // move first element of list2 to the end
    list2.splice(list2.end(), list2, list2.begin()); // with source list & source position

    /* Forward List */
    /* 1. It is a restrictd list that it is not able to iterate backward.
     * 2. As benefits, it uses less memory and provides slight better runtime behavior.
     * 3. It is as good as C style pointer based list.
     *
     * 4. No reverse_iterator is provided. rbegin(), rend() not valid.
     * 5. size() member function not allowed. 
     * 6. It does not have back(), push_back() function.
     * 7. You can insert_after() which inserts new elements after the element.
     * 
     * 8. To access element front() is used. ( like head() )
     * 9. fwlist.insert_after(fwlist.before_begin(), { 77, 88 . 99 });
     */
    forward_list<int> list3 = { 1, 2, 3 ,4 };
    forward_list<int> list4 = { 77, 88, 99 };

    print_lists(list3,list4);

    //insert six new elements at the beginning of list3.
    list3.insert_after(list3.before_begin(), 99);
    list3.push_front(10);
    list3.insert_after(list3.before_begin(), { 10, 11, 12, 13 });
    print_lists(list3, list4);

    // find first event element in list 3 and insert 42
    auto posBefore = list3.before_begin();
    for(; next(posBefore)!= list3.end(); ++posBefore){
      if(*next(posBefore) %2 == 0)
        break;
    }
    list3.insert_after(posBefore, 42);
  
    // find the position before the first event element
    posBefore = find_before_if(list3.before_begin(), list3.end(), [] (int i){ return i%2 == 0;});

    // insert new element after posBefore
    list3.insert_after(posBefore,42);

    // if we don't pass  before begin() then we skip the first element.
    // insert_after with list.end() results in undefined behavior. it has to be valid iterator. that's why before_begin() is given.

    list3.sort(); // sort the elements
    list3.unique(); // remove duplicate elements;

    // merge both sorted lists into list1

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /* SETS / MULTISETS */
    set<int, greater<int>> colset;
    colset.insert({4, 3, 5, 1, 6, 2 });
    colset.insert(5);

    // print all elements
    PRINT_ELEMENTS(colset);

    // insert 4 again and process return value
    auto status = colset.insert(4); // returns <iterator, status> after insert
    if(!status.second)
      cout<<" 4 already inserted" <<endl;

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /* Maps / Multimaps */
    /* namespace std{
     *  template< typename Key, typename T, typename comapre= less<Key>, typename Allocator = allocator<pair< const Key, T>>>
     *  class map;
     *
     * 1. Just like sets it saves values in RB trees
     * 2. inserts elements as make_pair()
     * 3. Can be treated as associative array but be careful
     * std::cout<< coll["outto"]; will insert the element outto with zero value since operator[] is overloaded for insert.
     */
      
    multimap<string, string> dict;
    dict.insert({
          {"day", "Tag"},
          {"strange", "fremd"},
          {"car", "Auto"},
          {"strange", "seltsam"},
          {"smart", "raffiniert"},
          {"smart", "klug"}
          }
        );
    
    // prints all elements
    cout.setf(ios::left, ios::adjustfield);
    cout<<' '<< setw(10)<<"english"<< "german"<<endl;
    cout<<setfill('-')<<setw(20)<<""<<setfill(' ')<<endl;
    
    for(const auto &elem: dict){
      cout<<' '<<setw(10)<<elem.first<< elem.second<<endl;
    }
    cout<<endl;

    // prints all values for key "smart"
    string word("smart");
    for(auto pos=dict.lower_bound(word); pos!= dict.upper_bound(word); ++pos)
      cout<<"    "<<pos->second<<endl;

    // prints all keys for value "raffiniert"
    word = "raffiniert";
    cout<< word<< ": "<<endl;
    for(const auto &elem: dict){
      if(elem.second == word)
        cout<<"  "<<elem.first<<endl;
    }

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /* Unordered sets / maps
   * 1. Implemented using hash
   * 2. Can specify max_load_factor(0.7) to specify maximum load factor to improve performance
   * 3. Can specify bucket size as hash.reserve(100);    // 100 buckets are reserved.
   * 4. rehash any time. hash.rehash(100);  rehash for 100 buckets.
   *
   * Providing own hashing function. It is a unary function which takes one argument and returns integer;
   * class CustomerHash{
   * public:
   *    size_t operator() (const Customer &c) const{
   *        return ..
   *    }
   * std::unordered_set<Customer, CustomerHash> custset;
   * 
   * can also pass hash function.
   *
   * Providing own equivalence function
   * bool operator(){ const Customer &c1, const Customer &c2){ return .. }
   * std::unordered_set<Customer, CustomerHash, CustomerEqual> custset;
   * std::unordered_map<Customer, string, CustomerHash, CustomerEqual> custtmap; // string is extra for value.
   *
   * bucket interface
   * it is possible to access individual buckets
   * custmap.bucket(val)
   * custmap.bucket_count()
   * custmap.begin(bucketidx) // returns a forward iterator for the first element of the bucket with index bucketidx
   * custmap.end(bucketidx) // returns a forward iterator for the position after last element
   * custmap.bucket_size(bucketidx)  // returns bucket size.
   *
   * It shows that hashmap is created as array of linked list.
   */

    unordered_multiset<int> umultiset = { 1, 2, 3, 4, 5, 6, 7};
    umultiset.insert({-7, 17, 33, -11 , 17 });
    PRINT_ELEMENTS(umultiset);

    // remove all elements with specific value
    umultiset.erase(17);

    // remove one of the elements with specific value
    auto pos = umultiset.find(13);
    if(pos != umultiset.end())
      umultiset.erase(pos);

    PRINT_ELEMENTS(umultiset);
    
    // bucket interface
    //printHashtableState(umultiset);

    unordered_multimap<string, string> dicttable={
      {"day", "Tag"}, {"strange", "fremd"},
      {"car", "Auto"}, {"smart", "elegant"},
      {"trait", "Merkmal"}, {"strange", "seltsam"}
    };
    printHashtableState(dicttable);
  return 0;
}


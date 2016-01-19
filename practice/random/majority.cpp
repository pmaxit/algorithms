#include <iostream>
#include <vector>
using namespace std;


int main(int argc, const char *argv[])
{
  vector<int> a = { 1 ,4 ,4 , 2 , 2 , 3 , 5 , 2, 2 };
  
  int ele = a[0];
  int count =0;
  for( int i=1; i < a.size(); i++){
    if(ele == a[i])
      count++;
    else{
      if(count >0 ) count --;
    }
    if(count == 0){
      ele = a[i];
      count = 1;
    }
  }

  // need to check if ele is majority element or not.
  int cnt = 0;
  for(auto it: a){
    if(it == ele)
      cnt++;
  }
  
  if(cnt > a.size()/2){
    cout<<" element : "<<ele<<" Count: "<<cnt<<endl;
  }
  else
    cout<<" no majority element found "<<endl;
  return 0;
}


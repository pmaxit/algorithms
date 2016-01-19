#include <iostream>
#include <vector>

using namespace std ;

int main(int argc, const char *argv[])
{
  vector<int> arr = { 1 , 3 ,2 , 6, 3, 7, 2 , 5 };
  int A[10] = {1};

  for(int i=1; i< arr.size(); i++){
    for(int j=i-1; j>=0 ;j--){
      if(arr[i] > arr[j])
       A[i] = max(A[i],A[j]+1);
      cout<<" value of i "<< i<<"  "<<A[i]<<endl;
    }
  }

  for(int i=0; i< arr.size(); i++)
    cout<< A[i]<< "  ";
  cout<<endl;
  
  return 0;
}



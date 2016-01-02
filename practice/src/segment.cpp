#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/*
 * Trees in form of array
 * node at i, child at 2*i+1, 2*i+2
 *
 */

int constructSTUtil(int arr[], int l, int r, int st[], int index){
  
  if(l == r){
    st[index ] = arr[l];
    return arr[l];
  }

  int mid = l + ( r - l ) /2;
  st[index] = constructSTUtil(arr, l, mid, st, 2*index+1) + 
    constructSTUtil(arr, mid+1, r, st, 2*index+2);
}

int* constructST(int arr[], int n){
  int x = (int)(ceil(log2(n)));
  int max_size = 2*(int)pow(2,x) -1;
  cout<< max_size<<endl;
  int *st = new int[max_size];

  constructSTUtil(arr, 0, n-1, st, 0);

  return st;
}


int getSumUtil(int st[], int ss, int se, int qs, int qe, int index){
  
  printf(" checking : (%d %d), (%d,%d) : %d \n", ss, se, qs, qe, st[index]);
  if(qs<=ss && se <= qe){
    printf(" returning : %d %d : %d \n", ss, se, st[index]);
    return st[index];
  }

  if(se < qs || ss > qe)
    return 0;

  int mid = ss + (se - ss)/2;
  return getSumUtil(st, ss, mid, qs, qe, 2*index+1) + 
    getSumUtil(st, mid+1, se, qs, qe, 2*index+2);
}
// qs : start Index
// qe : end Index
int getSum(int st[], int n, int qs, int qe){
  
  return getSumUtil(st, 0, n-1, qs, qe, 0);
}


int main(int argc, const char *argv[])
{
  int arr[] = {1, 3, 5, 7, 9, 11};
  int n = sizeof(arr)/sizeof(arr[0]);

  // Build a segment tree
  int *st = constructST(arr, n);
  for(int i=0; i < 15; i++)
    printf("i: %d - %d \n", i, st[i]);
  printf("\n");

  printf("Sum of values in given range %d\n", getSum(st, n, 1,4));

  // update value

  return 0;
}


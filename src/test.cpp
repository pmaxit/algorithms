#include <iostream>
#include <fstream>
#include <string>
#include "heap.h"

using namespace std;

int getKsmallest(int arr[], int n, int k){
    Heap<int> h(arr, n);

    while(k-- && !h.empty()) h.extractMin();

    if(!h.empty())
        return h.getMin();
    else
        return -1;
}

// using max heap to find k smallest element
int getKsmallest2(int arr[], int n, int k){

    std::vector<int> v(arr, arr+k);

    // make max heap of k elements
    std::make_heap(v.begin(), v.end());

    for(int i=k; i<n ; i++){
        if(arr[i] < v.front()){
            // replace root with this element and call heapify
            std::pop_heap(v.begin(), v.end());    // last element is now at size -1

            v.pop_back();
            v.push_back(arr[i]);
            std::push_heap(v.begin(), v.end());
        }
    }

    return v.front();
}

// using max heap to get k largest element
int getKlargest(int arr[], int n, int k){
    vector<int> v(arr , arr+k);

    // make min heap of k elements
    std::make_heap(v.begin(), v.end(), std::greater<int>());

    // confirm whether its min heap or not
    //cout<<"front: "<<v.front()<<"  "<<endl;

    for(int i=k; i<n ;i++){
        // check if it is bigger than root
        if(arr[i] > v.front()){
            // exchange it with root
            std::pop_heap(v.begin(), v.end(),std::greater<int>());

            v.pop_back();
            v.push_back(arr[i]);

            std::push_heap(v.begin(), v.end(),std::greater<int>());
        }
    }
    return v.front();
}


// Quick sort method to find k largest
int partition(int arr[], int start , int end){

    int pivot = end;
    int left = start;
    int right = end-1;


    while(left < right){
        while(arr[left] < arr[pivot])left++;

        while(arr[right]> arr[pivot])right--;

        if(left < right) swap(arr[left], arr[right]);

    }
    // left is the final place for pivot
    swap(arr[left], arr[pivot]);
    return left;
}

int kthSmallest(int arr[], int l, int r, int k){
    if( k > 0 && k <= r - l + 1){

        int pos = partition(arr, l, r, k);

        if(pos == k)
            return arr[pos];

        else if (pos > k)
            return kthSmallest(arr, l, pos-l , k);
        else
            return kthSmallest(arr, pos )
    }
}

int main(int argc, const char *argv[])
{
    int a[]={20 , 8 ,1, 5, 4, 9 , 11 ,6};

    int size = sizeof(a)/sizeof(a[0]);

    for(auto i: a){
        cout<<i<<"   ";
    }
    cout<<endl;

    int index = partition(a, 0, size-1);
    for(auto i: a){
        cout<<i<<"   ";
    }
    cout<<"index: "<<index<<endl;

    cout<<" k smallest "<< getKsmallest(a, size, 3)<<endl;

    cout<<" k smallest "<<getKsmallest2(a, size, 3)<<endl;

    cout<<" k largest "<<getKlargest(a, size, 3)<<endl;

    cout<<"k largest "<<findKlargest3(a, size, 3)<<endl;

    return 0;
}

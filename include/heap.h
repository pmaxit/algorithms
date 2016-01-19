#ifndef HEAP
#define HEAP

#include<iostream>
#include<vector>

using namespace std;

template<class T=int>
int mincmp(T &a , T &b){
    return a < b;
}

template<class T=int>
int maxcmp(T &a, T &b){
    return a > b;
}

template<class T=int>
class Heap{
public:
    Heap(int (*cmp)(T &a, T&b)= mincmp);
    Heap(T a[], int size, int (*cmp)(T &a, T &b) = mincmp);
    int parent(int i){ return (i-1) /2 ; }
    int left(int i) { return 2*i+1; }
    int right(int i) { return 2*i + 2 ;}
    int empty(){return size == 0; }


    int extractMin(); // extracts root (minimum) Element
    T getMin() { return arr[0]; }
    void heapify(int i);
    int insert(T data);
    void buildHeap(T a[], int size);
    void print(ostream &out);

    friend ostream& operator<<(ostream &out, Heap<T> &heap){
        heap.print(out);
        return out;
    }

private:
    vector<T> arr;
    int capacity;
    int size;

    int (*cmp)(T &a, T &b);
    void shiftUp(int index);

};

#endif // MINHEAP


// implementation
template<class T>
Heap<T>::Heap(int (*cmp)(T &a, T &b)):cmp(cmp){
    capacity = 0;
    size=0;
}

template<class T>
Heap<T>::Heap(T a[], int sz, int (*cmp)(T &a, T &b)):Heap<T>(cmp){

    buildHeap(a, sz); // faster implementation than insert for every element
    capacity = 0;
    size = sz;
}

template<class T>
int Heap<T>::extractMin(){
    arr[0] = arr[size-1];
    heapify(0);
    size--;
    return 0;
}

template<class T>
void Heap<T>::heapify(int i){
    // check if it is max or min heapify
    int l = left(i);
    int r = right(i);
    int cur = i;
    if(l < size && cmp(arr[l], arr[cur]))
        cur = l;
    if(r < size && cmp(arr[r], arr[cur]))
        cur = r;

    if(cur != i){
        swap<T>(arr[i], arr[cur]);
        heapify(cur);
    }
}

template<class T>
int Heap<T>::insert(T data){
    arr.push_back(data);

    shiftUp(size);
    size++;

    return 0;
}

template<class T>
void Heap<T>::shiftUp(int index){
    T val = arr[index];
    int p = parent(index);
    while(p>=0 && arr[p] > val)
        p = parent(p);
    swap<T>(arr[index], arr[p]);
}

/*
 * Build Heap : faster implementation of O(N)
 * Better than inserting element one by one
 */
template<class T>
void Heap<T>::buildHeap(T a[], int size){
    arr.insert(arr.end(), &a[0], &a[size]);
    for(int i=size/2; i>=0; i--)
        heapify(i);
}

template<class T>
void Heap<T>::print(ostream &out){

    for(int i =0; i< size; i++)
        out<<"i:  "<< i<<"   "<<arr[i]<<"  "<<endl;
}

/*
 *
    Heap<int> h(a, size);


    cout<<h;

    while(!h.empty()){
        cout<< h.getMin()<< "  "<<endl;
        h.extractMin();
    }
*/

#include "Heap.h"
void HeapSort(int A[],size_t n){
    if(n <=1){
     return;
    }
    Heap<int> myHeap(A,n);
    size_t lastindex = myHeap.getCount()-1;
    for(size_t i = lastindex; i >= 1; --i){
        myHeap.buildMaxHeap();
        A[i] = myHeap.getRoot();
        myHeap.deleteRoot();
    }
    A[0] = myHeap.getRoot();
}
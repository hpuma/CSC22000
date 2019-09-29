#include "Heap.h"
void HeapSort(int A[],size_t n){
    if(n <= 1){
        return;
    }
    Heap<int> myHeap(A,n);
    myHeap.buildMaxHeap();
    cout<<myHeap.getRoot()<<"\n";
}
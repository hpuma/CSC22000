#include "Heap.h"
void HeapSort(int A[],size_t n){
    // If the array is empty or there is only 1 element, then do nothing.. A single element is already sorted
    // and an empty array cannot be sorted.
    if(n <=1){
     return;
    }
    // Creates a heap containing the array.
    Heap<int> myHeap(A,n);
    // Gets the last element that is accesable.
    size_t lastindex = myHeap.getCount()-1;

    // From the last node to the left child of the root.
    for(size_t i = lastindex; i >= 1; --i){
        // Create a max heap, the greatest value is at the root.
        myHeap.buildMaxHeap();
        // Set the last item of the input array to the greatest value of the array.
        A[i] = myHeap.getRoot();
        // Delete the node from the root so that we find the next greatest value.
        myHeap.deleteRoot();
    }
    // All the nodes have been deleted besides the root, then add the root to the first index
    // of the input array.s
    A[0] = myHeap.getRoot();
}
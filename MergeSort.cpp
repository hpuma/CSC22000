# include "ArrayBuilder.h"
/* Time Complexity: Θ(n*logn)
 A: Array to be sorted
 p: is the first accesable element. 0 index
 r: is the last accesable element. n-1 index
*/
void MergeSort(int A[], size_t p, size_t r, bool Trace){
    // Check if we are the lowest posssible sub problem ... can we split the array further?
    if(p < r){ // Θ(1)
        // Find the midpoint of the array.
        size_t q = floor((p+r)/2); // Θ(1)
        // Split from the left part of the splitted array.
        MergeSort(A,p,q,Trace); // T(n/2)
        // Split from the right side of the splitted array.
        MergeSort(A,q+1,r,Trace); // T(n/2)
        // Applies Merge to the right side of the array????
        Merge(A,p,q,r,Trace);
    }
}
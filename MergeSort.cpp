// Merge Sort Algorithm
// p: is the first accesable element.
// r: is the last accesable element.
void MergeSort(int A[], size_t p, size_t r){
    // Check if we are the lowest posssible sub problem ... can we split the array further?
    if(p < r){
        // Find the midpoint of the array.
        size_t q = floor((p+r)/2);
        // Split from the left part of the splitted array.
        MergeSort(A,p,q);
        // Split from the right side of the splitted array.
        MergeSort(A,q+1,r);
        // Applies Merge to the right side of the array????
        Merge(A,p,q,r);
    }
}
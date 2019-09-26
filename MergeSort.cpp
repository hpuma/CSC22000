void MergeSort(int A[], size_t p, size_t r){
    if(p < r){
        size_t q = floor((p+r)/2);
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        Merge(A,p,q,r);
    }
}
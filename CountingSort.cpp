#include "Arraybuilder.h"
/*
A: Array of size n that needs to be sorted. Must be in range 0 .. k
B: Output Array, sorted version of A. Also size n and in range 0 ..k
n: Size of the input and output arrays.
k: Range of values within A.
if Trace:
TRACK A TO C: Prints out C after iterating through A.
SUM PREVIOUS C: Prints out C after summing the pairs of elements.
B: Prints out the sorted array.*/
void CountingSort(int A[], int B[], size_t n, size_t k, bool Trace){
    ArrayBuilder f; // Used to print arrays when needed.
    // C: Used to keep count of all the value counts in A.
    int* C = new int[k+1]; // We extend C by 1 since we are dealing with 0 indexing.

    // Initialize all the values in C to 0.
    // NOTE: We go all the way up to k index because C has that extra space
    for (size_t i = 0; i <= k; i++){
        C[i] = 0;
    }
    // Iterate through A, and incremement it's count in C by 1.
    for (size_t j = 0; j < n; j++){
        C[A[j]] += 1;
    }
    if(Trace){
        cout<<"\nTRACK A TO C:\t";
        f.printArr(C,n+1);
        cout<<"\n";
    }
    // Start from the second element in C, and add the count from the previous element to 
    // the current element.
    // NOTE: We go all the way up to k index because C has that extra space
    for(size_t i = 1; i <= k; i++){
        C[i] = C[i] + C[i-1];
    }
    if(Trace){
        cout<<"SUM PREVIOUS C:\t";
        f.printArr(C,n+1);
        cout<<"\n";
    }
    // Iterates through A
    // USE the value from A, to access C.
    // Then take the value of C to access B
    // Finally, add the value from A to B.
    for(size_t j = 0; j  < n; j++){
        B[C[A[j]]-1] = A[j];    // NOTE: we subtract by 1 because of 0 indexing.
        C[A[j]] -= 1; 
    }
    if(Trace){
        cout<<"B:\t\t";
        f.printArr(B,n);
    }
}
int getMax(int A[], size_t n){
    int maxVal = INT_MIN;
    for(int i = 0; i < n; i++){
        if(A[i] > maxVal){
            maxVal = A[i];
        }
    }
    return maxVal;
}
void CountingRadix(int A[],int B[], int C[], size_t n, size_t k, bool Trace){
    int count[k+1];
    int A_SORT[n];
    int B_SORT[n];
    int C_SORT[n];
    for(int i = 0; i <= k; i++){
        count[i] = 0;
    }
    for(int j = 0; j < n; j++){
        count[A[j]] += 1;
    }
    for(int i = 1; i <= k; i++){
        count[i] = count[i] + count[i-1];
    }
    for(int j = 0; j < n; j++){
        A_SORT[count[A[j]]-1] = A[j];
        B_SORT[count[A[j]]-1] = B[j];
        C_SORT[count[A[j]]-1] = C[j];
        count[A[j]] -=1;
    }
    for (int i = 0; i < n; i++){
        A[i] = A_SORT[i];
        B[i] = B_SORT[i];
        C[i] = C_SORT[i];
    }
    if(Trace){
        ArrayBuilder f;
        cout<<"A:\t";
        f.printArr(A,n);
        cout<<"B:\t";
        f.printArr(B,n);
        cout<<"C:\t";
        f.printArr(C,n);
        cout<<"\n";
    }
}
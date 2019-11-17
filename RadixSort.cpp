#include "ArrayBuilder.h"
#include "CountingSort.cpp"
// The main function to that sorts arr[] of size n using  
// Radix Sort 
void RadixSort(int hundreds[], int tens[], int ones[], size_t n, bool Trace){
    int ones_max = getMax(ones, n);
    int tens_max = getMax(tens, n);
    int hundreds_max = getMax(hundreds, n);
    CountingRadix(ones,tens,hundreds,n,ones_max,Trace);
    CountingRadix(tens,hundreds,ones,n,tens_max,Trace);
    CountingRadix(hundreds,tens,ones,n,hundreds_max,Trace);
    if(Trace){
        ArrayBuilder f;
        cout<<"Hundreds:\t";
        f.printArr(hundreds,n);
        cout<<"Tens:\t";
        f.printArr(tens,n);
        cout<<"Ones:\t";
        f.printArr(ones,n);
    }
} 
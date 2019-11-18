#include "ArrayBuilder.h"
#include "CountingSort.cpp"
// The main function to that sorts arr[] of size n using  
// Radix Sort 
void RadixSort(int hundreds[], int tens[], int ones[], size_t n, bool Trace){
    int ones_max = getMax(ones, n);
    int tens_max = getMax(tens, n);
    int hundreds_max = getMax(hundreds, n);
    CountingSort(ones,n,ones_max,Trace);
    CountingSort(tens,n,tens_max,Trace);
    CountingSort(hundreds,n,hundreds_max,Trace);

    if(Trace){
        ArrayBuilder f;
        cout<<"\nHundreds:";
        f.printArr(hundreds,n);
        cout<<"\nTens:\t";
        f.printArr(tens,n);
        cout<<"\nOnes:\t";
        f.printArr(ones,n);
        cout<<"\n";
    }
} 
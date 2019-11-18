# include "ArrayBuilder.h"
/* Time Complexity: O(n^2)
    Stable: YES
    InPlace: YES
NOTE: In order to apply this sorting algorithm, A MUST have at LEAST 2 elements
A: Array to be sorted
n: size of the array
Trace: TRUE == print array when changed.
*/
void insertionSort(int A[], int n, bool Trace){
    // The Array must have at LEAST 2 elemnents in order to be sorted. If it has less, than 2, then do NOTHING.
    if(n < 2){ return; } 
    // Iterate the array starting from the second element.
    for(int j = 1; j < n; j++){ //  Θ(n-1)
        // Store the Current Value <-> key.
        int key = A[j]; //  Θ(1)
        // Make another variable i to look at the element before you.
        int i = j-1; // Θ(1)
        // If the previous element is greater than KEY.
        while(i > -1 && A[i] > key){ // O(n)
            // Move the previous value forwards.
            A[i+1] = A[i]; // Θ(1)
            if(Trace){
                ArrayBuilder f;
                f.printArr(A,n);
            }
            // Move left.
            i = i-1; // Θ(1)
        } 
        // Move the KEY behind the larger values.
        A[i+1] = key; // Θ(1)
        if(Trace){
            ArrayBuilder f;
            f.printArr(A,n);
        }
    }
}
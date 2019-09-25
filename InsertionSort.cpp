// NEED To : Draw out each iteration.
void insertionSort(int A[], int n){
    if(n < 2){ return; } // The Array must have at LEAST 2 elemnents in order to be sorted. If it has less, than 2, then do NOTHING.
    for(int j = 1; j < n; j++){ // Iterate the array starting from the second element.
        int key = A[j]; // Store the Current Value <-> key.
        int i = j-1; // Make another variable i to look at the element before you.
        while(i > -1 && A[i] > key){ //If the element before the Current Value is greater than the current value.
            A[i+1] = A[i]; // Move the current value backwards.
            i = i-1; // Move left.
        }
    A[i+1] = key; // Swap the current value to the correct place.
    }
}
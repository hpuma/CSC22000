/*  Henry Puma
    Ahmet Yuksel 
    CSC 22000

    A[] is the input array.
    n is the current size of A.

    Best Case: The array is already sorted, there is no need for shuffling, there are n comparisons. 
    Theta(n)
    Average Case: The array is not sorted, still does comparisons in the while-loop 
    Theta(n^2)
    Worst Case: The array is in non increasing order there is n-1 iterations in the for-loop and approximently n iterations in the while-loop
    Theta(n^2)
*/

void insertionSort(int A[], int n){
    // This loop starts at the second element in the array A[1] and iterates until the last possible index.
        int key = A[j]; // C1: Stores the current value A[j] as "KEY", this will be used for comparisons in the future.
        int i = j-1; // C2: Make another variable i to look at the element before you. This is a temp variable to iterate backwards of the array.
        while(i > -1 && A[i] > key){ // C(n) times:  If the A[i] value is greater than the "KEY" value then.
            A[i+1] = A[i]; // C3: Swap the values. 
            i = i-1; // C4: Move the current index i backwards.
        }
    A[i+1] = key; // C(n-1) times: Swap the current value to the correct place because everything to the right of i is greater than "KEY".
    }
}

/*
 Sample input: A = {1,5,3,4}, and n == 4

 Base Case: When n == 1, then S(1)
 An array of size 1 is by definition already sorted because there is nothing else to compare it to. This is before the first j iteration.
 Anything in A[0.. j-1] are sorted before any comparisons.
 Since S(1) holds, we can assume S(n+1)
Office hours for guidance ... 

*/

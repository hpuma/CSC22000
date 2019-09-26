// MERGE ... Takes two sub arrays and sorts them in non decreasing order.
// NOTE: p == 0, q == n/2 and r = n-1
// Page 31 of textbook

void merge(int A[], int p, int q, int r){
    // Divides the array into two subarrays of equal length.
    int n1 = q - p+1;
    int n2 = r - q;
    // We make two arrays L for left and R for right. Both arrays have an additional element to store the sentinal value.
    int L[n1+1] = {};
    int R[n2+1] = {};

    // Setting up the ndexes of the left and right subarrays used to store the halves of A/
    int i = 0;  
    int j = 0;

    // We take the first half of the array and copy the values it to L.
    for(i = 0; i < n1; i++){
        L[i] = A[p+i];
    }
    // We take the second half of the array and copy the values to R.
    for (j = 0; j < n2; j++){
        R[j] = A[q+j+1];
    }

    /* This stores a sentinal value of the largest possible number in the last element
    this value will help us determine which array is empty and add on the rest of the non empty array.*/
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    // We are preparing for the sub array comparisons, this means we reset the indexes of the left and right sub arrays.
    i = 0; 
    j = 0;
    // For loop that iterates both arrays of equal lengths, the smallest one gets sorted...
    for (int k = p; k <= r; k++){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
}
/*Merge: Helper function for MergeSort.
 Takes two sub arrays and sorts them in non decreasing order.
 NOTE: p == 0, q == n/2 and r = n-1
 Page 31 of textbook.
*/
# include "ArrayBuilder.h"
# include <iomanip>
void Merge(int A[], int p, int q, int r, bool Trace){
    // Divides the array into two subarrays of equal length.
    int n1 = q - p+1; // Beginning to middle  Θ(1)
    int n2 = r - q; // 1 after middle to end  Θ(1)
    // We split the array in half and assign it to L for left and R for right. Both arrays have an additional element to store a sentinal value.
    // The sentinel value will be used to determine the small array is finished traversing.
    int L[n1+1] = {}; // Θ(1)
    int R[n2+1] = {}; // Θ(1)

    // Setting up the indexes of the left and right subarrays used to store the halves of A.
    int i = 0;  // Θ(1)
    int j = 0; // Θ(1)

    // We take the first half of the array and copy the values it to L.
    for(i = 0; i < n1; i++){ // Θ(n)
        L[i] = A[p+i];
    }
    // We take the second half of the array and copy the values to R.
    for (j = 0; j < n2; j++){  // Θ(n)
        R[j] = A[q+j+1];
    }

    /* This stores a sentinal value of the largest possible number in the last element.
    this value will help us determine which array is empty and add on the rest of the non empty array.*/
    L[n1] = INT_MAX; // Θ(1)
    R[n2] = INT_MAX; // Θ(1)
    if(Trace){
        ArrayBuilder f;
        cout<<"LEFT:";
        cout<<"\t\tRIGHT:\n";
        f.printArr(L,n1);
        cout<<"\t\t";
        f.printArr(R,n2);
        cout<<"\n";
    }
    // We are preparing for the sub array comparisons, this means we reset the indexes of the left and right sub arrays.
    i = 0;  // Θ(1)
    j = 0; // Θ(1)
    // For loop that iterates both arrays of equal lengths, the smallest one get added to A until both R and L are empty.
    for (int k = p; k <= r; k++){ // Θ(n)
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
    if(Trace){
        ArrayBuilder f;
        cout<<"A:";
        f.printArr(A,r+1);
        cout<<"\n\n";
    }
}
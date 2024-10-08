// S: 10/16/19
void swap(int A[], int size, int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int Partition(int A[], int size, int p, int r){
    int x = A[r];
    int i = p-1;
    for(int j = p; j < r-1; j++){
        if(A[j] <= x){
            i = i+1;
            swap(A,size,i,j);
        }
    }
    swap(A,size,i+1,r);
    return i+1;
}


void QuickSort(int A[], int size, int p, int r){
    if(p < r){
        int q = Partition(A,size,p,r);
        QuickSort(A,size,p,q-1);
        QuickSort(A,size,q+1,r);
    }
}
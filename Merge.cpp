#include<cmath> 
// PAGE 31 of textbook

void merge(int A[], int p, int q, int r){
int n1 = q - p + 1;
int n2 = r - q;
int L[n1+1]; int R[n2+1];
int i ,j = 1;

for(i = 1; i <= n1; i++){
    L[i] = A[p+1-1];
}
for (j = 1; j <= n2; j++){
    R[j] = A[q+j];
}
L[n1+1] = INT_MAX;
R[n2+1] = INT_MAX;
i = 1; j =1;
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
#include <iostream>
using namespace std;
void insertionSort(int A[], int n){
    if(n < 2){ return; }
    for(int j = 1; j < n; j++){
        int key = A[j];
        int i = j-1;
        while(i > -1 && A[i] > key){
            A[i+1] = A[i];
            i = i-1;
        }
    A[i+1] = key;
    }
}
int main(){
    int testArr[] = {1,4,2,5,3};
    int size = 5;
    cout<<"BEFORE:\t";
    for(int i =0; i < size; i++){
        cout<<testArr[i];
    }
    insertionSort(testArr,size);
    cout<<"\nAFTER:\t";
    for(int j = 0; j < size; j++){
        cout<<testArr[j];
    }

    return 0;
}
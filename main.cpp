#include <iostream>
#include <cmath> 
#include <bits/stdc++.h> // for INT_MAX,
#include <cstdlib> // Provides size_t type.
#include "InsertionSort.cpp"
#include "Merge.cpp"
#include "MergeSort.cpp"
#include "Heap.h"
#include "HeapSort.cpp"
using namespace std;
template<class Item> 
void printArr(Item A[],int n){
    cout<<"[";
    for(size_t i = 0; i < n; i++){
			cout<<A[i];
			if(i != n-1){
				cout<<","<<setw(2);
			}
	}
	cout<<"]\n";
}
int main(){
    int testArr[] = {2,4,5,7,1,8,3,6};
    int size = 8;
    // Merge Sort.
    printArr(testArr,size);
    MergeSort(testArr,0,7);
    printArr(testArr,size);

    return 0;
}
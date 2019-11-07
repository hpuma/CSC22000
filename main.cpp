#include <iostream>
#include <cmath> 
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h> // Provides INT_MAX,
#include <cstddef> // Provides size_t type.
#include "ArrayBuilder.h"
#include "InsertionSort.cpp"
#include "Merge.cpp"
#include "MergeSort.cpp"
#include "HeapSort.cpp"
#include "QuickSort.cpp"
using namespace std;
template<class Item>
void printArr(Item A[],size_t n){
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
    ArrayBuilder test();
    int testArr[] = {2,4,5,6,1,7,3};
    size_t size = 7;
    cout<<"BEFORE:\t"; printArr(testArr,size);

    // MERGE SORT
    // MergeSort(testArr,0,size-1);

    //HEAP SORT
    // HeapSort(testArr,size);
    QuickSort(testArr,size,0,6);

    cout<<"AFTER:\t"; printArr(testArr,size);
    return 0;
}
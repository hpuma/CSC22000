#include <iostream>
#include <cmath> 
#include <bits/stdc++.h> // Provides INT_MAX,
#include <cstddef> // Provides size_t type.
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
    int testArr[] = {2,4,5,6,1,7,3};
    size_t size = 7;
    cout<<"BEFORE:\t"; printArr(testArr,size);

    // Merge Sort.
    // MergeSort(testArr,0,size-1);

    //HeapSort
    HeapSort(testArr,size);

    cout<<"AFTER:\t"; printArr(testArr,size);
    return 0;
}
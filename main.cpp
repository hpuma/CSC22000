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
#include "Node.h"
using namespace std;

int main(){
    int testArr[] = {8,2,4,9,3,6};
    size_t size = 6;
    Node<int>* test = new Node<int>(10);
    cout<<test->getData();
    return 0;
}
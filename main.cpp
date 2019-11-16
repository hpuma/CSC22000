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
#include "BST.h"

using namespace std;

int main(){
    int testArr[] = {8,2,4,9,3,6};
    size_t size = 6;
    Node<int>* test = new Node<int>(10);
    cout<<test->getData()<<"\n";
    BST testNode(test);
    Node<int>* n1 = new Node<int>(2);
    Node<int>* n2 = new Node<int>(45);
    Node<int>* n3 = new Node<int>(114);
    Node<int>* n4 = new Node<int>(42);

    testNode.insertNode(n1);
    testNode.insertNode(n2);
    
    testNode.insertNode(n3);
    testNode.insertNode(n4);
    testNode.insertNode(new Node<int>(1));
    print(test,1);
    return 0;
}
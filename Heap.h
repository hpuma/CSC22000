#ifndef __HEAP_H__
#define __HEAP_H__
// Previous two lines are the start of the marco guard

// CSc 21200 - Spring 2019
// Homework 5 header file

// Try not to change this file

#include <iostream>
#include <cassert>    // Provides assert
#include <cctype>
#include <cmath>      // Provides floor
#include <cstdio>
#include <cstdlib>    // Provides size_t
#include <climits>

using namespace std;

template <class Item>
class Heap
{
public:
    const size_t DEF_CAP = 30;
    // CONSTRUCTOR
    Heap(){
	capacity = DEF_CAP;
	data = new Item[capacity];
	count = 0;
    }
    Heap(Item inputData[],int n){
	assert(n < capacity);
	capacity = DEF_CAP;
	Item* newData = new Item[capacity];
	for(int i = 0; i < n; i++){
		newData[i] = inputData[i];
	}
	delete data;
	data = newData;
	count = n;
    }

    size_t getCount() {return count;}

	// This only applies to one set of parent and children.
    void maxHeapify(const size_t& i){
	// NOTE: Current Node i = Parent.
	// Set the largest node as the current node by default. This is the index of the element with the largest value.
	    size_t largest = i;

	// Make sure that the left childindex is within the array bounds AND check if the left child has its value greater than the parent.
	    if (left(i) <= getCount() && data[left(i)] > data[i]){
		largest = left(i); // If the right child has a greater value than the value at the largest index, then set the largest index to the left child index.
	    }
	    else{
		largest = i;  // Set the largest to the parent.
	    }
	// Make sure that the right child index is within the array bounds AND check if the value of the right child is greater than the node at the largest index.
	    if(right(i) <= getCount() && data[right(i)] > data[largest]){
		    largest = right(i); // If the right child has a greater value than the value at the largest index, then set the largest index to the right child index.
	    }
	/* This while loop checks if one of the children nodes have a greater value than the parent. If it doesn't, then largest = i which is the parent.
	This means that there is no swapping required.
	However, if a child has the largest value then the index of that child will be stored in largest
	A swap must occur to apply the Max Heap property.*/
	    if(largest != i){ 
		    swap(data[i],data[largest]); 
		    maxHeapify(largest);
	    }
    }
    void buildMaxHeap(){
	// Apply the max heap property from the bottom to top.
	size_t heapSize = getCount();
	for (size_t i = floor(heapSize/2); i >= 0; i--){
		maxHeapify(i);
	}
}
    Item minimum();
    Item maximum();
    
private:
    Item* data;
    size_t count;
    size_t capacity;

    size_t parent(size_t i) {return floor((i-1)/2);}
    size_t left  (size_t i) {return 2*i+1;}
    size_t right (size_t i) {return 2*i+2;}
};

template <class Item>
void swap(Item& x, Item& y) {
	Item temp = x;
	x = y;
	y = temp;
}

#endif
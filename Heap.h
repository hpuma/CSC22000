#ifndef __HEAP_H__
#define __HEAP_H__
// Class Defeinition of Heap in Dynamic Array format.
#include <iostream>
#include <iomanip>	// Provides setw
#include <cassert>  // Provides assert
#include <cctype>
#include <cmath>    // Provides floor
#include <cstdio>
#include <cstdlib>  // Provides size_t
#include <climits>

using namespace std;

template <class Item>
class Heap
{
public:
    const size_t DEF_CAP = 30;
    // CONSTRUCTORS
    Heap(){
	capacity = DEF_CAP;
	data = new Item[capacity];
	count = 0;
    }
	// Overwrites the current Heap Data.
	// n: is the size of the "inputData" array.
    Heap(Item inputData[], size_t n){
	capacity = DEF_CAP;
	Item* newData = new Item[capacity];
	for(size_t i = 0; i < n; i++){
		newData[i] = inputData[i];
	}
	data = newData;
	count = n;
    }
	// Returns the number of non-empty elements within the Heap.
    size_t getCount() const{
		return count;
	}
	void deleteRoot(){
		if(getCount() == 0){
			return;
		}else{
		size_t  lastIndex = getCount() - 1;
		data[0] = data[lastIndex];
		count--;
		}
	}
	Item getRoot() const{
		if(getCount() == 0){
			return Item();
		}
		return data[0];
	}	
	// This only applies to one set of parent and children.
    void maxHeapify(const size_t& i){
	// NOTE: Current Node i = Parent.
	// Set the largest node as the current node by default. This is the index of the element with the largest value.
	    size_t largest = i;
	// Make sure that the left childindex is within the array bounds AND check if the left child has its value greater than the parent.
	    if (left(i) < getCount() && data[left(i)] > data[i]){
		largest = left(i); // If the right child has a greater value than the value at the largest index, then set the largest index to the left child index.
	    }
	    else{
		largest = i;  // Set the largest to the parent.
	    }
	// Make sure that the right child index is within the array bounds AND check if the value of the right child is greater than the node at the largest index.
	    if(right(i) < getCount() && data[right(i)] > data[largest]){
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
	// The last node that has children is located within floor(heapSize/2), if we decrement the index of the data array we are actually traversing the Heap upwards.
	// BuildMaxHeap applies the Max Heap property to all the nodes within the Heap.
    void buildMaxHeap(){
		// Gets the size of the size of the Heap. If there is a single node or an empty Heap, then we don't do anything to the Heap.
		size_t heapSize = getCount();
		if(heapSize <= 1){
			return;
		}
		for (size_t i = floor((heapSize-1)/2); i >= 1; i--){
			maxHeapify(i);
		}
		maxHeapify(0);
	}	
	// Simple function that prints the current data within the Heap.
	void printHeap(){
		size_t n = getCount();
		cout<<"HEAP:\t[";
		for(size_t i = 0; i < n; i++){
			cout<<data[i];
			if(i != n-1){
				cout<<","<<setw(2);
			}
		}
		cout<<"]\n";
	}
    
private:
    Item* data;
    size_t count;
    size_t capacity;
	// Node access within the heap.
    size_t parent(const size_t& i) {return floor((i-1)/2);}
    size_t left  (const size_t& i) {return (2*i)+1;}
    size_t right (const size_t& i) {return (2*i)+2;}
};

template <class Item>
void swap(Item& x,Item& y) {
	Item temp = x;
	x = y;
	y = temp;
}
#endif
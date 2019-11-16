#ifndef __NODE_H__
#define __NODE_H__
#include <iostream>
#include <iomanip>	// Provides setw
#include <cassert>  // Provides assert
#include <cctype>
#include <cmath>    // Provides floor
#include <cstdio>
#include <cstdlib>  // Provides size_t
#include <climits>
template <class Item> 
class Node{

private:
Item data;
Node<Item>* leftChild;
Node<Item>* rightChild;
public:
Node(){
    this->data = Item();
    this->leftChild = NULL;
    this->rightChild = NULL;
}
Node(Item Data, Node<Item>* leftChild = NULL, Node<Item>* rightChild = NULL){
    this->data = Data;
    this->leftChild = leftChild;
    this->rightChild = rightChild;
}
~Node(){
    this->data = 0;
    delete leftChild;
    delete rightChild;
}
void setData(Item Data){
    this->data = Data;
}
void setLeft(Node<Item>* Node){
    this->leftChild = Node;
}
void setRight(Node<Item>* Node){
    this->rightChild;
}
Item getData() const{
    return (this->data);
}
Node<Item>* getRight() const{
    return this->rightChild;
}
Node<Item>* getLeft() const{
    return this->leftChild;
}
bool isLeaf() const{
    return (this->leftChild == NULL && this->rightChild == NULL);
}

};
#endif
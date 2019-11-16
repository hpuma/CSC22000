#ifndef __NODE_H__
#define __NODE_H__
#include <iostream>
#include <iomanip>
#include <cassert> 
#include <cctype>
#include <cmath>    
#include <cstdio>
#include <cstdlib>  
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
    this->data = Item();
    delete leftChild;
    delete rightChild;
}
void setData(Item Data){
    this->data = Data;
}
void setLeft(Node<Item>* node){
    this->leftChild = node;
}
void setRight(Node<Item>* node){
    this->rightChild = node;
}
Item getData(){
    return data;
}
Node<Item>* getLeft() {
    return this->leftChild;
}
Node<Item>* getRight() {
    return this->rightChild;
}

bool isLeaf() {
    return (this->leftChild == NULL && this->rightChild == NULL);
}
};



#endif
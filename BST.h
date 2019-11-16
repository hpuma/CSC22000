

#include "Node.h"
#include <cmath>
#include <iomanip>

class BST{
public:
typedef int Item;
Node<Item>* root;
size_t nodeCount;

BST(){
this->root = NULL;
this->nodeCount = 0;
}
BST(Node<Item>* Root){
    this->root = Root;
}
void insertNode(Node<Item>* node){
    if(root == NULL){
        root = node;
        return;
    }
    Node<Item>* currentNode = root;
    while(!currentNode->isLeaf()){
        if(node->getData() < currentNode->getData()){
            if(currentNode->getLeft() != NULL){
                currentNode = currentNode->getLeft();
            }else{
                currentNode->setLeft(node);
                currentNode = currentNode->getLeft();
            }
        }
        if(node->getData() > currentNode->getData()){
            if(currentNode->getRight() != NULL){
                currentNode = currentNode->getRight();
            }else{
                currentNode->setRight(node);
                currentNode = currentNode->getRight();
            }
        }    
    }
    if(currentNode->getLeft() == NULL && node->getData() < currentNode->getData()){
        currentNode->setLeft(node);
    }
    else if(node->getRight() == NULL && node->getData() > currentNode->getData()){
        currentNode->setRight(node);
    }    
    nodeCount++;
}

size_t getDepth(){
    return floor(log2(nodeCount));
}
Node<Item>* getRoot(){
    return this->root;
}

};

template<class Item, class SizeType> 
void print(Node<Item>* nodePtr, SizeType depth){
     cout<<setw(4*depth)<<"";
     if(nodePtr == NULL){
        cout<<"Empty\n";
     }  
     else if(nodePtr->isLeaf()){
        cout<<nodePtr->getData()<<"LEAF\n";
     }  
     else{
        cout<<nodePtr->getData()<<"\n";
        print(nodePtr->getLeft(), depth+1);
        print(nodePtr->getRight(), depth+1);   
     }   
}
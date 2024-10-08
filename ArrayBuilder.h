#ifndef __ARRAYBUILDER_H__
#define __ARRAYBUILDER_H__
#include <iostream>
#include <iomanip>
#include <time.h>		   //for srand seed generator
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;

class ArrayBuilder{

private:
int* Data;
size_t DataSize;

public:
ArrayBuilder(){
    Data = NULL;
    DataSize = 0;
}
ArrayBuilder(int InputData[], size_t DataSize){
    int* NewData = new int[DataSize];
    this->DataSize = DataSize;
    for(int i = 0; i < DataSize; i++){
        NewData[i] = InputData[i];
    }
    this->Data = NewData;
}
void setData(int InputData[], size_t InputSize){
    int* NewData = new int[DataSize];
    this->DataSize = InputSize;

    for(int i = 0; i < InputSize; i++){
        NewData[i] = InputData[i];
    }
    
    this->Data = NewData;
}
int* getData(){
    if(Data == NULL){return NULL;}
    int* SendData = new int[DataSize];
    for(int i = 0; i < DataSize; i++){
        SendData[i] = this->Data[i];
    }
    return SendData;
}
size_t getDataSize(){
    return this->DataSize;
}
// Prints the data array.
void printDataArray(){
    size_t index = 0;
    size_t lastElement = DataSize-1;
    cout<<"\n[";
    while(index < DataSize){
        cout<<this->Data[index];
        if(index != lastElement){
            cout<<","<<setw(2);
        }
        index++;
    }
    cout<<setw(1)<<"]\n";
}
// Prints any given array.
void printArr(int A[], int size){
    size_t index = 0;
    size_t lastElement = size - 1;
    cout<<"[ ";
    while(index < size){
        cout<<A[index];
        if(index != lastElement){
            cout<<","<<setw(2);
        }
        index++;
    }
    cout<<" ]";
}
bool validData(){
    return (Data != NULL && DataSize > 1);
}
int* RandomArray(size_t size, int LeftBound, int RightBound){
    srand(time(NULL));
    // Make sure that the size value isn't a negative number because it is an invalid index. Make sure that the right bound is greater than the left bound.
        if(size <= 1 || RightBound < LeftBound){
            cout<<"\nINCORRECT BOUNDS!\n";
            return NULL;
        }
        // NewRandom: Array used to store the random values generated.
        int* NewRandom = new int[size];
        // Index: used to add the next random value chosen.
        int Index = 0;
        // RandomNumber: Temp variable used to store the random value generated.
        int RandomNumber = 0;
        // While-loop that generates random values that fills the entire RandomArray.
        while(Index < size){
            RandomNumber = rand() % RightBound + LeftBound;
            NewRandom[Index] = RandomNumber;
            Index+=1;
        }
        return NewRandom;
}

};
#endif
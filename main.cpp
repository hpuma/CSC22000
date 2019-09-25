#include <iostream>
#include<cmath> 
#include "InsertionSort.cpp"
#include "Merge.cpp"
using namespace std;
int main(){
    int testArr[] = {1,4,2,5,3};
    int size = 5;
    cout<<"BEFORE:\t";
    for(int i =0; i < size; i++){
        cout<<testArr[i];
    }
    insertionSort(testArr,size);
    cout<<"\nAFTER:\t";
    for(int j = 0; j < size; j++){
        cout<<testArr[j];
    }
    return 0;
}


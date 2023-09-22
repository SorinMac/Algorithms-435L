#include <iostream> //object oriented library that allows input and output using streams

using namespace std;

//takes in a array uses selection sort to sort it
string* selectionSort(string selectionSortsArray[666], int size){
    int arrayLength = size;

    for(int i = 0; i < arrayLength - 2; i++){
        int smallestNum = i;
        for(int k = i + 1; k < arrayLength - 1; k++){
            if (selectionSortsArray[k] < selectionSortsArray[i]){
                string temp = selectionSortsArray[i];
                //cout << selectionSortsArray[i] << "\n";
                //cout << selectionSortsArray[k] << "\n";
                selectionSortsArray[i] = selectionSortsArray[k];
                selectionSortsArray[i] = temp;

            }
        }
    }



    return selectionSortsArray;

    //seems to be doing to much switch and not actually trying to find the smallest one and then swap

};

//takes in a array uses insert sort to sort it
void insertSort(string insertSortArray[]){

};

//takes in a array uses merge sort to sort it
void mergeSort(string mergeSortArray[]){

};

//takes in a array uses quick sort to sort it
void quickSort(string quickSortArray[]){

};
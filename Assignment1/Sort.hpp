#include <iostream> //object oriented library that allows input and output using streams

using namespace std;

//takes in a array uses selection sort to sort it
void selectionSort(string* selectionSortsArray, int size){

    int numOfComp = 0;

    //has the array size
    int arrayLength = size;

    //goes through the array from start to the second to last one
    //if there is one thing left than it is sorted
    for(int i = 0; i < arrayLength - 2; i++){

        //starts by saying the smallest thing is what ever is in the i'th place
        int smallestNum = i;

        //will start making comparisons for everything after the i'th place
        for(int k = i + 1; k < arrayLength; k++){

            numOfComp++;

            //if smaller givea k to the smallestNum to variable 
            if (selectionSortsArray[k] < selectionSortsArray[smallestNum]){
                smallestNum = k;
            }
        }

        if(smallestNum != i){
            //performs the swap
            string temp = selectionSortsArray[i];
            selectionSortsArray[i] = selectionSortsArray[smallestNum];
            selectionSortsArray[smallestNum] = temp;
        }
    }

    cout << "\n" << "Selection Sort's number of comparisons is: " << numOfComp << "\n";

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
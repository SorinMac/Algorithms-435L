#include <iostream> //object oriented library that allows input and output using streams

using namespace std;

int Partition(string* pivotArray, int start, int end){
    //create the pivot value at what is at the middle of the parted array
    string pivotValue = pivotArray[end];

    //to keep track of what place you are at
    int place = start;

    //goes from the start of the sub array to the end
    for(int i  = start; i < end; i++){


        //checks to see if the ith value is less than the end
        if(pivotArray[i] < pivotValue){

            //if so swap and make place move over
            swap(pivotArray[place], pivotArray[i]);
            place++;
        }
    }

    //swap the place with the end to make sure all is well
    swap(pivotArray[place], pivotArray[end]);

    //return the place you are at to become the new end for the rest
    return place;

}


//takes in a array uses quick sort to sort it
void QuickSort(string* quickSortArray, int start, int end){

    //creates the condition to make it start calling
    if(start < end){

        //creates a accurate pivotPoint (middle)
        int pivotPoint = Partition(quickSortArray, start, end);
        
        //sets up the recursion
        QuickSort(quickSortArray, start, pivotPoint-1);
        QuickSort(quickSortArray, pivotPoint+1, end);

    }
        
}
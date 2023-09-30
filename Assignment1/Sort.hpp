#include <iostream> //object oriented library that allows input and output using streams
#include <algorithm>
#include <cstdlib>

using namespace std;

int numOfComp = 0;
int paritionPlace = 0;

//takes in a array uses selection sort to sort it
void selectionSort(string* selectionSortsArray, int size){

    //counts the number of comparisons
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

            //counts the number of comparisons
            //put it here since it will have to check everything in the array at least onces
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

    //prints out the number of comparisons
    cout << "\n" << "Selection Sort's number of comparisons is: " << numOfComp << "\n";

};

//takes in a array uses insert sort to sort it
void insertSort(string* insertSortArray, int size){

    //counts the number of comparisons
    int numOfComp = 0;

    //does not start at one since a iteam with one thing in it is sorted
    for(int i = 1; i < size; i++){

        //take the string at that spot in the array and uses that to check the rest
        string comparisonValue = insertSortArray[i];
        int k = i - 1;

        //goes through until the value at k is less than comparison value
        while(k >= 0 &&  insertSortArray[k] > comparisonValue){
            //swap pt.1
            insertSortArray[k + 1] = insertSortArray[k];
            k = k - 1;
            //the while loop will always be entered if the num is greater than 0 or equal to zero or the k'th value is smaller than comparison
            //so that means that something was checked so but the value here
            numOfComp++;
        }
        //swap pt.2
        insertSortArray[k + 1] = comparisonValue;
    }

    //prints out the number of comparisons
    cout << "\n" << "Insert Sort's number of comparisons is: " << numOfComp << "\n";

    numOfComp++;

};

//does the mergeing back at the end

//not sure if it is swapping correctly or if its just randomly swappinf things to the right side's
void Merge(string* MergedArray, int start, int end, int middle) {

    //creats a left side and a right side
    int left = start;
    int right = middle+1;

    //temp string arrays to handle the storing of the left and the right value
    string* tempLeftSide = new string[left];
    string* tempRightSide = new string[right];

    //comparison to tell what is left and right
    for(int i = start; i < end; i++){

        numOfComp++;

        //checks if the right is lesser than end
        if(right < end){

            //if so moves it to the left
            tempLeftSide[i] = MergedArray[left];
            left++;

        //checks if the left is greater than middle
        } else if (left > middle){

            //moves it to the right
            tempRightSide[i] = MergedArray[right];
            right++;

        //checks if the value of left is lesser than right
        } else if (MergedArray[left] < MergedArray[right]){

            //moves it to the left side
            tempLeftSide[i] = MergedArray[left];
            left++;
        
        //else moves it to the right
        }else{
            tempRightSide[i] = MergedArray[right];
            right++;
        }
    }  

    //sets the left side
    for (int k = left; k < middle; k++){
        MergedArray[k] = tempLeftSide[k];
    }

    //sets the right side
    for (int l = middle+1; l < end; l++){
        MergedArray[l] = tempRightSide[l];
    }

    //deletes the temp values
    delete[] tempLeftSide;
    delete[] tempRightSide;


}

//takes in a array uses merge sort to sort it
int MergeSort(string* mergeSortArray, int start, int end){

    //uses recursion to set up a sort of queue that breaks down the total array to single values
    //then when the reusion is done it brings it all back to the the total array and sorts it along the way
    if(start >= end){

        //creates a accurate middle
        int middle = (start + end) / 2;
        
        //sets up the recursion
        MergeSort(mergeSortArray, start, middle);
        MergeSort(mergeSortArray, middle+1, end);

        //when all done starts the merging back
        Merge(mergeSortArray, start, end, middle);
    }

}

int Partition(string* pivotArray, int left, int right){
   

}


//takes in a array uses quick sort to sort it
void quickSort(string* quickSortArray){
        
};
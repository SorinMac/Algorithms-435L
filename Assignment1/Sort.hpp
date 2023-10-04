#include <iostream> //object oriented library that allows input and output using streams

using namespace std;

int numOfComp = 0;
int paritionPlace = 0;
int numOfCompQuick = 0;

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
    int leftSize = middle - start + 1;
    int rightSize = end - middle;

    //temp string arrays to handle the storing of the left and the right value
    string* tempLeftSide = new string[leftSize];
    string* tempRightSide = new string[rightSize];

    //copy the data to temp arrays to manipulate for sorting (left)
    for(int i = 0; i < leftSize; i++){
        tempLeftSide[i] = MergedArray[start + i];
    }

    //copy the data to temp arrays to manipulate for sorting (right)
    for(int k = 0; k < rightSize; k++){
        tempRightSide[k] = MergedArray[middle + 1 + k];
    }

    //place holder variables to tell where you are at
    int left = 0;
    int right = 0;
    int mergePlace = start;

    //comparison to tell what is left and right
    //does it for time of place value < thand the actual size
    while(left < leftSize && right < rightSize){

        numOfComp++;

        //if the left is lessthan or equal to the right but is on the left side
        if(tempLeftSide[left] <= tempRightSide[right]){
            MergedArray[mergePlace] = tempLeftSide[left];
            left++;
        //else has to go on the right side
        } else{
            MergedArray[mergePlace] = tempRightSide[right];
            right++;
        }  
        //advance foward on the place you are checking
        mergePlace++;
    }

    //copy the rest of the left values over
    while(left < leftSize){
        MergedArray[mergePlace] = tempLeftSide[left];
        left++;
        mergePlace++;
        numOfComp++;
    }

    //copy the rest of the right values over
    while(right < rightSize){
        MergedArray[mergePlace] = tempRightSide[right];
        right++;
        mergePlace++;
        numOfComp++;
    }

    //deletes the temp values
    delete[] tempLeftSide;
    delete[] tempRightSide;
}


//takes in a array uses merge sort to sort it
int MergeSort(string* mergeSortArray, int start, int end){

    //uses recursion to set up a sort of queue that breaks down the total array to single values
    //then when the reusion is done it brings it all back to the the total array and sorts it along the way
    if(start < end){

        //creates a accurate middle
        int middle = start + (end - start) / 2;
        
        //sets up the recursion
        MergeSort(mergeSortArray, start, middle);
        MergeSort(mergeSortArray, middle+1, end);

        //when all done starts the merging back
        Merge(mergeSortArray, start, end, middle);

    }

    return numOfComp;

}

int Partition(string* pivotArray, int start, int end){
    //create the pivot value at what is at the middle of the parted array
    string pivotValue = pivotArray[end];

    //to keep track of what place you are at
    int place = start;

    //goes from the start of the sub array to the end
    for(int i  = start; i < end; i++){

        //gives the num of comparisons
        numOfCompQuick++;

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
int QuickSort(string* quickSortArray, int start, int end){

    //creates the condition to make it start calling
    if(start < end){

        //creates a accurate pivotPoint (middle)
        int pivotPoint = Partition(quickSortArray, start, end);
        
        //sets up the recursion
        QuickSort(quickSortArray, start, pivotPoint-1);
        QuickSort(quickSortArray, pivotPoint+1, end);

    }

    //for comparisons
    return numOfCompQuick;
        
}
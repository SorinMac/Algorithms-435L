#include <iostream> //object oriented library that allows input and output using streams

using namespace std;

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

};

//sudo code start have to have a middle, left and right -> merge does that all good (now to actual use it)

//does the mergeing back at the end
void Merge(string* MergedArray, int left, int middle, int right) {

    //determing the left and the right side from the mid point
    int leftToMid = middle - left + 1;
    int rightToMid = right - middle;

    //temp arrays for the left and right side
    string* tempLeftSide = new string[leftToMid];
    string* tempRightSide = new string[rightToMid];

    //assign the temp array the values from the 0th to the leftToMid point
    for(int i = 0; i < leftToMid; i++){
        tempLeftSide[i] = MergedArray[left + i];
    }

    //assign the temp array to the values from the mid to the end
    //why we have to add the k to the middle as well so that we move along to the end 
    //middle is there also for the addition to make is so we start at the middle
    for(int k = 0; k < rightToMid; k++){
        tempRightSide[k] = MergedArray[middle + 1 + k];
    }

    //some defined variable to be used for keeping track of where we are
    int leftSide = 0;
    int rigthSide = 0;
    int start = left;

    //goes for the whole time unitl the check stuff is bigger than the left to mid value and the right side is at the end or bigger than right to mid
    while(leftSide < leftToMid && rigthSide < rightToMid){

        //if the left is smaller than right swap
        if(tempLeftSide[leftSide] <= tempRightSide[rigthSide]){

            //swap by making the actuall array switch with the value of the temp left side
            MergedArray[start] = tempLeftSide[leftSide];
            //then incroment to keep track
            leftSide++;

        //if the left is bigger than the right swap other way
        } else if(tempLeftSide[leftSide] >= tempRightSide[rigthSide]){

            //swap by making the actuall array switch with the value of the temp right side
            MergedArray[start] = tempRightSide[rigthSide];
            //the incroment to keep track
            rigthSide++;

        }
        start++;
    }

    //makes sure the rest is correctly copied left side
    while(leftSide < leftToMid){
        MergedArray[start] = tempLeftSide[leftSide];
        leftSide++;
        start++;
    }

    //makes sure the rest is correctly copied right side
    while(rigthSide < rightToMid){
        MergedArray[start] = tempRightSide[rigthSide];
        rigthSide++;
        start++;
    }
    
    //deletes the temp arrays that where made
    delete[] tempLeftSide;
    delete[] tempRightSide;

}

//takes in a array uses merge sort to sort it
//this should be all good to give a accurate left right and mid if there is a even or a odd size value
void MergeSort(string* mergeSortArray, int left, int right){
    
    //uses recursion to set up a sort of queue that breaks down the total array to single values
    //then when the reusion is done it brings it all back to the the total array and sorts it along the way
    if(left < right){
        //creates a accurate middle
        int middle = left + (right - left) / 2;
        
        //sets up the recursion
        MergeSort(mergeSortArray, left, middle);
        MergeSort(mergeSortArray, middle + 1, right);

        //when all done starts the merging back
        Merge(mergeSortArray, left, middle, right);
    }

}

//takes in a array uses quick sort to sort it
void quickSort(string quickSortArray[]){

};
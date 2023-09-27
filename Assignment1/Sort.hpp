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
void Merge(string* MergedArray, int left, int middle, int right){

    int start = right + 1;
    int i = 1;

    string* tempArray = new string[right];

    for(int k = 0; i < right-1; k++){
        if (start > right){
            tempArray[k] = MergedArray[i];
            i++;
        }else if (i > right){
            tempArray[k] = MergedArray[right];
            right++;
        }else if (MergedArray[i] < MergedArray[right]){
            tempArray[k] = MergedArray[i];
            i++;
        }else{
            tempArray[k] = MergedArray[right];
            right++;
        }
    }

    for(int j = 0; j < right; j++){
       MergedArray[j] = tempArray[j];
    }
}

//takes in a array uses merge sort to sort it
//this should be all good to give a accurate left right and mid if there is a even or a odd size value
void MergeSort(string* mergeSortArray, int left, int right){
    if (left < right) {
        int mid = left + (right - left) / 2;
        MergeSort(mergeSortArray, left, mid);
        MergeSort(mergeSortArray, mid + 1, right);
        Merge(mergeSortArray, left, mid, right);
    }
}

//takes in a array uses quick sort to sort it
void quickSort(string quickSortArray[]){

};
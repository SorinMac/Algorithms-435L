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

};

//fix num of comp

//does the mergeing back at the end
void Merge(string* MergedArray, int left, int middle, int right) {

    //counts the number of comparisons
    numOfComp = 0;

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
        numOfComp++;
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
int MergeSort(string* mergeSortArray, int left, int right){
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

    return numOfComp;

}

int Partition(string* pivotArray, int pivot, int size){
    //i think this works have not been able to test but seem to work

    //goes to the end of the sub array
    swap(pivotArray[pivot], pivotArray[size]);
    
    //place variable to keep track of where you are
    int place = 0;

    for(int i = 0; i < size-1; i++){
        
        //will eventually be used to check the number of comparisons
        numOfComp++;
        
        //checks if smaller
        if (pivotArray[i] < pivotArray[pivot]){

            //if so move over by one
            place++;
            //swap the things
            swap(pivotArray[place], pivotArray[i]);

        }
    }

    //swap back to the start
    swap(pivotArray[size], pivotArray[place+1]);

    //returne the place that we are at to continue going on
    return place+1;

}


//takes in a array uses quick sort to sort it
void quickSort(string* quickSortArray, int size){
    if(size > 1){

        //trying to implment the whole use the three casue only two worst cases picks so third has to be the best

        /* 
            Do this by use the sort method and pick three random places
            once i find the three random places i go to see which string is in the middle and then pick that as my pivot value
            i use that pivot value as a way to "break" aport the array into its samller parts
            
            *issue since pivot gets reset to 665 every time and the arrays are being broken down that does not work like that.
             the nums are to be for the array being to small

             how do i go about making something that can handle the array sizes
        */

       //explain to him the spaghetti code that you made and what approach you where trying to take

       /*
            I was trying to account for it getting bad start pivot by implementing what you brough up in class but i am haveing some trouble with
            it.
       */


        //gives the partition place in order to go along with the ever smaller arrays
        int pivot = paritionPlace;

        //make the random truly random generates a new random seed evertime
        srand((unsigned) time(NULL));
        

        //pickes the three random things based
        int randNum1 = rand() % pivot + 0;
        int randNum2 = rand() % pivot + 0;
        int randNum3 = rand() % pivot + 0;
    
        //find the string equivalent in the array 
        string randomString1 = quickSortArray[randNum1];
        string randomString2 = quickSortArray[randNum2];
        string randomString3 = quickSortArray[randNum3];

        //makes them into a array for sorting
        string middleArray[] = {randomString1, randomString2, randomString3};
        
        //sorts it to easly find the middle
        sort(middleArray->begin() , middleArray->end());

        //gets the number for the middle so that we have a index at which to start sorting at
        for(int i = 0; i < size; i++){
            if(middleArray[1] == quickSortArray[i]){
                pivot = i;
            }
        }

        //actiavates the recursion 
        paritionPlace = Partition(quickSortArray, pivot, size);
        //ever so smaller
        quickSort(quickSortArray, pivot-1);
        quickSort(quickSortArray, pivot+1); 

    }

};
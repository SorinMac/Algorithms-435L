#include <iostream> //object oriented library that allows input and output using streams

using namespace std;


int linearSearch(string* magicIteams, string* values, int size){
    //used to check
    string key = " ";
    int linearSearchTotal = 0;

    //counts the number of comparisons
    int comparisons = 0;

    //goes through the 42 different things in the arrya
    for(int i = 0; i < 42; i++){
        //Makes the key the item in the array you are looking for
        key = values[i];
        comparisons = 0;

        //goes througt the whole array looking for the key value
        for(int k = 0; k < size; k++){
            if(key == magicIteams[k]){
                //when key is found prints out the number of comparisons 
                cout << "Number of Comparisons in linear search for the " << i+1 << " word is: " << comparisons << "\n";
                linearSearchTotal = linearSearchTotal + comparisons;
            }else{
                comparisons++;
            }
        }
    }

    return linearSearchTotal;
}

void binarySearch(string* magicIteams, string* values, int size){
    //low and high to split
    int low = 0;
    int high = 666;
    //smae values for comparisons and the key
    int comparisons = 0;
    string key = " ";

    //for loop of the 42 items in the key array
    for(int i = 0; i < 42; i++){
        key = values[i];
        comparisons = 0;
        low = 0;
        high = 666;


        //only split while the low is lesser than high so that you dont go infinite
        while (low < high){

            //finds the mid
            int mid = (low + high)/2;

            //if its found will print out the number of comparisons
            if (key == magicIteams[mid]){
                cout << "Number of Comparisons in binary search for the " << i+1 << " word is: " << comparisons << "\n";
                break;
            }else if(key < magicIteams[mid]){
                //if not high equal mid making the new high the mid (if less)
                high = mid;
                comparisons++;
            }else{
                //if it greater or a bigger value amkes the low the midd plus one
                low = mid + 1;
                comparisons++;
            }
        }
        
    }
}
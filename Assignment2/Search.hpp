#include <iostream> //object oriented library that allows input and output using streams

using namespace std;

void linearSearch(string* magicIteams, string* values, int size){
    string key = " ";
    int comparisons = 0;

    for(int i = 0; i < 42; i++){
        key = values[i];
        comparisons = 0;
        for(int k = 0; k < size; k++){
            if(key == magicIteams[k]){
                cout << "Number of Comparisons in linear search for the " << i+1 << " word is: " << comparisons << "\n";
            }else{
                comparisons++;
            }
        }
    }
}

void binarySearch(string* magicIteams, string* values, int size){
    int low = 0;
    int high = 666;
    int comparisons = 0;
    string key = " ";

    for(int i = 0; i < 42; i++){
        key = values[i];
        comparisons = 0;
        low = 0;
        high = 666;

        while (low < high){

            int mid = (low + high)/2;

            if (key == magicIteams[mid]){
                cout << "Number of Comparisons in binary search for the " << i+1 << " word is: " << comparisons << "\n";
                break;
            }else if(key < magicIteams[mid]){
                high = mid;
                comparisons++;
            }else{
                low = mid + 1;
                comparisons++;
            }
        }
        
    }
}
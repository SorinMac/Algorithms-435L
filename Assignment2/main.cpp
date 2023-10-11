//first two are librarys
#include <iostream> //object oriented library that allows input and output using streams
#include <fstream> //allows for the reading of a file in the library
#include <string> /* These three are used for the removing of a space for the strings */
#include <algorithm> /* These three are used for the removing of a space for the strings */
#include <cctype> /* These three are used for the removing of a space for the strings */
#include "singleSort.hpp"
#include "Search.hpp"
#include "hash.hpp"

using namespace std;

const int arraysize = 666;
int palanplacecheck = 1;

//main functions
int main(){
    
    cout << "\n";

    int count = 0;

    int magicIteamCount = 0;
    string magicIteam[arraysize];
    string valuesArray[42];

    //start of the file stream studd
    string readInString;

    //opens the right file
    ifstream File ("magicitems.txt");

    //checks if the file is open
    if (File.is_open()){

        //while file is open gets the line
        while (File.good()){

            getline(File, readInString);

            //add the now properly formatted line to the array
            magicIteam[magicIteamCount] = readInString;
            magicIteamCount++;

            
        }
        //closed the file at the end when all done
        File.close();
    }

    //error checking if the file is not opened
    else cout << "Unable to open file"; 

    //perfroms the sorting 
    QuickSort(magicIteam, 0, arraysize - 1);

    //finds the 42 iteams at random to go find
    for(int i = 0; i < 42; i++){
        int randNum = rand() % 665 + 0;
        valuesArray[i] = magicIteam[randNum];
    }

    //does a linear search
    linearSearch(magicIteam, valuesArray, arraysize);

    //does a binary search
    binarySearch(magicIteam, valuesArray, arraysize);

    HashTable(magicIteam);

    

}


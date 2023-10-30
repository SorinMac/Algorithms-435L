//first two are librarys
#include <iostream> //object oriented library that allows input and output using streams
#include <fstream> //allows for the reading of a file in the library
#include <string> /* These three are used for the removing of a space for the strings */
#include <algorithm> /* These three are used for the removing of a space for the strings */
#include <cctype> /* These three are used for the removing of a space for the strings */
#include <iomanip> //used to set the amount of accuracy for the decmial points
#include "BST.hpp"

using namespace std;

const int arraysize = 666;
const int BSTsize = 42;
int palanplacecheck = 1;

//main functions
int main(){
    
    cout << "\n";

    int count = 0;

    int magicIteamCount = 0;
    string magicIteam[arraysize];

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

    BST* root;
    root = new BST;

    BST* temp;
    temp = new BST;

    for(int i = 0; i < arraysize; i++){
        string insertPath = BSTTreeInsert(root , magicIteam[i]);
        cout << "This is the path of " + magicIteam[i] + " is " + insertPath + "." << "\n";
    }

    cout << "\n";

    count = 0;

    int BSTcount = 0;
    string BSTitem[BSTsize];

    //start of the file stream studd
    readInString;

    //opens the right file
    ifstream BST ("magicitems-find-in-bst.txt");

    //checks if the file is open
    if (BST.is_open()){

        //while file is open gets the line
        while (BST.good()){

            getline(BST, readInString);

            //add the now properly formatted line to the array
            BSTitem[BSTcount] = readInString;
            BSTcount++;

            
        }
        //closed the file at the end when all done
        BST.close();
    }

    //error checking if the file is not opened
    else cout << "Unable to open file"; 

    for(int i = 0; i < BSTcount; i++){
        temp = BSTSearch(root, BSTitem[i]);
        cout << temp->data;
    }

}


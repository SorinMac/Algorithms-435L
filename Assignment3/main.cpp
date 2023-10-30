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

    //used to creat the root of the tree
    BST* root;
    root = new BST;

    //goes through the whole array of magic items to see where they will be inserted into the binary tree
    for(int i = 0; i < arraysize; i++){
        //this string will output the path taken to where the magicitem was placed
        //it gets passed the tree's root to start and the item it is adding
        string insertPath = BSTTreeInsert(root , magicIteam[i]);
        cout << "This is the path of " + magicIteam[i] + " is " + insertPath + "." << "\n";
    }

    //to split the two sections up
    cout << "\n";

    count = 0;

    //makes a new array to be written too for the stuff that will looked for in the BinaryTree
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

    //call the BSTSearch function to search for the 42 items that where inputed from the magicitems-find-in-bst.txt file
    for(int i = 0; i < BSTcount; i++){
        BSTSearch(root, BSTitem[i]);
    }

}


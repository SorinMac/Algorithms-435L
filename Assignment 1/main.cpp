//first two are librarys
#include <iostream> //object oriented library that allows input and output using streams
#include <fstream> //allows for the reading of a file in the library
#include "Functions1.hpp" //all the functions that will be used to make the node, stack, queue, and the sorting

using namespace std;

const int arraysize = 666;

//main functions
int main(){

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

            for (int i = 0; i < readInString.length(); i++){
                if(int(readInString.at(i)) >= 32 && int(readInString.at(i)) <= 47){
                    readInString[i] = '_';
                }

                if(int(readInString.at(i)) >= 65 && int(readInString.at(i)) <= 90){
                    readInString[i] = char(int(readInString.at(i) + 32));
                }
            }

            magicIteam[magicIteamCount] = readInString;
            magicIteamCount++;

            cout << readInString << endl;
            
        }
        //closed the file at the end when all done
        File.close();
    }

    //error checking if the file is not opened
    else cout << "Unable to open file"; 

}


//first two are librarys
#include <iostream> //object oriented library that allows input and output using streams
#include <fstream> //allows for the reading of a file in the library
#include "Functions1.hpp" //all the functions that will be used to make the node, stack, queue, and the sorting

using namespace std;

//main functions
int main(){

    //catch error if fstream is not able to read the file
    cerr << "Unable to open the file!";
    exit(1);

    string readInString;
    ifstream File;
    File.open("C:\\Users\\sorin\\OneDrive\\Documents\\GitHub\\Algorithms-435L\\Assignment1\\magicitems.txt");

    while (File >> readInString){
        cout << readInString;
    }


}


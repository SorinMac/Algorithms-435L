//first two are librarys
#include <iostream> //object oriented library that allows input and output using streams
#include <fstream> //allows for the reading of a file in the library
#include <string> /* These three are used for the removing of a space for the strings */
#include <algorithm> /* These three are used for the removing of a space for the strings */
#include <cctype> /* These three are used for the removing of a space for the strings */
#include <iomanip> //used to set the amount of accuracy for the decmial points
#include <string>
#include <vector>
#include <sstream>
#include "BST.hpp"
#include "Matrix.hpp"
#include "AdjacencyList.hpp"
#include "LinkedObjects.hpp"

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

    cout << "\n";

    InOrderPrint(root);

    //start of the graph

    //makes a new array to be written too for the stuff that will looked for in the BinaryTree
    vector<string> GraphVector;

    //start of the file stream studd
    readInString;

    //opens the right file
    ifstream Graph ("graphs1.txt");

    //checks if the file is open
    if (Graph.is_open()){

        //while file is open gets the line
        while (Graph.good()){

            getline(Graph, readInString);

            //add the now properly formatted line to the array
            GraphVector.push_back(readInString);

            
        }
        //closed the file at the end when all done
        Graph.close();
    }

    //error checking if the file is not opened
    else cout << "Unable to open file"; 

    //values that will be used to check things
    int vertexs = 0;
    string start = "0";
    string end = "0";
    vector<int> StartList;
    vector<int> EndList;
    int Gcount = 0;

    //will go throught the vector that contains all the lines in the graph1.txt file
    for(string i : GraphVector){
        //check if it does not see the comment line
        //if so start processing
        if(i.find("--") == std::string::npos){
            
            //if it sees new (for new graph) or the end of the vector then reset everything
            if(i.find("new") != std::string::npos || i == GraphVector.back()){

                //print out as Matrix
                MatrixGraph(vertexs, StartList, EndList);

                //print out as Adjacency list
                AdjacencyList(vertexs, StartList, EndList, Gcount);

                //print out as linked objects
                LinkedObjs(vertexs, StartList, EndList, Gcount);

                //resets all data back to nothing to get the data of the next graph
                vertexs = 0;
                StartList.clear();
                EndList.clear();

            }else if(i.find("vertex") != std::string::npos){

                //if you find vertex in i that means a new vertex so add to the total amount
                vertexs++;

            }else if(i.find("edge") != std::string::npos){

                /*for(int k = 0; k < i.length(); k++){
                    if(i[k] == '-'){
                        //this can not handle integers of larger than 1
                        StartList.push_back(int(i[k-2])-48);
                        EndList.push_back(int(i[k+2])-48);
                    }
                }*/

                //if you find the edge then start pulling the start and end value for the edge to find out what two vertexes are connected to each other4

                //this will be used with the tokens to read and extract tokens out of the string i
                std::istringstream iss(i);
                std::string token;
                
                //will be used to switch between vectors
                bool addToVectorA = true;

                //checks the tokens if they are equal will skip them
                while (iss >> token) {
                    if (token == "add" || token == "edge" || token == "-") {
                        continue;
                    }

                    int num;

                    //this will check if the token is a int and if so add it to the start list first then the second one to the end list
                    if (std::istringstream(token) >> num) {
                        if (addToVectorA) {
                            StartList.push_back(num);
                        } else {
                            EndList.push_back(num);
                        }

                        // Toggle between vectors
                        addToVectorA = !addToVectorA;

                        //if the graph starts at zero this value will be used to tell the out functions to start at 0 instead of 1
                        if(num == 0){
                            Gcount = 5;
                        }
                    }
                }
            }
        }
    }
}


//first two are librarys
#include <iostream> //object oriented library that allows input and output using streams
#include <fstream> //allows for the reading of a file in the library
#include <string> /* These three are used for the removing of a space for the strings */
#include <algorithm>
#include <cctype>
#include "Functions1.hpp" //all the functions that will be used to make the node, stack, queue, and the sorting
#include "shuffle.hpp" //shuffle functions 
#include "Sort.hpp" // sorting algorithms

using namespace std;

const int arraysize = 666;

//main functions
int main(){
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

            //this for loop will make is so that all spaces and special characters are all one specific symbol to check for
            for (int i = 0; i < readInString.length(); i++){    
                //make all letters lowercase
                if(int(readInString.at(i)) >= 65 && int(readInString.at(i)) <= 90){
                    readInString[i] = char(int(readInString.at(i) + 32));
                }
            }

            //uses three of the includes (string, algorithms, cctype) to remove the space
             readInString.erase(std::remove_if(readInString.begin(), readInString.end(), ::isspace),
             readInString.end());


            //add the now properly formatted line to the array
            magicIteam[magicIteamCount] = readInString;
            magicIteamCount++;

            
        }
        //closed the file at the end when all done
        File.close();
    }

    //error checking if the file is not opened
    else cout << "Unable to open file"; 

    //creates the Node start for the stack
    Node* head;
    head = new Node;

    //goes through every word
    for (int i = 0; i<666; i++){

        //creates the queue
        Queue queue;

        //gets the word in the section of the array that is i
        string PalanCheck = "";
        PalanCheck = magicIteam[i];

        //for the length of the word pushes to stack and enqueues the queue
        for(int k = 0; k < PalanCheck.length(); k++){
            push(&head, PalanCheck[k]);
            queue.EnQueue(PalanCheck[k]);
        }

        //pops the char out of the stack and dequeus it at the same time
        for (int j = 0; j < PalanCheck.length(); j++){
            char popChar =  pop(*&head);
            char queueChar =  queue.DeQueue();

            //checks if they match
            if (popChar != queueChar){

                //count is used to make sure the programm checks the whole word (rest cause some words have a few that match)
                count = 0;
                break;

            } else if (popChar = queueChar){

                //if the two do match adds to count
                count++;

                //if the count equal the lenght of the string (did the whole string so print it out)
                if(count == PalanCheck.length()){
                    cout << PalanCheck << "\n";
                    count = 0;
                }

            }

        }

    }

    //the now storted array for strings
    selectionSort(magicIteam, arraysize);

    shuffle(magicIteam);

    /*for (int i = 0; i < 666; i++){
        cout << magicIteam[i] << "\n";
    }*/


    

}


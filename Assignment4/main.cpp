//first two are librarys
#include <iostream> //object oriented library that allows input and output using streams
#include <fstream> //allows for the reading of a file in the library
#include <string> /* These three are used for the removing of a space for the strings */
#include <algorithm> /* These three are used for the removing of a space for the strings */
#include <cctype> /* These three are used for the removing of a space for the strings */
#include <iomanip> //used to set the amount of accuracy for the decmial points
#include <vector>
#include <sstream>
#include "FractionalGreedy.hpp"

using namespace std;


//main functions
int main(){
    
    cout << "\n";

    vector<string> SpiceHeist;

    //start of the file stream studd
    string readInString;

    //opens the right file
    ifstream File ("spice.txt");

    //checks if the file is open
    if (File.is_open()){

        //while file is open gets the line
        while (File.good()){

            getline(File, readInString);

            //add the now properly formatted line to the array
            SpiceHeist.push_back(readInString);

            
        }
        //closed the file at the end when all done
        File.close();
    }

    //error checking if the file is not opened
    else cout << "Unable to open file"; 

    //variables that will be used for processing
    string SpiceName;
    float SpicePrice;
    int SpiceQty;
    int count = 0;
    int knapsackSize;
    
    //will hold the knapsacks value
    vector<int> kanpsacks;

    //start of the long amount of logic that is used to correctly process the file
    for(string i: SpiceHeist){

        //checks for comments
        if(i.find("--") == std::string::npos){
            //the word spice it found then we know that there is a new spice
            if(i.find("spice") != std::string::npos){
                std::istringstream iss(i);
                std::string token;

                while (iss >> token) {
                    //then we skip over all the words and symbols so that we are left with just the values
                    if (token == "spice" || token == "name" || token == "=" || token == "total_price" || token == "qty") {
                        continue;
                    }
                    //this only works is the values stay in the same format

                    //the first thing is always the spice name so we find the token with the semi colon
                    if(token.find(";") != std::string::npos && count == 0){
                        //make that token the SpiceName
                        SpiceName = token;
                        //trim the semi colon off
                        SpiceName.erase(remove(SpiceName.begin(), SpiceName.end(), ';'), SpiceName.end());
                        //make the count one more so that we can move on to the next thing to add
                        count++;
                        continue;
                    }

                    //the second thing is always the SpicePrice
                    if(token.find(";") != std::string::npos && count == 1){
                        //since this will be a float we have to get ride of the semi colon first before converting from string to float
                        token.erase(remove(token.begin(), token.end(), ';'), token.end());
                        //convert
                        SpicePrice = stof(token);
                        //move the count along to check for the next thing
                        count++;
                        continue;
                    }

                    //the third this will always be the SpiceQTY
                    if(token.find(";") != std::string::npos && count == 2){
                        //since this wil be a int we have the trim the semi colon off first before converstion
                        token.erase(remove(token.begin(), token.end(), ';'), token.end());
                        //convertion
                        SpiceQty = stoi(token);
                        //set the count back to look for the SpiceName since we have all the data for the spice after this
                        count = 0;
                        continue;
                    }
            
                }

                //then pass that data to Spice function in "FractionalGreedy.hpp" to create the spice
                Spice(SpiceName, SpicePrice, SpiceQty);

            //if we see a knapsack word do other actions
            }else if(i.find("knapsack") != std::string::npos){
                std::istringstream iss(i);
                std::string token;

                //much less to skip over
                while (iss >> token) {
                    if (token == "knapsack" || token == "capacity" || token == "=") {
                        continue;
                    }

                    //same logic as before once the token have a semicolon at it thats the data
                    if(token.find(";") != std::string::npos){   
                        //trim the semi colon off since the knap sack size will be a int
                        token.erase(remove(token.begin(), token.end(), ';'), token.end());
                        //convert
                        knapsackSize = stoi(token);
                        //add to the vector that will hold all the knap sack sizes
                        kanpsacks.push_back(knapsackSize);
                    }
                }
                    
            }
        }
    }

    //this wil go through all the knap sack sizes and send them over to the FractionGreedy algorithm in "FractionalGreedy.hpp
    for(int i : kanpsacks){
        FractionalGreedy(i);
    }



    
}


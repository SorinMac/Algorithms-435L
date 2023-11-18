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

    string SpiceName;
    float SpicePrice;
    int SpiceQty;
    int count = 0;
    int knapsackSize;
    
    vector<int> kanpsacks;

    for(string i: SpiceHeist){
        if(i.find("--") == std::string::npos){
            if(i.find("spice") != std::string::npos){
                std::istringstream iss(i);
                std::string token;

                while (iss >> token) {
                    if (token == "spice" || token == "name" || token == "=" || token == "total_price" || token == "qty") {
                        continue;
                    }

                    if(token.find(";") != std::string::npos && count == 0){
                        SpiceName = token;
                        SpiceName.erase(remove(SpiceName.begin(), SpiceName.end(), ';'), SpiceName.end());
                        count++;
                        continue;
                    }

                    if(token.find(";") != std::string::npos && count == 1){
                        token.erase(remove(token.begin(), token.end(), ';'), token.end());
                        SpicePrice = stof(token);
                        count++;
                        continue;
                    }

                    if(token.find(";") != std::string::npos && count == 2){
                        token.erase(remove(token.begin(), token.end(), ';'), token.end());
                        SpiceQty = stoi(token);
                        count = 0;
                        continue;
                    }
            
                }

                Spice(SpiceName, SpicePrice, SpiceQty);

            }else if(i.find("knapsack") != std::string::npos){
                std::istringstream iss(i);
                std::string token;

                while (iss >> token) {
                    if (token == "knapsack" || token == "capacity" || token == "=") {
                        continue;
                    }

                    if(token.find(";") != std::string::npos){
                        token.erase(remove(token.begin(), token.end(), ';'), token.end());
                        knapsackSize = stoi(token);
                        kanpsacks.push_back(knapsackSize);
                    }
                }
                    
            }
        }
    }



    
}


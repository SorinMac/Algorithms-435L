//first two are librarys
#include <iostream> //object oriented library that allows input and output using streams
#include <fstream> //allows for the reading of a file in the library
#include <string> /* These three are used for the removing of a space for the strings */
#include <algorithm> /* These three are used for the removing of a space for the strings */
#include <cctype> /* These three are used for the removing of a space for the strings */
#include <iomanip> //used to set the amount of accuracy for the decmial points
#include <vector>
#include <sstream>

using namespace std;

struct spice{
    string name;
    float price;
    int QTY;
    float unitPrice;
};

vector<spice*> SpiceHolder;

void Spice(string SpiceName, float SpicePrice, int SpiceQTY){

    spice* Spice = new spice;
    Spice->name = SpiceName;
    Spice->price = SpicePrice;
    Spice->QTY = SpiceQTY;
    Spice->unitPrice = SpicePrice/SpiceQTY;

    SpiceHolder.push_back(Spice);
    
}


void FractionalGreedy(int size){
    int NapSize = 0;
    int condition = 0;
    float total = 0;
    spice* GUnitPrice;
    GUnitPrice->unitPrice = 0;

    NapSize = size;

    for(spice* j : SpiceHolder){

        if(j->unitPrice > GUnitPrice->unitPrice){

            GUnitPrice = j;

        }
    }

    //not getting to the right function to do the work look at geeks for geeks for that answer
    
    if(GUnitPrice->QTY < NapSize){

        //will handle whole amounts

        NapSize = NapSize - GUnitPrice->QTY;
        total = GUnitPrice->price;

    }else if(GUnitPrice->QTY > NapSize){

        //will handle fractional amounts

        cout << "Knapsack of capacity " << std::to_string(NapSize) << " is worth " << std::to_string(GUnitPrice->unitPrice * NapSize) << " quatloos and contains " << std::to_string(NapSize) << " scoop of " << GUnitPrice->name << "." << "\n";
        
    }
}



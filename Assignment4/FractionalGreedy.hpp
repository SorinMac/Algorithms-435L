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
};

vector<spice*> SpiceHolder;

void Spice(string SpiceName, float SpicePrice, int SpiceQTY){

    spice* Spice = new spice;
    Spice->name = SpiceName;
    Spice->price = SpicePrice;
    Spice->QTY = SpiceQTY;

    SpiceHolder.push_back(Spice);
    
}


void FractionalGreedy(){

}


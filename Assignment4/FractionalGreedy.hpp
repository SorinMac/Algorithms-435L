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


void FractionalGreedy(vector<int> knapsacks){
    int sackSize = 0;
    int condition = 1;

    for(int i : knapsacks){
        sackSize = i;

        for(spice* i : SpiceHolder){

            if(i->QTY > sackSize){
                condition = 1;
            }
        }

        if(condition == 1){

            spice* GUnitPrice;

            for(spice* j : SpiceHolder){

                if(j->unitPrice > GUnitPrice->unitPrice){

                    GUnitPrice = j;

                }
            }

            if(GUnitPrice->QTY > sackSize){
                cout << "Knapsack of capacity " << std::to_string(sackSize) << " is worth " << std::to_string(GUnitPrice->unitPrice * sackSize) << " quatloos and contains " << std::to_string(sackSize) << " scoop of " << GUnitPrice->name << "." << "\n";
            }
        }else{
            
        }


    }

}


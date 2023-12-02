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

//this is the spice class that i made 
struct spice{
    //name of the spice
    string name;
    //the price as a float if needed
    float price;
    //the QTy
    int QTY;
    //unitPrice to be caculated
    float unitPrice;
    //processed (taken from Assignment3) so that we do not indefinetly check the same spice
    bool Processed;
};

//this will hold all the different spice's
vector<spice*> SpiceHolder;

void Spice(string SpiceName, float SpicePrice, int SpiceQTY){

    //creates a new spice 
    spice* Spice = new spice;

    //uses data to populate the parts of the class
    Spice->name = SpiceName;
    Spice->price = SpicePrice;
    Spice->QTY = SpiceQTY;
    Spice->unitPrice = SpicePrice/SpiceQTY;
    Spice->Processed = false;

    //then adds the pointer to the spice to the SpiceHolder vector so that i can access to them all
    SpiceHolder.push_back(Spice);
    
}


void FractionalGreedy(int size){
    //is given the size of the knap sack
    int NapSize = size;
    //consant for the print out
    const int trueSize =  size;
    //to keep hold of the total
    float total = 0;

    vector<string> SpiceName;
    vector<int> SpiceAmount;

    //will go until the Knap Sack is 0 in size
    while(NapSize > 0){
        //create a new pointer to find the greatest unit price
        spice* GUnitPrice = nullptr;

        //goes through all the spices that are in the spice holder
        for(spice* j : SpiceHolder){
            //if there is a new greatest unit price
            if(GUnitPrice == nullptr || j->unitPrice > GUnitPrice->unitPrice && j->Processed == false){
                //make the GUnitPrice pointer equal to it
                GUnitPrice = j;
            }
        }

        if (GUnitPrice->Processed == true) {
            //no more spices left
            break;
        }

        //will set the spice of the greatest one to true so that if it is used up in full we do not check it
        //of if its a fraction then we know we are done
        GUnitPrice->Processed = true;

        if(GUnitPrice->QTY <= NapSize){

            //will handle whole amounts

            NapSize = NapSize - GUnitPrice->QTY;
            total = total + GUnitPrice->price;

            //will add the amounts to a vector so that we have access to all the spices that made up the greatest combination (whole amounts)
            SpiceName.push_back(GUnitPrice->name);
            SpiceAmount.push_back(GUnitPrice->QTY);


        }else if(GUnitPrice->QTY > NapSize || NapSize == 0){

            //will handle fractional amounts

            total = total + GUnitPrice->unitPrice * NapSize;

            //will add the amounts to a vector so that we have access to all the spices that made up the greatest combination (fractional amounts)
            SpiceName.push_back(GUnitPrice->name);
            SpiceAmount.push_back(GUnitPrice->QTY - NapSize);

            break;
            
        }

    }


    //will handle the out put onto terminal
    cout << "Knapsack of capacity " << std::to_string(trueSize) << " is worth " << setprecision(3) << total << " quatloos and contains ";
    
    //goes through the vecotrs that hold the data and prints out everything in it
    for(int i = 0; i < SpiceName.size(); i++){
        cout << SpiceAmount[i] << " scoops of " << SpiceName[i] << ". ";
    }

    //creates a new line for the next input
    cout << "\n";

    //resets all the spice values Prcosessed values to false so that it can be done again with a different knap sack
    for(spice* i : SpiceHolder){
        i->Processed = false;
    }
    
}



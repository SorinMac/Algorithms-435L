#include <iostream> //object oriented library that allows input and output using streams

using namespace std;

//takes in a array and shuffles it useing a random number
void shuffle(string shuffleArray[]){
    //gets a random number from 0 to 665 since array size is 666
    int randNum = rand() % 665 + 0;

    for (int i = 0; i < 666; i++){
        //does the swap of the two things
        string temp = shuffleArray[i];
        shuffleArray[i] = shuffleArray[randNum];
        shuffleArray[randNum] = temp;
    }
    




};
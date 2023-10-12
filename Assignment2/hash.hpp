#include <iostream> //object oriented library that allows input and output using streams
#include <string>


using namespace std;

struct Node{
    string data;
    Node* link;
};

int HashValue(string word){

    //const for the has table size
    const int HASH_TABLE_SIZE = 250;

    //makes everything upper case
    for(int k = 0; k < word.length(); k++){
        word.at(k) = toupper(word.at(k));
    }

    //what we are hashing
    string HashString = word;
    //the length of the word we are hashing
    int length = word.length();
    //this will become the hash
    int letterTotal = 0;

    //hash goes through till the length of the string and adds the int value (ascii) of the character to the total of the whole string
    for (int j = 0; j < length; j++) {
        char thisLetter = HashString.at(j);
        int thisValue = (int)thisLetter;
        letterTotal = letterTotal + thisValue;
    }

    //makes the value not a float in case and mod divided by the size to make sure it will be a index of the array
    int hashCode = (letterTotal * 1) % HASH_TABLE_SIZE;

    //returns the hash code
    return hashCode;

}

void HashTable(string* HashingArray){

    //creats the array of 250 things as the node data type and sets all things to nullptr
    Node* HashMap[250] = { nullptr };

    for(int k = 0; k < 666; k++){
        //finds the hash value and assign it to place
        int place = HashValue(HashingArray[k]);

        //makes a new node and assigns the data to the magicitems[k] and the link to null
        //since it will be the first thing
        Node* newNode = new Node;
        newNode->data = HashingArray[k];
        newNode->link = nullptr;

        //gets checks if place has a nullptr
        if (HashMap[place] == nullptr) {

            //then create the newNode since this will be the first one
            HashMap[place] = newNode;

        } else {

            //if not make the link the place and the head place is the newNode
            newNode->link = HashMap[place];
            HashMap[place] = newNode;
        }

    }

    

}
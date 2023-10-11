#include <iostream> //object oriented library that allows input and output using streams
#include <string>


using namespace std;

struct Node{
    string data;
    Node* link;
};

//push asks for a pointer to a pointer of the front and the key (value) that you want to add
void push(Node** front, string key) {

    //mks a new node pointer call newFront (becasue it will be use to reassign the front to the pushed value)
    Node* newFront = new Node;

    /*assigns the newFront the passed in key (the new data)
    then assigns the link to be the pointer value to the front
    then the pointer to front is equal to the newFront makeing is back at the top*/

    /* Diagram: 
        (new front) new thing -> newFront*
            (new front) new thing -> to front**
                                 front -> first one***
    */


    newFront->data = key;
    newFront->link = *front;
    *front = newFront;



}

int HashValue(string word){

    const int HASH_TABLE_SIZE = 250;


    for(int k = 0; k < word.length(); k++){
        word.at(k) = toupper(word.at(k));
    }

    string HashString = word;
    int length = word.length();
    int letterTotal = 0;

    for (int j = 0; j < length; j++) {
        char thisLetter = HashString.at(j);
        int thisValue = (int)thisLetter;
        letterTotal = letterTotal + thisValue;
    }

    int hashCode = (letterTotal * 1) % HASH_TABLE_SIZE;

    return hashCode;

}

void HashTable(string* HashingArray){
    Node* HashMap[250] = { nullptr };

    for(int k = 0; k < 666; k++){
        int place = HashValue(HashingArray[k]);

        Node* newNode = new Node;
        newNode->data = HashingArray[k];
        newNode->link = nullptr;

        if (HashMap[place] == nullptr) {
            HashMap[place] = newNode;
        } else {
            newNode->link = HashMap[place];
            HashMap[place] = newNode;
        }

    }

    

}
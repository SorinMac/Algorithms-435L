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

int HashMap(string* HashingArray, string* values){

    //creates the hash map
    Node* HashMap[250] = { nullptr };
    int hashTotal = 0;

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


    //goes through the the 42 different values and finds them 
    for(int k = 0; k < 42; k++){
        //to get the num of comparisons
        int comparisons = 0;
        //what the hash function will get it too and then that will equal the place it is on the array
        int valuePlace = HashValue(values[k]);
        //the key we are looking for
        string key = values[k];

        //will create a temp node so that we can travers the linked lists inside fo the hashmap
        Node* temp = new Node;
        temp->link = HashMap[valuePlace]->link;
        temp->data = HashMap[valuePlace]->data;


        //does this while the linked list does not equal 0x0 or the end
        while(temp != 0x0){ 
            //if it finds the end then prints out the message and adds to the total to be used later and breaks out the loop
            if(temp->data == key){
                cout << "Number of Comparisons in Hash search for the " << k+1 << " word is: " << comparisons << "\n";
                hashTotal = hashTotal + comparisons;
                break;
            }else{
                //if not add to comparison and then move along the linked list
                comparisons++;
                temp =  temp->link;
            }
        }

        //delets the temp value once done
        delete temp;
        
    }
    
    //return the total to be used to find the average
    return hashTotal;

    


}
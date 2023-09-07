//librarys that are always used in c++
#include <iostream>
using namespace std;

//This class will be the nodes that are made to make the link list
//The data type for data is char since there will characters passed to make the list
struct Node{
    char data;
    Node* link;
};

//push asks for a pointer to a pointer of the front and the key (value) that you want to add
void push(Node** front, char key) {

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

//pop the first iteam in the stack out of the stack
char pop(Node*& front) {
    //checks if the front is NULL or not
    if(front){

        //mks a temp variable
        Node* TempPop =  front;
        //gets the data
        char data =  front->data;
        //make front = to next thing
        front = front->link;

        //delets all that not used and returns the data to be used
        delete TempPop;
        return data;
    }

    /* Diagram: 

        front1 -> link* (takes the data from here)
            thing2 -> link** (makes this the new head)
                thing3 -> link***

        take the data from front and returns that and then makes the head what ever is below it
    */
}


//checks if the list is empty
bool isEmptyStack(Node*& head) {
    //value to be returned back
    bool EmptyOrNot = false;

    //mks a temp node value
    Node* temp = head;

    //assign the value of temp (head) to CheckLink
    Node* CheckLink = temp->link;

    //if null end of list (empty) if not not end of list still full
    if (CheckLink == NULL){
        EmptyOrNot = true;
    } else{
        EmptyOrNot = false;
    }

    //returns bool answer
    return EmptyOrNot;
}

struct Queue{
    Node* front;
    Node* back;

    Queue(){
        front = NULL;
        back =  NULL;
    }
};

void EnQueue(){

}

char DeQueue(){

}

//checks if the Queue is empty
bool isEmptyQueue(Node*& head) {
    //value to be returned back
    bool EmptyOrNot = false;

    //mks a temp node value
    Node* temp = head;

    //assign the value of temp (head) to CheckLink
    Node* CheckLink = temp->link;

    //if null end of list (empty) if not not end of list still full
    if (CheckLink == NULL){
        EmptyOrNot = true;
    } else{
        EmptyOrNot = false;
    }

    //returns bool answer
    return EmptyOrNot;
}



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
        Node* temp =  front;
        //gets the data
        char data =  front->data;
        //make front = to next thing
        front = front->link;

        //delets all that not used and returns the data to be used
        delete temp;
        return data;
    }

    /* Diagram: 

        front1 -> link* (takes the data from here)
            thing2 -> link** (makes this the new head)
                thing3 -> link***

        take the data from front and returns that and then makes the head what ever is below it
    */

   return '0';
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

    delete temp;

    //returns bool answer
    return EmptyOrNot;
}

struct Queue{
    //Node pointer for the front and back
    Node* front;
    Node* back;

    Queue(){
        front = NULL;
        back =  NULL;
    }

    //put the item of choice one after the last slot
    void EnQueue(char info){
        
        //creates a temp Node pointer
        Node* temp = new Node;

        //sets the data to the temp nodes data
        temp->data =  info;
            //checks if back is null
            if(back == NULL){
                front = temp;
                back = temp;
                return;
            }

            //sets the back link to temp and then back to equal temp
            back->link = temp;
            back = temp;

            delete temp;
    }

    /* Diagram: 
        head -> link
        tail -> link (new iteam)
        iteam -> link (becomes new tail) ...
    */

    char DeQueue(){
        //checks if front is null or at the top
        if (front == NULL) {
            return '0';
        }

        //creates a temp node pointer
        Node* temp = front;

        //sets the front  variable to the link of front
        front = front->link;

        //set data of char type to the temp->datas data
        char data =  temp->data;

        //delets temp since not needed anymore
        delete temp;

        //makes it all null
        if(front == NULL){
            back = NULL;
        }

        //returns the data
        return data;

    }

    /* Diagram: 
        head -> link
        tail -> link (new iteam)
        iteam -> link (becomes new tail) ...

        same thing as above but in reverse

        head -> link (takes out this item)
        item -> link (this becomes new head)
        tail -> link 

    */
};


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

    delete temp;

    //returns bool answer
    return EmptyOrNot;
}



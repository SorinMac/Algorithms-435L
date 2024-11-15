//librarys that are always used in c++
#include <iostream>
#include <vector>
#include <string>
using namespace std;


//new class for the LinkedObj
struct LinkedObj{
    string node;
    vector<int> neightbors;
    bool IsProcessed =  false;
};

struct QueueNode{
    int data;
    QueueNode* link;
};

struct Queue{
    //Node pointer for the front and back
    QueueNode* front;
    QueueNode* back;

    Queue(){
        //sets the front and back to null
        front = nullptr;
        back =  nullptr;
    }

    void EnQueue(int info) {
        //creates a new point and make the data for it the id passed (called info)
        //and the link null
        struct QueueNode * ptr;

        ptr = (struct QueueNode * ) malloc(sizeof(struct QueueNode));

        ptr->data = info;
        ptr->link = NULL;

        //if the queue has nothing make the front the new thing and the back 
        if ((front == NULL) && (back == NULL)) {
            front = back = ptr;
        } else { //else add the new data to the back
            back-> link = ptr;
            back = ptr;
        }
        
    }

    /* Diagram: 
        head -> link
        tail -> link (new iteam)
        iteam -> link (becomes new tail) ...
    */

    int DeQueue(){
        //checks if front is null or at the top
        if (front == NULL) {
            return 0;
        }

        //creates a temp node pointer
        QueueNode* temp = front;

        //sets the front  variable to the link of front
        front = front->link;

        //set data of char type to the temp->datas data
        int data =  temp->data;

        //delets temp since not needed anymore
        delete temp;

        //makes it all null
        if(front == NULL){
            back = NULL;
        }

        //returns the data
        return data;

    }

    //checks if the Queue is empty
    bool isEmptyQueue() {
        return front == nullptr;
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

void DepthFirstSearch(LinkedObj Vertecies[], int id, int count){
    //will see if the node at the array of LinkeObjs is processed
    if (Vertecies[id].IsProcessed == false) {

        //if not make true and print out
        Vertecies[id].IsProcessed = true;

        //print out if first vertex is 0
        if(count == 5){
            cout << "Visited node " << stoi(Vertecies[id].node) - 1 << endl;
        }else{ //if first vertex is 1
             cout << "Visited node " << stoi(Vertecies[id].node) << endl;
        }
        
        //then will recurivly send the neighbors to the fucntion to have the same thing happen to them
        for (int neighbor : Vertecies[id].neightbors) {
            DepthFirstSearch(Vertecies, neighbor - 1, count);
        }
    }
} 

void BreathFirstSearch(LinkedObj Vertecies[], int id, int count){

    //creates the queue
    Queue BFSQueue;

    //enques the first thing of the id of the first thing
    BFSQueue.EnQueue(id);

    //sets the processed value to true
    Vertecies[id].IsProcessed = true;

    cout << "\n";

    cout << "Breath First Search: " << "\n";

    //while the queue is not empty do these actions
    while(BFSQueue.isEmptyQueue() == false){

        //then dequeus the first item and prints it out
        int current =  BFSQueue.DeQueue();

        if(count == 5){
            cout << "Visited Node: " << stoi(Vertecies[current].node) - 1 << endl;
        }else{
            cout << "Visited Node: " << Vertecies[current].node << endl;
        }
       
        //for all the neighbors in the place
        for(int neighbor: Vertecies[current].neightbors){
            if(!Vertecies[neighbor-1].IsProcessed){
                //if they are not processed then process them (set processed to true)
                Vertecies[neighbor-1].IsProcessed = true;
                //and enqueue it
                BFSQueue.EnQueue(neighbor-1);
            }
        }
    }

}

void LinkedObjs(int vertexs, vector<int> start, vector<int> end, int count) {

    //will create a array of LinkedObj called Vertecies to store them all
    LinkedObj Vertecies[vertexs];
    int VECTOR_SIZE = 0;

    //to check howe many edges there are (for is the start has more than the end)
    if(start.size() == end.size()){
        VECTOR_SIZE = start.size();
    }else if(start.size() > end.size()){
        VECTOR_SIZE = start.size();
    }else{
        VECTOR_SIZE = end.size();
    }

    //give the name to the node value of each of the LinkedObj
    for(int i = 0; i < vertexs; i++){
        Vertecies[i].node = to_string(i+1);
    }

    //will go to Vertecies sub start the neighbors vector and push_back the end value to it
    for(int i = 0; i < VECTOR_SIZE; i++){

        //checking if given a 0 vertex
        if(start[i] == 0){
            Vertecies[start[i]].neightbors.push_back(end[i]);
            Vertecies[end[i]-1].neightbors.push_back(start[i]);
        }else if(end[i] == 0){
            Vertecies[start[i]-1].neightbors.push_back(end[i]);
            Vertecies[end[i]].neightbors.push_back(start[i]);
        }else{
            Vertecies[start[i]-1].neightbors.push_back(end[i]);
            Vertecies[end[i]-1].neightbors.push_back(start[i]);
        }
    }

    if(vertexs > 0){

        //print out if the first vertex starts at 0
        if(count == 5){
            cout << "\n";
    
            cout << "Linked Objects: " << "\n";
            
            for (int i = 0; i < vertexs; i++) {
                
                //goes to each of the Vertecies get the node and prints out
                cout << "Neighbors of Node " << stoi(Vertecies[i].node) - 1 << ": ";

                    //then prints out all of thats nodes neighbors 
                    for (int neighbor : Vertecies[i].neightbors) {
                        cout << neighbor << " ";
                    }
                cout << endl;
            }
            
            //id is the first node we want to process
            int id = 0;

            cout << "\n";

            cout << "Depth First Search: " << "\n";

            //then goes to depth first search to do that print out as well
            DepthFirstSearch(Vertecies, id, count);

            //resets values for the breath first search
            for(int i = 0; i < vertexs; i++){
                Vertecies[i].IsProcessed = false;
            }

            //then goes to breath first search to do that print out as well
            BreathFirstSearch(Vertecies, id, count);

            cout << "\n";

            cout << "Not Connected Nodes: " << "\n";
            
            //will print out all no connected values
            for(int i = 0; i < vertexs; i++){
                //if not connected they where never processed so there value would be false
                if(Vertecies[i].IsProcessed == false){
                     cout << stoi(Vertecies[i].node)-1 << " is not connect :(" << "\n";
                }
            }

        }else{
            //print out if the vertex starts a 1
            cout << "\n";
    
            cout << "Linked Objects: " << "\n";
            
            for (int i = 0; i < vertexs; i++) {
                
                //goes to each of the Vertecies get the node and prints out
                cout << "Neighbors of Node " << stoi(Vertecies[i].node) << ": ";

                    //then prints out all of thats nodes neighbors 
                    for (int neighbor : Vertecies[i].neightbors) {
                        cout << neighbor << " ";
                    }
                cout << endl;
            }

            //id is the first node we want to process
            int id = 0;

            cout << "\n";

            cout << "Depth First Search: " << "\n";

            //then goes to depth first search to do that print out as well
            DepthFirstSearch(Vertecies, id, count);

            for(int i = 0; i < vertexs; i++){
                Vertecies[i].IsProcessed = false;
            }

            //then goes to breath first search to do that print out as well
            BreathFirstSearch(Vertecies, id, count);

            cout << "\n";

            cout << "Not Connected Nodes: " << "\n";

            for(int i = 0; i < vertexs; i++){
                if(Vertecies[i].IsProcessed == false){
                     cout << stoi(Vertecies[i].node) << " is not connect :(" << "\n";
                }
            }
        }
        
    }
    
}
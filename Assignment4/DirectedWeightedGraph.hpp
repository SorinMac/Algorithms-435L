//first two are librarys
#include <iostream> //object oriented library that allows input and output using streams
#include <fstream> //allows for the reading of a file in the library
#include <string> /* These three are used for the removing of a space for the strings */
#include <algorithm> /* These three are used for the removing of a space for the strings */
#include <cctype> /* These three are used for the removing of a space for the strings */
#include <iomanip> //used to set the amount of accuracy for the decmial points
#include <vector>
#include <sstream>

//hardest thing was wrapping my head around what the relax function is compariring to make the graph RELAX

using namespace std;

//class to hold the vertex
struct Graph{
    //name of the vertex
    int Vertex;
    //will hold the neighbors for that vertex
    vector<int> neighbors;
    //will hold the weights that go along with that neighbors
    vector<int> weights;
    //this is the default distance made and then will change with relax
    int Distance = 8675309;
    //this will hold the shortest path from the source to desitnation
    vector<int> BackToTheFuture;
};

//this will hold the vertex pointers
vector<Graph*> VertexHolder;

//since the graph2.txt file reads in the vertex's first i build the vertex with the class and store the id
//then put it into the VertexHolder
void Vertex(int VertexName){
    //creats the pointer to the Graph object called vertex
    Graph* vertex = new Graph;
    //adds the VertexName as the Vertex for the pointer
    vertex->Vertex = VertexName;
    //adds to the VertexHolder vector
    VertexHolder.push_back(vertex);   
}

//this will add the end vertex that is found for the edges as a neighbor of the start vertex
//as well as the corresponding weight (since the edge has add edge start - end weight)
void AddEdge(int Start, int End, int Weight){
    //adds end as a neighbor to the start
    VertexHolder[Start-1]->neighbors.push_back(End);
    //as well as the weight corresponding it
    VertexHolder[Start-1]->weights.push_back(Weight);

}

void DeleteVertex(){
    //will clear the vertex in VertexHolder to have a new graph
    VertexHolder.clear();
}

void IniatSS(){//graph, source
    //initalizes the source vertex
    //always the first vertex
    VertexHolder[0]->Distance = 0;

}

void Relax(int start, int end, int weight){//comeing from, going too, weight
    //will check if the start-1 (have to get array index for the vertex) distance is not the greatest number
    //And that the start->distance plus the weight is less than the end->distance
    if(VertexHolder[start-1]->Distance != 8675309 && (VertexHolder[start-1]->Distance + weight) < VertexHolder[end-1]->Distance){
        //if so the end distance is the start distance plus weight
        VertexHolder[end-1]->Distance =  VertexHolder[start-1]->Distance + weight;
        //will equat the end to the start BackToTheFuture vector so that they we main tain the exisitng path
        VertexHolder[end-1]->BackToTheFuture = VertexHolder[start-1]->BackToTheFuture;
        //then adds the end value to the end BackToTheFutre vector
        VertexHolder[end-1]->BackToTheFuture.push_back(VertexHolder[end-1]->Vertex);
    }

}

bool BellmanFord(){//graph, weight, source

    //calls the inilize function to make sure everything is set up
    IniatSS();

    //goes through all vertex except one since the frist is the source one
    for(int s = 0; s < VertexHolder.size()-1 ; s++){
        //then goes through all vertex
        for(int o = 0; o < VertexHolder.size(); o++){
            //and all there neighbors (to go through all added edges)
            for(int r = 0; r < VertexHolder[o]->neighbors.size(); r++){
                //gets the neighbor
                int neighbor = VertexHolder[o]->neighbors[r];
                //gets the weight
                int weight = VertexHolder[o]->weights[r];
                //then passes it to relax to see if the relax should happen or not
                Relax(VertexHolder[o]->Vertex, neighbor, weight);
            }
        }
    }

    //goes through al vertex's
    for(int i = 0; i < VertexHolder.size()-1 ; i++){
        //then goes though all the neighbors
        for(int n = 0; n < VertexHolder[i]->neighbors.size(); n++){
            //find the neighbors again
            int neighbor = VertexHolder[i]->neighbors[n];
            //finds the weight again (for al edges)
            int weight = VertexHolder[i]->weights[n];
            //checks for negative weights for the algorithm
            if(VertexHolder[i]->Distance != 8675309 && (VertexHolder[i]->Distance + weight) < VertexHolder[neighbor-1]->Distance){
                //will return false if found
                return false;
            }
        }
    }
    
    // else will Print the path
    //formatting
    cout << "\n";
    //goes through all Vertex in VertexHolder
    for(int t = 1; t < VertexHolder.size(); t++){
        //prints out start of the path string
        cout << "The path from " << VertexHolder[0]->Vertex << " --> " << VertexHolder[t]->Vertex << " is " << VertexHolder[0]->Vertex << " --> ";
        for(int o = 0; o < VertexHolder[t]->BackToTheFuture.size(); o++){
            //then will go through the BackToTheFuture Vextor to give the path way
            if(o == VertexHolder[t]->BackToTheFuture.size()-1){
                //for a clean output
                cout << VertexHolder[t]->BackToTheFuture[o] << "\n";
            }else if(o < VertexHolder[t]->BackToTheFuture.size()){
                //or this to get the arrow
                 cout << VertexHolder[t]->BackToTheFuture[o] << " --> ";
            }
        }
    }
    
    //return true so that in main can be checked
    return true;

    

}
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

/*

things to do:

0 graph loops till infinite (reads the other new graph and try to read graph on null) (might be fixed)
check other graphs

*/

using namespace std;

struct Graph{
    int Vertex;
    vector<int> neighbors;
    vector<int> weights;
    int Distance = 8675309;
    vector<int> BackToTheFuture;
};

vector<Graph*> VertexHolder;

void Vertex(int VertexName){
    Graph* vertex = new Graph;

    vertex->Vertex = VertexName;

    VertexHolder.push_back(vertex);   
}

void AddEdge(int Start, int End, int Weight){
    VertexHolder[Start-1]->neighbors.push_back(End);

    VertexHolder[Start-1]->weights.push_back(Weight);

}

void DeleteVertex(){
    VertexHolder.clear();
}


//from here
void printGraphData(const Graph* graph) {
    std::cout << "Vertex: " << graph->Vertex << std::endl;

    std::cout << "Neighbors: ";
    for (int neighbor : graph->neighbors) {
        std::cout << neighbor << " ";
    }
    std::cout << std::endl;

    std::cout << "Weights: ";
    for (int weight : graph->weights) {
        std::cout << weight << " ";
    }
    std::cout << std::endl;
}

void PrintAllData(){
    for (const Graph* graph : VertexHolder) {
        printGraphData(graph);
    }
}
//to here was taken from someone else
//wont have it in final submission only here for testing (making sure all is good for the data)

void IniatSS(){//graph, source
    
    VertexHolder[0]->Distance = 0;

}

void Relax(int start, int end, int weight){//comeing from, going too, weight

    if(VertexHolder[start-1]->Distance != 8675309 && (VertexHolder[start-1]->Distance + weight) < VertexHolder[end-1]->Distance){
        VertexHolder[end-1]->Distance =  VertexHolder[start-1]->Distance + weight;
        VertexHolder[end-1]->BackToTheFuture = VertexHolder[start-1]->BackToTheFuture;
        VertexHolder[end-1]->BackToTheFuture.push_back(VertexHolder[end-1]->Vertex);
    }

}

bool BellmanFord(){//graph, weight, source

    IniatSS();

    for(int s = 0; s < VertexHolder.size()-1 ; s++){
        for(int o = 0; o < VertexHolder.size(); o++){
            for(int r = 0; r < VertexHolder[o]->neighbors.size(); r++){
                int neighbor = VertexHolder[o]->neighbors[r];
                int weight = VertexHolder[o]->weights[r];
                Relax(VertexHolder[o]->Vertex, neighbor, weight);

            }
        }
    }

    for(int i = 0; i < VertexHolder.size()-1 ; i++){
        for(int n = 0; n < VertexHolder[i]->neighbors.size(); n++){
            int neighbor = VertexHolder[i]->neighbors[n];
            int weight = VertexHolder[i]->weights[n];
            if(VertexHolder[i]->Distance != 8675309 && (VertexHolder[i]->Distance + weight) < VertexHolder[neighbor-1]->Distance){
                return false;
            }
        }
    }

    // Print the path
    for(int t = 1; t < VertexHolder.size(); t++){
        cout << "The path from " << VertexHolder[0]->Vertex << " --> " << VertexHolder[t]->Vertex << " is " << VertexHolder[0]->Vertex << " --> ";
        for(int o = 0; o < VertexHolder[t]->BackToTheFuture.size(); o++){
            if(o == VertexHolder[t]->BackToTheFuture.size()-1){
                cout << VertexHolder[t]->BackToTheFuture[o] << "\n";
            }else if(o < VertexHolder[t]->BackToTheFuture.size()){
                 cout << VertexHolder[t]->BackToTheFuture[o] << " --> ";
            }
        }
    }
    

    return true;

    

}
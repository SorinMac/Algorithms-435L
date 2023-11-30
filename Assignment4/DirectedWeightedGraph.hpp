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

struct Graph{
    int Vertex;
    vector<int> neighbors;
    vector<int> weights;
    int Distance = 0;
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
    VertexHolder[0]->BackToTheFuture.clear();

    for(int i = 1; i < VertexHolder.size(); i++){
        VertexHolder[i]->Distance = 8675309;
        VertexHolder[i]->BackToTheFuture.clear();
    }

}

void Relax(int start, int end, int weight){//comeing from, going too, weight

    if(VertexHolder[end-1]->Distance > (weight + VertexHolder[start-1]->Distance)){
        VertexHolder[end-1]->Distance =  weight + VertexHolder[start-1]->Distance;
        VertexHolder[end-1]->BackToTheFuture.push_back(start);

        cout << start << "\n";
    }

}

bool BellmanFord(){//graph, weight, source

    IniatSS();

    for(int i = 1; i < VertexHolder.size()-1 ; i++){
        for(int e = 0; e < VertexHolder[i]->neighbors.size(); e++){
            int a = VertexHolder[i]->Vertex;
            int b = VertexHolder[i]->neighbors[e];
            int c = VertexHolder[i]->weights[e];
            Relax(VertexHolder[i]->Vertex, VertexHolder[i]->neighbors[e], VertexHolder[i]->weights[e]);
        }
    }

    for(int c = 0; c < VertexHolder.size()-1 ; c++){
        for(int g = 0; g < VertexHolder[c]->neighbors.size(); g++){
            if((VertexHolder[VertexHolder[c]->neighbors[g]-1]->Distance > (VertexHolder[c]->weights[g] + VertexHolder[c]->Distance))){
                return false;
            }
        }
    }
    return true;

}
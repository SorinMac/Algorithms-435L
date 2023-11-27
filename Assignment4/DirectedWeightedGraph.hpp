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
    bool IsProcessed = false;
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

    std::cout << "IsProcessed: " << (graph->IsProcessed ? "true" : "false") << std::endl;
    std::cout << "----------------------" << std::endl;
}

void PrintAllData(){
    for (const Graph* graph : VertexHolder) {
        printGraphData(graph);
    }
}
//to here was taken from someone else
//wont have it in final submission only here for testing (making sure all is good for the data)

void IniatSS(){//graph, source

}

void Relax(){//comeing from, going too, source

}

void BellmanFord(){//graph, weight, source

}
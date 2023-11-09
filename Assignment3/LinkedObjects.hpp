//librarys that are always used in c++
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct LinkedObj{
    string node;
    vector<int> neightbors;
    bool IsProcessed =  false;
};

void DepthFirstSearch(LinkedObj Vertecies[], int id, int count){
    if (Vertecies[id].IsProcessed == false) {
        Vertecies[id].IsProcessed = true;
        if(count == 5){
             cout << "Visited node " << stoi(Vertecies[id].node) - 1 << endl;
        }else{
             cout << "Visited node " << stoi(Vertecies[id].node) << endl;
        }
        
        for (int neighbor : Vertecies[id].neightbors) {
            DepthFirstSearch(Vertecies, neighbor - 1, count);
        }
    }
} 

void LinkedObjs(int vertexs, vector<int> start, vector<int> end, int count) {
    LinkedObj Vertecies[vertexs];
    int VECTOR_SIZE = 0;

    if(start.size() == end.size()){
        VECTOR_SIZE = start.size();
    }else if(start.size() > end.size()){
        VECTOR_SIZE = start.size();
    }else{
        VECTOR_SIZE = end.size();
    }

    for(int i = 0; i < vertexs; i++){
        Vertecies[i].node = to_string(i+1);
    }

    for(int i = 0; i < VECTOR_SIZE; i++){
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
        if(count == 5){
            cout << "\n";
    
            cout << "Linked Objects: " << "\n";
            
            for (int i = 0; i < vertexs; i++) {
                cout << "Neighbors of Node " << stoi(Vertecies[i].node) - 1 << ": ";
                    for (int neighbor : Vertecies[i].neightbors) {
                        cout << neighbor << " ";
                    }
                cout << endl;
            }

            int id = 0;

            cout << "\n";

            cout << "Depth First Search: " << "\n";
            
            DepthFirstSearch(Vertecies, id, count); 
        }else{
            cout << "\n";
    
            cout << "Linked Objects: " << "\n";
            
            for (int i = 0; i < vertexs; i++) {
                cout << "Neighbors of Node " << stoi(Vertecies[i].node) << ": ";
                    for (int neighbor : Vertecies[i].neightbors) {
                        cout << neighbor << " ";
                    }
                cout << endl;
            }

            int id = 0;

            cout << "\n";

            cout << "Depth First Search: " << "\n";
            
            DepthFirstSearch(Vertecies, id, count); 
        }
        
    }
    
}
//librarys that are always used in c++
#include <iostream>
#include <vector>
using namespace std;

struct LinkedObj{
    string node;
    vector<int> neightbors;
    bool IsProcessed =  false;
};

void LinkedObjs(int vertexs, vector<int> start, vector<int> end) {
    //make a array of size vertexes and then at each one make a LinkedObj for each one with id of the array spot+1;

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
    
    for(int i = 0; i < vertexs; i++){
        cout << Vertecies[i].neightbors << "\n";
    }
    
}
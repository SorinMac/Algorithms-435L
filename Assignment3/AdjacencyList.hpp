//librarys that are always used in c++
#include <iostream>
#include <vector> 
using namespace std;

void AdjacencyList(int vertexs, vector<int> start, vector<int> end){
    vector <int> neighbors[vertexs];
    int VECTOR_SIZE = 0;

    if(start.size() == end.size()){
        VECTOR_SIZE = start.size();
    }else if(start.size() > end.size()){
        VECTOR_SIZE = start.size();
    }else{
        VECTOR_SIZE = end.size();
    }

    for(int i = 0; i < VECTOR_SIZE; i++){
        if(start[i] == 0){
            neighbors[start[i]].push_back(end[i]);
            neighbors[end[i]-1].push_back(start[i]);
        }else if(end[i] == 0){
            neighbors[start[i]-1].push_back(end[i]);
            neighbors[end[i]].push_back(start[i]);
        }else{
            neighbors[start[i]-1].push_back(end[i]);
            neighbors[end[i]-1].push_back(start[i]);
        }
    }

    for(int i = 0; i < VECTOR_SIZE; i++){
        cout <<  << "\n";
    }

}
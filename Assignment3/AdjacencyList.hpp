//librarys that are always used in c++
#include <iostream>
#include <vector> 
using namespace std;

void AdjacencyList(int vertexs, vector<int> start, vector<int> end, int count){
    //makes a array with vectors or size Vertexs.
    vector <int> neighbors[vertexs];
    int VECTOR_SIZE = 0;

    //to check howe many edges there are (for is the start has more than the end)
    if(start.size() == end.size()){
        VECTOR_SIZE = start.size();
    }else if(start.size() > end.size()){
        VECTOR_SIZE = start.size();
    }else{
        VECTOR_SIZE = end.size();
    }

    //will go through the VECTOR_SIZE amount and add to what every the start is the end value connected to and vis versa
    for(int i = 0; i < VECTOR_SIZE; i++){
        
        //checking if given a 0 vertex
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

    if(vertexs > 0){
        //special print if the vertex start at 0 instead of 1
        if(count == 5){
            cout << "\n";
    
            cout << "Adjacency List: " << "\n";


            for (int i = 0; i < vertexs; i++) {
                cout << "Vertex " << i << ": ";
                for (int j = 0; j < neighbors[i].size(); j++) {
                    cout << neighbors[i][j] << " ";
                }
                cout << endl;
            }
            
        }else{
            //print out if the vertex starts a 1
            cout << "\n";
    
            cout << "Adjacency List: " << "\n";

            //goes to every vertex in the neighbors array
            for (int i = 0; i < vertexs; i++) {
                
                //prints out the vertex
                cout << "Vertex " << i + 1 << ": ";

                //and all the neighbors at that specific vertex (kinda like a 2d array)
                for (int j = 0; j < neighbors[i].size(); j++) {
                    cout << neighbors[i][j] << " ";
                }
                cout << endl;
            }

        }

    }

}
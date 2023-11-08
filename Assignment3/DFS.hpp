//librarys that are always used in c++
#include <iostream>
using namespace std;

void DeapthFirstSearch(LinkedObj vertex){
    if (vertex.IsProcessed == false){
        cout << vertex.node << "\n";
        vertex.IsProcessed = true;
    }

    for(int i = 0; i < vertex.neightbors.size(); i++){
        if(vertex.IsProcessed == false){
           //DeapthFirstSearch(//the vertex that you are on);
        }
    }
}   

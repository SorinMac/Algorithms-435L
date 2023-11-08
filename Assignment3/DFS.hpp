//librarys that are always used in c++
#include <iostream>
using namespace std;

void DeapthFirstSearch(LinkedObj vertex){
    if (vertex.IsProcessed == false){
        cout << vertex.node << "\n";
        vertex.IsProcessed = true;
    }
}   
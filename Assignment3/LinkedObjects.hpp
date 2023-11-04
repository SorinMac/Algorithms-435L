//librarys that are always used in c++
#include <iostream>
#include <vector>
using namespace std;

struct LinkedObj{
    string node;
    vector<string> neightbors;
    bool IsProcessed =  false;
};

void LinkedObjs(int vertexs, vector<int> start, vector<int> end) {
    //make a array of size vertexes and then at each one make a LinkedObj for each one with id of the array spot+1;
}
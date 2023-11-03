//librarys that are always used in c++
#include <iostream> 
#include <vector>
using namespace std;

void MatrixGraph(int vertexs, vector<int> start, vector<int> end) {
    int Matrix[vertexs][vertexs];

    for(int i = 0; i < start.size() && i < end.size(); i++){
        Matrix[start[i]][end[i]] = 1;
        Matrix[end[i]][start[i]] = 1;
    }

}
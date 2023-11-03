//librarys that are always used in c++
#include <iostream> 
#include <vector>
using namespace std;

void MatrixGraph(int vertexs, vector<int> start, vector<int> end) {
    int Matrix[vertexs][vertexs];
    const int VECTOR_SIZE = start.size();

    for(int i = 0; i < vertexs; i++){
        for(int j = 0; j < vertexs; j++){
            Matrix[i][j] = 0;
        }
    }

    for(int i = 0; i < VECTOR_SIZE; i++){
        Matrix[start[i]-1][end[i]-1] = 1;
        Matrix[end[i]-1][start[i]-1] = 1;
    } 

}
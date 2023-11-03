//librarys that are always used in c++
#include <iostream> 
#include <vector>
using namespace std;

int* MatrixGraph(int vertexs, vector<int> start, vector<int> end) {
    start = {1,1,1,2,2,2,3,4,5,5,6};
    end = {2,5,6,3,5,6,4,5,6,7,7};
    int Matrix[vertexs][vertexs];

    for(int i = 0; i < start.size() && i < end.size(); i++){
        Matrix[start[i]][end[i]] = 1;
        Matrix[end[i]][start[i]] = 1;
    }

    return *Matrix;
      




}
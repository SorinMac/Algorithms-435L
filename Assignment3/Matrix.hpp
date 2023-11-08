//librarys that are always used in c++
#include <iostream> 
#include <vector>
using namespace std;

void MatrixGraph(int vertexs, vector<int> start, vector<int> end) {
    int Matrix[vertexs][vertexs];
    int VECTOR_SIZE = 0;

    if(start.size() == end.size()){
        VECTOR_SIZE = start.size();
    }else if(start.size() > end.size()){
        VECTOR_SIZE = start.size();
    }else{
        VECTOR_SIZE = end.size();
    }

    for(int i = 0; i < vertexs; i++){
        for(int j = 0; j < vertexs; j++){
            Matrix[i][j] = 0;
        }
    }

    for(int i = 0; i < VECTOR_SIZE; i++){

        if(start[i] == 0){
            Matrix[start[i]][end[i]-1] = 1;
            Matrix[end[i]-1][start[i]] = 1;
        }else if(end[i] == 0){
            Matrix[start[i]-1][end[i]] = 1;
            Matrix[end[i]][start[i]-1] = 1;
        }else{
            Matrix[start[i]-1][end[i]-1] = 1;
            Matrix[end[i]-1][start[i]-1] = 1;
        }
    }

    if(vertexs > 0){
        cout << "\n";

        cout << "Matrix: " << "\n";

        for(int a = 0; a < vertexs; a++){

            for(int b = 0; b < vertexs; b++){
                cout << Matrix[a][b] << " ";
            }

            cout << endl;
        } 
    } 

}
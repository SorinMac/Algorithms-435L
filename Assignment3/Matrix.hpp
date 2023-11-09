//librarys that are always used in c++
#include <iostream> 
#include <vector>
using namespace std;

void MatrixGraph(int vertexs, vector<int> start, vector<int> end) {
    //makes a 2d array of row vertex and colum vertex
    int Matrix[vertexs][vertexs];
    int VECTOR_SIZE = 0;

    //to check howe many edges there are (for is the start has more than the end)
    if(start.size() == end.size()){
        VECTOR_SIZE = start.size();
    }else if(start.size() > end.size()){
        VECTOR_SIZE = start.size();
    }else{
        VECTOR_SIZE = end.size();
    }


    //initilize everything so now outputing errors
    for(int i = 0; i < vertexs; i++){
        for(int j = 0; j < vertexs; j++){
            Matrix[i][j] = 0;
        }
    }

    //will go to Matrix array row start column end and make the value a 1 instead of a 0
    for(int i = 0; i < VECTOR_SIZE; i++){

        //checking if given a 0 vertex
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

        //print out for the Matrix array
        cout << "\n";

        cout << "Matrix: " << "\n";

        //goes through every row
        for(int a = 0; a < vertexs; a++){
            
            //and prints everything out in that column at that row
            for(int b = 0; b < vertexs; b++){
                cout << Matrix[a][b] << " ";
            }

            cout << endl;
        } 
    } 


}
#include "main.h"

void printPoints(point *points, const int& length){
    // cout << length << " points\n";
    for(int i = 0; i < length; i++){
        cout << "( " << points[i].x << " , " << points[i].y << " )\n";
    }
}

void printDistanceMatrix(int **distMatrix, const int& count){
    // cout << count << "x" << count << " distance matrix\n";
    for(int i = 0; i < count; i++){
        for(int j = 0; j < count; j++){
             cout << "d(" << i << "," << j << "):" << distMatrix[i][j] << "\n";
        }
    }
}

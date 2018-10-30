#include "main.h"

int getDistance(const point& i, const point& j){
    double dist = sqrt((i.x - j.x)*(i.x-j.x) + (i.y - j.y)*(i.y-j.y));
    //cout << "i:(" << i.x << "," << i.y << ") j:(" << j.x << "," << j.y << ")\n";
    //cout << "d(i,j)=" << dist << "\n";
    return round(dist);
}

void buildDistanceMatrix(point *points, int **distMatrix, const int& count){
    for(int i = 0; i < count; i++){
        for(int j = 0; j < count; j++){
            if(i == j){
                distMatrix[i][j] = 0;
            } else if(distMatrix[i][j] == 0){
                int d = getDistance(points[i], points[j]);
                distMatrix[i][j] = d;
                distMatrix[j][i] = d;
            }
        }
    }
}

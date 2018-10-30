#include "main.h"

// Check all edges emanating from tree to find minimum
void minStHelper(int **st, int *covered, int **dm, const int& n, int *degrees) {
    int min = INT_MAX;
    edge newEdge = {-1, -1};

    for (int i = 0; i < n; i++) {
        if (covered[i]) {
            for (int j = 0; j < n; j++) {
                if (!covered[j] && dm[i][j] < min) {
                    min = dm[i][j];
                    newEdge.u = i;
                    newEdge.v = j;
                }
            }
        }
    }

    assert(newEdge.u != -1 && newEdge.v != -1); // Error check

    st[newEdge.u][newEdge.v] = 1;
    st[newEdge.v][newEdge.u] = 1;
    degrees[newEdge.u]++;
    degrees[newEdge.v]++;
    covered[newEdge.u] = covered[newEdge.v] = 1;
}

void minSt(int ** st, int **dm, const int& n, int *covered, int *degrees) {
    covered[0] = 1;                      // Start at node 0
    int nodesLeft = n-1;                 // Num nodes not yet covered

    while (nodesLeft > 0) {
        minStHelper(st, covered, dm, n, degrees);
        nodesLeft--;
    }
}

void printSt(int **st, const int& n) {
    cout << "Edges in min spanning tree:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (st[i][j])
            cout << "(" << i << "," << j << ") : " << st[i][j] << "\n";
        }
    }
}

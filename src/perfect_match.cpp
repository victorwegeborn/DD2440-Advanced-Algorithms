#include "main.h"
#include "PerfectMatching.h"


void findDegreesOfSt(int **st, int *odd, int& numberOfOddNodes, int* nodeMapping, const int& n) {
    int node = 0;
    for (int i = 0; i < n; i++) {
        int c = 0;
        //*(nodeMapping + i) = -1; // -1 => no mapping
        for (int j = 0; j < n; j++) {
            if (st[i][j]) {

                c++;
            }
        }
        if(c & 1) {
            *(odd + i) = 1;
            numberOfOddNodes++;
            *(nodeMapping + i) = node;
            node++;
        }
        else
            *(odd + i) = 0;
    }
}

void printDegreesOfSt(const int *degree, const int& numberOfOddNodes, const int* nodeMapping, const int& n) {
    // cout << "Degrees of min spanning tree nodes:\n";
    for (int i = 0; i < n; i++) {
        cout << i << ": " << degree[i] << "\n";
    }
    // cout << "number of odd nodes: " << numberOfOddNodes << "\n";
    // cout << "Node mapping: \n";
    for(int i = 0; i < n; i++) {
        cout << i << " -> " << *(nodeMapping+i) << "\n";
    }

}

// NOT CHECKED FOR EDGE CASES!!! RISK FOR OFF ONE SEGMENTATION FAULT
int reverseNodeMap(int idx, int step, const int* nodeMapping, const int& max) {
    if(idx == nodeMapping[step])
        return step;
    if(nodeMapping[step] < idx)
        return reverseNodeMap(idx, step+1, nodeMapping, max);
    assert(!"This point should never be reached");
}

// find min weight perfect match on complete graph of nodes with
// odd nodes in spanning tree
void minWeightPerfectMatch(int **st, const int *d, const int& numberOfOddNodes, const int* nodeMapping, int **distMatrix, const int& n) {

    int V = numberOfOddNodes;
    int E = (V*(V-1))/2;
    edge edges[E];
    class PerfectMatching::PerfectMatching *p = new PerfectMatching(V,E);

    for(int i = 0; i < n; i++) {
        // only consider nodes with odd degre
        if(*(d+i) & 1 && *(nodeMapping + i) != -1) {
            for(int j = i; j < n; j++) {

                // consider only odd connecting nodes
                if((*(d+j) & 1) && (i != j)) {
                    // remap nodes for PerfectMatching library
                    int u = *(nodeMapping + i);
                    int v = *(nodeMapping + j);

                    if(DEBUG)
                        cout << "{" << i << "," << j << "} -> {" << u << "," << v << "}, cost: " << distMatrix[i][j] <<"\n" ;

                    // add edge to library with correct distances.
                    int idx = p->AddEdge(u,v,distMatrix[i][j]);
                    edges[idx].u = u;
                    edges[idx].v = v;

                    // idx = p->AddEdge(v,u,distMatrix[(i*n)+j]);
                    // edges[idx].u = v;
                    // edges[idx].v = u;
                }
            }
        }
    }
    p->Solve();

    if(DEBUG)
        cout << "Perfect matching:\n";

    for(int e = 0; e < E; e++) {
        if(p->GetSolution(e)) {
            int x = reverseNodeMap(edges[e].u, 0, nodeMapping, n);
            int y = reverseNodeMap(edges[e].v, 0, nodeMapping, n);

            if(DEBUG)
                cout << "{" << edges[e].u << "," << edges[e].v << "} -> {" << x << "," << y << "}, << cost: " << distMatrix[x][y] << "\n";

            st[x][y] += 1;
            st[y][x] += 1;
        }
    }
    delete p;
}

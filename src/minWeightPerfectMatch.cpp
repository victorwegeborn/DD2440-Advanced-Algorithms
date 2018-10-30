#include "main.h"
#include "PerfectMatching.h"


void minWeightPerfectMatch(int **G, int **cost, const int& n, int *degrees, int *map) {

    int V = 0;
    for(int i = 0; i < n; i++) {
        if(degrees[i] & 1)
            V++;
    }

    int E = n*(n-1)/2;
    if(V & 1) V++;

    /* MUST KNOW AMOUNT OF VERTECIES BEFORE INITIALIZE */
    class PerfectMatching::PerfectMatching *p = new PerfectMatching(V,E);
    vector<edge> edges;
    E = 0;
    int idx = 0;
    for(int i = 0; i < n; i++) {
        // Consider odd nodes
        if(degrees[i] & 1) {
            for(int j = i; j < n; j++) {
                // Consider only odd nodes
                if(i != j && (degrees[j] & 1)) {
                    if(map[i]<0) {
                        map[i] = idx;
                        idx++;
                    }
                    if(map[j]<0) {
                        map[j] = idx;
                        idx++;
                    }
                    p->AddEdge(map[i],map[j],cost[i][j]);
                    edge e = {i,j};
                    edges.push_back(e);
                    E++;
                }
            }
        }
    }
    p->Solve();
    for (int i = 0; i < E; i++) {
        if(p->GetSolution(i)) {
            G[edges.at(i).u][edges.at(i).v]++;
            G[edges.at(i).v][edges.at(i).u]++;
        }
    }
    delete p;
}

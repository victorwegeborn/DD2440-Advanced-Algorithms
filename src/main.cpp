#include "main.h"

static const bool DEBUG = false;



int main(int argc, char** argv) {
#if defined(TESTEULER)
    testEuler();
#elif defined(TESTMINSPANNINGTREE)
    testMinSpanningTree();
#else

    int n;
    ios::sync_with_stdio(false);    // <--- SPEED UP IO
    cin >> n;                       // Read number of coordinates
    dim = n;

    // Account for edge case of only one node
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    // Initialize
    point points[n];
    int degrees[n];
    int nodeMapping[n];
    int covered[n];
    int nodeMap[n];
    int numberOfOddNodes = 0;
    int ** G = new int*[n];
    int **distMatrix = new int*[n];
    for(int i = 0; i < n; i++){
        G[i] = new int[n]();
        distMatrix[i] = new int[n]();

        degrees[i] = 0;
        nodeMap[i] = -1;
        covered[i] = 0;
        nodeMap[i] = -1;

        cin >> points[i].x;
        cin >> points[i].y;
    }

    buildDistanceMatrix(points, distMatrix, n);
    minSt(G, distMatrix, n, covered, degrees);
    minWeightPerfectMatch(G, distMatrix, n, degrees, nodeMap);

    // Find Euler tour over stWithMatching
    int *tour = eulerTour(G, n);
    int *optTour = twoOpt(tour, distMatrix , n);

    // Print Euler tour
    // cout << "Result of Euler tour:\n";
    for (int i = 0; i < n; i++)
        cout << optTour[i] << "\n";


    delete[] optTour;


    for(int i = 0; i < n; i++) {
        delete [] G[i];
        delete [] distMatrix[i];
    }
    delete [] G;
    delete [] distMatrix;
#endif

    return 0;
}

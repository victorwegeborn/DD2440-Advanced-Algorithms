#include "main.h"

int distance(int *tour, int n, int **cost) {
    int res = 0;
    for(int i = 0; i < n-1; i++){
        res += cost[tour[i]][tour[i+1]];
    }
    res += cost[tour[n-1]][tour[0]];
}


// Return difference: newDist - oldDist
// Negative if swap is beneficial, else INT_MAX
int optSwap(int *oldTour, int oldTourDist, int *newTour, int a, int b, int n, int **dm) {
    // Nope out if not beneficial
    int beforeA = (a-1 < 0 ? n-1 : a-1);
    int afterA = a+1;
    int afterB = (b+1 > n-1 ? 0 : b+1);

    if ( !(dm[oldTour[a]][oldTour[afterB]] < dm[oldTour[a]][oldTour[afterA]] ||
          dm[oldTour[b]][oldTour[afterA]] < dm[oldTour[b]][oldTour[afterB]]))
        return INT_MAX;

    // Add nodes from 0 to a-1 in order
    for (int i = 0; i < a; i++) {
        newTour[i] = oldTour[i];
    }

    // Add nodes from a to b in reverse order
    {
        int j = b;
        for (int i = a; i <= b; i++) {
            newTour[i] = oldTour[j];
            j--;
        }
    }

    // Add nodes from b+1 to n-1 in order
    for (int i = b+1; i < n; i++) {
        newTour[i] = oldTour[i];
    }

    // cout << "New tour after swapped with a=" << a << " and b=" << b << endl;
    // for(int i = 0; i < n; i++) {
    //     cout << newTour[i] << endl;
    // }
    // cout << "---" << endl;

    return distance(newTour, n, dm) - oldTourDist;
}


int *twoOpt(int* tour, int **cost, int &n) {
    int *newTour = new int[n]();

    int dist = distance(tour, n, cost);
    int improvementFound = 1;
    while (improvementFound) {
        improvementFound = 0;

        for (int i = 0; i < n - 1; i++) {
            for (int k = i+1; k < n; k++) {
                int difference = optSwap(tour, dist, newTour, i, k, n, cost);

                if (difference < 0) {
                    improvementFound = 1;
                    memcpy(tour, newTour, n * sizeof(int));
                    dist += difference;
                    assert(dist > 0);
                }
            }
        }
    }
    return tour;
}

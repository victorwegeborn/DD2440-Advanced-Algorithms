#ifndef MAIN_H
#define MAIN_H
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <unordered_map>
#include <string.h>
#include <iterator>
#include <vector>
#include <limits.h>
#include <assert.h>
#include <ctime>
#include <stdio.h>
#include "PerfectMatching.h"
#include "LCA.h"
using namespace std;

static int dim;


struct point {
    double x;
    double y;
};

struct edge {
    int u;
    int v;
};

// A stop in the tour
struct stop {
    int id; // Id of node stop is at
    stop *next;
};

// A loop = a sequence of stops in the tour.
// Invariant: last->next = first.
struct loop {
    stop *first;
    stop *last;
};

void printPoints(point *points, const int& length);
void printDistanceMatrix(int **distMatrix, const int& count);
int getDistance(const point& i, const point& j);
void buildDistanceMatrix(point *points, int **distMatrix, const int& count);
void minStHelper(int **st, int *covered, int **dm, const int& n, int *degrees);
void minSt(int ** st, int **dm, const int& n, int *covered, int *degrees);
void printSt(int **st, const int& n);
int *eulerTour(int **g, int n);
int *twoOpt(int* tour, int **cost, int &n);
void testEuler(void);
void testMinSpanningTree(void);
void minWeightPerfectMatch(int **G, int **cost, const int& n, int *degrees, int *map);
void findDegreesOfSt(int **st, int *odd, int& numberOfOddNodes, int* nodeMapping,
    const int& n);
void printDegreesOfSt(const int *degree, const int& numberOfOddNodes,
    const int* nodeMapping, const int& n);
int reverseNodeMap(int idx, int step, const int* nodeMapping, const int& max);
void minWeightPerfectMatch(int **st, const int *d,
    const int& numberOfOddNodes, const int* nodeMapping,
    int **distMatrix, const int& n);
#endif

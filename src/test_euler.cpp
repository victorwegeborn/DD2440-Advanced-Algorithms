#include "main.h"

void testEuler(void) {
    {
        int n = 6;
        int **g = (int **) malloc(n * sizeof(int *));
        for (int i = 0; i < n; i++) {
            g[i] = (int *) calloc(n, sizeof(int));
        }

        g[0][1] = 1;  //     0---1
        g[1][0] = 1;  //     |   |
        g[1][2] = 1;  // 5---3---2
        g[2][1] = 1;  //  \  |
        g[2][3] = 1;  //   `-4
        g[3][2] = 1;
        g[0][3] = 1;
        g[3][0] = 1;
        g[3][4] = 1;
        g[4][3] = 1;
        g[3][5] = 1;
        g[5][3] = 1;
        g[4][5] = 1;
        g[5][4] = 1;

        int *tour = eulerTour(g, n);
    }

    {
        int n = 6;
        int **g = (int **) malloc(n * sizeof(int *));
        for (int i = 0; i < n; i++) {
            g[i] = (int *) calloc(n, sizeof(int));
        }

        g[0][1] = 1;  // 0---1
        g[1][0] = 1;  // |   |
        g[1][2] = 1;  // 3---2---4
        g[2][1] = 1;  //     |  /
        g[2][3] = 1;  //     5´
        g[3][2] = 1;
        g[0][3] = 1;
        g[3][0] = 1;
        g[2][4] = 1;
        g[4][2] = 1;
        g[2][5] = 1;
        g[5][2] = 1;
        g[4][5] = 1;
        g[5][4] = 1;

        int *tour = eulerTour(g, n);
        cout << "Test 1\n";
        for (int i = 0; i < n; i++)
            cout << tour[i] << "\n";
        cout << '\n';
    }

    {
        int n = 6;
        int **g = (int **) malloc(n * sizeof(int *));
        for (int i = 0; i < n; i++) {
            g[i] = (int *) calloc(n, sizeof(int));
        }



        g[0][1] = 1; //   - 5
        g[1][0] = 1; //  /  |
        g[1][2] = 1; // 4---0---1
        g[2][1] = 1; //     |   |
        g[2][3] = 1; //     3---2
        g[3][2] = 1;
        g[0][3] = 1;
        g[3][0] = 1;
        g[0][4] = 1;
        g[4][0] = 1;
        g[0][5] = 1;
        g[5][0] = 1;
        g[4][5] = 1;
        g[5][4] = 1;

        int *tour = eulerTour(g, n);
        cout << "Test 2\n";
        for (int i = 0; i < n; i++)
            cout << tour[i] << "\n";
        cout << '\n';
    }

    {
        int n = 6;
        int **g = (int **) malloc(n * sizeof(int *));
        for (int i = 0; i < n; i++) {
            g[i] = (int *) calloc(n, sizeof(int));
        }

        // Produced by sample 2
        g[0][0] = 0;
        g[0][1] = 1;
        g[0][2] = 0;
        g[0][3] = 1;
        g[0][4] = 0;
        g[0][5] = 0;
        g[1][0] = 1;
        g[1][1] = 0;
        g[1][2] = 1;
        g[1][3] = 1;
        g[1][4] = 1;
        g[1][5] = 0;
        g[2][0] = 0;
        g[2][1] = 1;
        g[2][2] = 0;
        g[2][3] = 0;
        g[2][4] = 0;
        g[2][5] = 1;
        g[3][0] = 1;
        g[3][1] = 1;
        g[3][2] = 0;
        g[3][3] = 0;
        g[3][4] = 0;
        g[3][5] = 0;
        g[4][0] = 0;
        g[4][1] = 1;
        g[4][2] = 0;
        g[4][3] = 0;
        g[4][4] = 0;
        g[4][5] = 1;
        g[5][0] = 0;
        g[5][1] = 0;
        g[5][2] = 1;
        g[5][3] = 0;
        g[5][4] = 1;
        g[5][5] = 0;

        int *tour = eulerTour(g, n);

        cout << "Test 3\n";
        for (int i = 0; i < n; i++)
            cout << tour[i] << "\n";
        cout << '\n';
    }
}

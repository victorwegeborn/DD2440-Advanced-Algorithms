#include "main.h"

/*
    Work with MatLab version R2015b
*/


void printMatlabEdge(vector<int> edges, int &E) {
    for(int i = 0; i < E; i++) cout << " " << edges.at(i)+1;
}

void makeMatlabG(int* tour, int &n, unsigned int* weights, point *cord) {
    int **complete = new int*[n];
    for(int i = 0; i < n; i++) {
        complete[i] = new int[n];
        for(int j = 0; j < n; j++) {
            if(i != j)
                complete[i][j] = 1;
        }
    }

    vector<int> s;
    vector<int> t;
    int E = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if(complete[i][j]) {
                E++;
                s.push_back(i);
                t.push_back(j);
            }
        }
    }



    cout << "\n\n% MATLAB CODE. COPY PASTE INTO MATLAB R2015b+\n";
    cout << "clc\n\n";


    cout << "tour = [";
    int start = tour[0] + 1;
    for(int i = 0; i < n; i++) {
        cout << " " << tour[i]+1;
    }
    cout << " " << start << "];\n\n";


    cout << "% node coordinates\n";
    cout << "x = [";
    for(int i = 0; i < n; i++) {
        cout << " " << cord[i].x;
    }
    cout << "];\n";
    cout << "y = [";
    for(int i = 0; i < n; i++) {
        cout << " " << cord[i].y;
    }
    cout << "];\n\n";


    cout << "s = [";
    printMatlabEdge(s, E);
    cout << "];\n";
    cout << "t = [";
    printMatlabEdge(t, E);
    cout << "];\n";


    cout << "G = graph(s,t);\n\n";


    cout << "GPLOT = plot(G,'XData',x,'YData',y,'LineWidth',0.025);\n"
         << "highlight(GPLOT,G,'EdgeColor',[0.67 0.67 0.67])\n"
         << "highlight(GPLOT,tour,'EdgeColor','r','lineWidth',3);\n\n";

    cout << "%%%%%%%%%%%% END OF MATLAB OUTPUT %%%%%%%%%%%%%\n";
}

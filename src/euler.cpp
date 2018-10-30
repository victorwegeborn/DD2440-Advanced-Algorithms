void printLoop(loop l) {
    stop *curr = l.first;
    do {
        cout << curr->id << '\n';
        curr = curr->next;
    } while (curr != l.first);
}

// Return id of node with an unused outgoing edge from 'tour'
int nodeWithUnusedOutgoingEdge(int **g, int n, loop tour) {
    stop *curr = tour.first;
    do {
        for (int i = 0; i < n; i++) {
            if (g[curr->id][i] > 0)
                return curr->id;
        }
        curr = curr->next;
    } while (curr != tour.first);

    return -1; // Signifies no node with unused edge found
}

// Return pointer to a new stop at node i, allocated on heap
stop *makeNewStop(int i) {
    stop *newStop = (stop *) malloc(sizeof(stop));
    newStop->id = i;
    newStop->next = NULL;
    return newStop;
}

// Return a loop struct, with stops allocated on heap.
// A loop = a sequence of stops.
// Invariant: last->next = first.
loop findLoop(int **g, int n, int startId) {
    stop *startOfLoop = makeNewStop(startId);
    loop loop = { startOfLoop, NULL };

    stop *curr = startOfLoop;
    int i = 0;

    // The second condition is here to not exit out of the while loop after the
    // first iteration (if no edge is found immediately)
    while (curr->id != startId || loop.last == NULL) {
        // We should never reach a node with no outgoing edge
        assert(i < n && "A node with uneven degree found while constructing Euler path");

        if (g[curr->id][i]) {
            // Edge from curr to i exists. Add i to loop
            stop *newStop = makeNewStop(i);
            curr->next = newStop;

            // Update loop
            loop.last = curr;

            // Mark edge as used (delete edge)
            g[curr->id][i]--;
            g[i][curr->id]--;

            // Set things up for the next iteration (move on to new node)
            curr = newStop;
            i = 0;
        } else {
            // Edge from curr to i does not exist, check next i
            i++;
        }
    }

    // Verify that at least one stop was added to the loop
    assert(startOfLoop->next != NULL);
    assert(loop.last != NULL);
    // Verify invariant
    assert(loop.last->next = loop.first);

    return loop;
}

// Return a new loop which is a and b merged (starting with a).
// This function has side effects: It uses the stops from loops a and b
// directly, so a and b are not valid loops after this function has run.
loop mergeLoops(loop a, loop b) {
    // Find stop x = stop in a at which b starts
    stop *x;
    {
        stop *curr = a.first;
        while (curr->id != b.first->id)
            curr = curr->next;

        x = curr;
    }
    assert(x->id == b.first->id);

    // Merge the loops, skipping b.first
    b.last->next = x->next;
    x->next = b.first->next;
    free(b.first); // b.first is not used in the merged loop

    loop merged;
    merged.first = a.first; // Always the same
    merged.last = (x == a.last ? b.last : a.last);
    // If loop b starts at last stop in a, use b.last as merged.last. Else use
    // a.last.

    return merged;
}

// Input: Graph g with n nodes
int *eulerTour(int **g, int n) {
    // Find the first loop of the tour
    loop tour = findLoop(g, n, 0);

    // Add new loops until no more exist
    {
        int startOfNewLoop = nodeWithUnusedOutgoingEdge(g, n, tour);
        while (startOfNewLoop != -1) {
            loop newLoop = findLoop(g, n, startOfNewLoop);
            tour = mergeLoops(tour, newLoop); // Add newLoop onto tour

            // Find unused edge for next iteration
            startOfNewLoop = nodeWithUnusedOutgoingEdge(g, n, tour);
        }
    }

    // Remove duplicates
    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Prepare return array
    int *res = (int *) malloc(n * sizeof(int));
    {
        stop *curr = tour.first;
        int i = 0;
        do {
            if (!visited[curr->id]) {
                visited[curr->id] = 1;
                res[i] = curr->id;
                i++;
            }
            curr = curr->next;
        } while (curr != tour.first);
    }
    return res;
}

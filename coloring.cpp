#include <iostream>
using namespace std;

#define V 5 // Number of vertices in the graph

bool isSafe(int graph[V][V], int color[], int v, int c) {
    for (int i = 0; i < V; ++i) {
        if (graph[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V) {
        return true; // All vertices are assigned colors
    }

    for (int c = 1; c <= m; ++c) {
        if (isSafe(graph, color, v, c)) {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }

            color[v] = 0; // Backtrack and try a different color
        }
    }

    return false; // No valid color assignment found
}

void graphColoring(int graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; ++i) {
        color[i] = 0; // Initialize all vertices with color 0 (uncolored)
    }

    if (graphColoringUtil(graph, m, color, 0)) {
        cout << "Graph can be colored using at most " << m << " colors.\n";
        cout << "Color assignment for each vertex:\n";
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << char('A' + i) << ": Color " << color[i] << endl;
        }
    } else {
        cout << "Graph cannot be colored using " << m << " colors.\n";
    }
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 1},
        {1, 0, 1, 0, 1},
        {0, 1, 1, 1, 0}
    };
    int m = 3; // Number of colors

    graphColoring(graph, m);

    return 0;
}

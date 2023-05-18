#include <iostream>
#include <climits>
using namespace std;

#define V 5 // Number of vertices in the graph

void floydWarshall(int graph[V][V]) {
    int dist[V][V];

    // Initialize the dist matrix with the graph's values
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            dist[i][j] = graph[i][j];
        }
    }

    // Run Floyd-Warshall algorithm
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                // Calculate the distance from i to j through k
                int distance_through_k = dist[i][k] + dist[k][j];

                // Update dist[i][j] if the new distance is shorter
                if (dist[i][j] > distance_through_k) {
                    dist[i][j] = distance_through_k;
                }
            }
        }
    }

    // Print the shortest distances
    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INT_MAX) {
                cout << "INF\t";
            } else {
                cout << dist[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

int main() {
    int graph[V][V] = {
        {0, 3, 8, INT_MAX, -4},
        {INT_MAX, 0, INT_MAX, 1, 7},
        {INT_MAX, 4, 0, INT_MAX, INT_MAX},
        {2, INT_MAX, -5, 0, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 6, 0}
    };

    floydWarshall(graph);

    return 0;
}

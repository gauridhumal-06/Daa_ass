#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

const int INF = INT_MAX;

// Function to solve the Traveling Salesman Problem using dynamic programming
int tsp(const std::vector<std::vector<int>>& graph, int start, int mask, std::vector<std::vector<int>>& dp) {
    int n = graph.size();

    // Base case: If all cities have been visited, return the cost of returning to the start city
    if (mask == (1 << n) - 1) {
        return graph[start][0];
    }

    // If the subproblem has already been solved, return the stored value
    if (dp[start][mask] != -1) {
        return dp[start][mask];
    }

    // Calculate the minimum cost for the current subproblem
    int minCost = INF;
    for (int next = 0; next < n; next++) {
        // If the next city has not been visited
        if ((mask & (1 << next)) == 0) {
            int newMask = mask | (1 << next);
            int cost = graph[start][next] + tsp(graph, next, newMask, dp);
            minCost = std::min(minCost, cost);
        }
    }

    // Store the minimum cost for the current subproblem
    dp[start][mask] = minCost;

    return minCost;
}

int main() {
    std::vector<std::vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int n = graph.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(1 << n, -1));

    int start = 0; // Starting city

    int minCost = tsp(graph, start, 1, dp);

    std::cout << "The minimum cost of the TSP tour is: " << minCost << std::endl;

    return 0;
}

all pair shortest path using dp

   |  A  |  B  |  C  |  D  |  E  |
---------------------------------
A  |  0  |  3  |  8  | inf | -4  |
---------------------------------
B  | inf |  0  | inf |  1  | 7   |
---------------------------------
C  | inf |  4  |  0  | inf | inf |
---------------------------------
D  |  2  | inf | -5  |  0  | inf |
---------------------------------
E  | inf | inf | inf |  6  |  0  |
---------------------------------



code: 
1.
dist[][] = {
  { 0, 3, 8, inf, -4 },
  { inf, 0, inf, 1, 7 },
  { inf, 4, 0, inf, inf },
  { 2, inf, -5, 0, inf },
  { inf, inf, inf, 6, 0 }
}

2.
for (int k = 0; k < V; ++k) {
  for (int i = 0; i < V; ++i) {
    for (int j = 0; j < V; ++j) {
      // Calculate the distance from i to j through k
      // and update dist[i][j] if it's shorter
    }
  }
}

3.
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

4.
dist[][] = {
  { 0, 1, -3, 2, -4 },
  { 3, 0, -4, 1, -1 },
  { 7, 4, 0, 5, 3 },
  { 2, -1, -5, 0, -2 },
  { 8, 5, 1, 6, 0 }
}

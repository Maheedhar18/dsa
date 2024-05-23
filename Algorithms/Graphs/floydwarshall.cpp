#include <bits/stdc++.h>
using namespace std;

// Floyd-Warshall algorithm is used to find the shortest paths between all pairs of vertices in a graph.
// Time Complexity: O(V3), as we have three nested loops each running for V times, where V = no. of vertices.
// Space Complexity: O(V2), where V = no. of vertices. This space complexity is due to storing the adjacency matrix of the given graph.


void floyd_warshall(int vertices, vector<vector<int>>& matrix, bool &negativeCycle) {
    // Initialize the distance matrix.
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i == j) matrix[i][j] = 0; // Distance from a vertex to itself is 0.
            if (matrix[i][j] == -1) {
                matrix[i][j] = 1e8; // Use a large number to represent infinity for non-existing edges.
            }
        }
    }

    // Update distances based on the Floyd-Warshall algorithm.
    for (int viaNode = 0; viaNode < vertices; viaNode++) {
        for (int node1 = 0; node1 < vertices; node1++) {
            for (int node2 = 0; node2 < vertices; node2++) {
                if (matrix[node1][viaNode] < 1e8 && matrix[viaNode][node2] < 1e8) {
                    // Update the distance only if the path via 'viaNode' is better.
                    matrix[node1][node2] = min(matrix[node1][node2], matrix[node1][viaNode] + matrix[viaNode][node2]);
                }
            }
        }
    }
    
    // Check for negative cycles.
    for (int node = 0; node < vertices; node++) {
        if (matrix[node][node] < 0) {
            negativeCycle = true; // A negative value on the diagonal indicates a negative cycle.
            return;
        }
    }

    // Convert all large numbers back to -1 to indicate no path exists.
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (matrix[i][j] == 1e8) {
                matrix[i][j] = -1;
            }
        }
    }
}

int main() {
    int vertices = 4;  // Number of vertices in the graph.
    bool negativeCycle = false;  // Flag to check for negative cycles.
    vector<vector<int>> matrix(vertices, vector<int>(vertices, -1));  // Distance matrix initialization.

    // Assign weights to edges in the graph.
    matrix[0][1] = 2;
    matrix[1][0] = 1;
    matrix[1][2] = 3;
    matrix[3][0] = 3;
    matrix[3][1] = 5;
    matrix[3][2] = 4;

    // Run the Floyd-Warshall algorithm.
    floyd_warshall(vertices, matrix, negativeCycle);

    // Output the result.
    if (negativeCycle) {
        cout << "Negative Cycle found" << endl;
    }

    // Print the shortest paths matrix.
    for (auto row : matrix) {
        for (auto cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}

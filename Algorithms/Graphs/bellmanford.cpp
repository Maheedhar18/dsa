#include <bits/stdc++.h>
using namespace std;

// Bellman-Ford algorithm to find the shortest path from a single source 
// Time Complexity: O(V*E), where V = no. of vertices and E = no. of Edges.
// Space Complexity: O(V) for the distance array which stores the minimized distances.


vector<int> bellman_ford(int vertices, vector<vector<int>>& edges, int source) {
    // Initialize the distance to all vertices as a large value, except the source which is 0
    vector<int> distance(vertices, 1e8);
    distance[source] = 0;

    // Relax all edges 'vertices-1' times to ensure the shortest path
    for (int i = 0; i < vertices - 1; i++) {
        for (auto edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            int weight = edge[2];

            // If a shorter path to node2 is found, update its distance
            if (distance[node1] != 1e8 && distance[node1] + weight < distance[node2]) {
                distance[node2] = distance[node1] + weight;
            }
        }
    }

    // Check for negative weight cycles in the graph
    for (auto edge : edges) {
        int node1 = edge[0];
        int node2 = edge[1];
        int weight = edge[2];

        // If a shorter path is still found, it means there is a negative weight cycle
        if (distance[node1] != 1e8 && distance[node1] + weight < distance[node2]) {
            return {-1}; // Return -1 indicating the presence of a negative weight cycle
        }
    }

    // Return the shortest distances from the source to all vertices
    return distance;
}

int main() {
    // Number of vertices and edges definition
    int vertices = 6;
    vector<vector<int>> edges(7, vector<int>(3));
    
    // Edges defined as {from, to, weight}
    edges[0] = {3, 2, 6};
    edges[1] = {5, 3, 1};
    edges[2] = {0, 1, 5};
    edges[3] = {1, 5, -3};
    edges[4] = {1, 2, -2};
    edges[5] = {3, 4, -2};
    edges[6] = {2, 4, 3};

    // Source vertex from which to find shortest paths
    int source = 0;
    
    // Calculate shortest paths using Bellman-Ford algorithm
    vector<int> dist = bellman_ford(vertices, edges, source);
    
    // Print out distances to all vertices from the source
    for (auto d : dist) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}

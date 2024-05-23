#include <bits/stdc++.h>
using namespace std;

// Dijkstra's algorithm
// Time Complexity: O( E log(V) ), Where E = Number of edges and V = Number of Nodes.
// Space Complexity: O( |E| + |V| ), Where E = Number of edges and V = Number of Nodes.

vector<int> dijkstra(int vertices, vector<vector<int>> adjacencyList[], int source)
{
    // Priority queue to pick the vertex with the smallest distance efficiently.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> priorityQueue;
    
    // Distance vector, initially set to a large number (1e9 here acts as infinity).
    vector<int> distance(vertices, 1e9);
    
    // Set the source vertex's distance to 0.
    distance[source] = 0;
    
    // Push the source into the priority queue.
    priorityQueue.push({0, source});
    
    // Process nodes until the priority queue is empty.
    while(!priorityQueue.empty()) {
        int currentDistance = priorityQueue.top().first;  // Distance of the current node from the source.
        int node = priorityQueue.top().second;           // Current node.
        priorityQueue.pop();                             // Remove the top element from the queue.

        // Explore each adjacent vertex of the current node.
        for(auto iterator:adjacencyList[node]) {
            int adjacentNode = iterator[0];  // Adjacent vertex.
            int weight = iterator[1];        // Weight of the edge to the adjacent vertex.

            // Relaxation step: Check if a shorter path to the adjacent node is found.
            if(currentDistance + weight < distance[adjacentNode]) {
                distance[adjacentNode] = currentDistance + weight;
                // Push the updated distance and vertex into the queue.
                priorityQueue.push({distance[adjacentNode], adjacentNode});
            }
        }
    }
    return distance; // Return the computed shortest distances from the source to all vertices.
}

int main()
{
    // Driver code to demonstrate the usage of the dijkstra function.
    int vertices = 3, source = 2; // Number of vertices in the graph and the source vertex.
    vector<vector<int>> adjacencyList[vertices]; 

    // Creating the graph by adding edges.
    adjacencyList[0].push_back({1, 1}); 
    adjacencyList[0].push_back({2, 6}); 
    adjacencyList[1].push_back({2, 3}); 
    adjacencyList[1].push_back({0, 1}); 
    adjacencyList[2].push_back({1, 3}); 
    adjacencyList[2].push_back({0, 6}); 

    // Running Dijkstra's algorithm.
    vector<int> res = dijkstra(vertices, adjacencyList, source);

    // Output the shortest distances from the source to all vertices.
    for (int i = 0; i < vertices; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}

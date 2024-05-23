#include<bits/stdc++.h>
using namespace std;

// Using DFS to detect cycle in a Directed Graph
// Time Complexity: O(V+E)+O(V) , where V = no. of nodes and E = no. of edges. There can be at most V components. So, another O(V) time complexity.
// Space Complexity: O(2N) + O(N) ~ O(2N): O(2N) for two visited arrays and O(N) for recursive stack space.
class Solution {
private:
    // DFS traversal to check for cycles in the graph.
	bool dfsCheck(int node, vector<int> adjacencyList[], int visited[], int pathVisited[]) {
        visited[node] = 1; // Mark the current node as visited
        pathVisited[node] = 1; // Mark the current node as visited on the current path
        // Explore all adjacent nodes
        for(auto adjacentNode : adjacencyList[node]) {
            if(!visited[adjacentNode]) { // If the adjacent node has not been visited
                if(dfsCheck(adjacentNode, adjacencyList, visited, pathVisited)) {
                    return true; // Cycle found in the recursion stack
                }
            }
            else if(pathVisited[adjacentNode]) { // If the adjacent node is visited but it has to be visited on the same path
                return true; // A cycle is detected
            }
        }
        pathVisited[node] = 0; // Unmark the node from the current path
        return false;
	}

public:
	// Function to detect cycle in a directed graph using DFS.
	bool isCyclic(int vertices, vector<int> adjacencyList[]) {
        int visited[vertices] = {0}; // Array to keep track of visited nodes
        int pathVisited[vertices] = {0}; // Array to keep track of nodes visited in the current DFS path

        // Iterate over all vertices to handle disconnected components
        for(int i=0;i<vertices;i++) {
            if(!visited[i]) { // If the vertex is not visited
                if(dfsCheck(i, adjacencyList, visited, pathVisited)) return true; // Start a DFS from the vertex and returning true if a cycle is found
            }
        }
        return false; // No cycle found in the graph
    }
};


// Detecting a cycle using Topological Sort
// Time Complexity: O(V+E), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm.
// Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the in-degree array, and O(N) for the queue data structure used in BFS(where N = no.of nodes).
bool topoSortBFS(int vertices, vector<int> adjacencyList[])
{
    int inDegree[vertices] = {0}; // Array to store in-degree of each node.
    for(int node=0; node<vertices; node++) {
        for(auto adjacentNode : adjacencyList[node]) {
            inDegree[adjacentNode]++; // Calculate in-degree for each node.
        }
    }
    queue<int> queue; // Queue to manage nodes with in-degree zero.
    for(int node=0; node<vertices; node++) {
        if(inDegree[node] == 0) queue.push(node); // Enqueue nodes with zero in-degree.
    }
    vector<int> topoSortedVector; // Vector to store the topological sort result.
    while(!queue.empty()) {
        int node = queue.front();
        topoSortedVector.push_back(node); // Add node to result vector.
        queue.pop();
        for(auto adjacentNode : adjacencyList[node]) {
            inDegree[adjacentNode]--; // Reduce the in-degree of adjacent nodes.
            if(inDegree[adjacentNode] == 0) {
                queue.push(adjacentNode); // Enqueue if in-degree becomes zero.
            }
        }
    }
    // if there is no cycle then the topologically sorted vector should contain all nodes.
    if(topoSortedVector.size()==vertices) return false;
    return true;
}

int main() {

	std::vector<int> adjacencyList[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
	int vertices = 11; 

    Solution obj;
	bool ans = obj.isCyclic(vertices, adjacencyList);
    cout<< "Using DFS : ";
	if (ans)
		cout << "True\n"; // Graph contains a cycle
	else
		cout << "False\n"; // Graph does not contain a cycle
    cout<< "Using Topological Sort : ";
    ans = topoSortBFS(vertices, adjacencyList);
    if (ans)
		cout << "True\n"; // Graph contains a cycle
	else
		cout << "False\n"; // Graph does not contain a cycle
	return 0;
}

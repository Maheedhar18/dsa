#include <bits/stdc++.h>
using namespace std;

// Topological Sort Algorithm - In Directed Acyclic Graph, node u will always appear before node v if there is a directed edge from node u towards node v(u -> v).

// Function to perform Topological Sort using Kahn's Algorithm (BFS approach).
// Time Complexity: O(V+E), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm.
// Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the indegree array, and O(N) for the queue data structure used in BFS(where N = no.of nodes).
vector<int> topoSortBFS(int vertices, vector<int> adjacencyList[])
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
    return topoSortedVector;
}


// Class to perform Topological Sort using Depth First Search (DFS) approach on Directed Acyclic Graphs (DAG).
// Time Complexity: O(V+E)+O(V), where V = no. of nodes and E = no. of edges. There can be at most V components. So, another O(V) time complexity.
// Space Complexity: O(2N) + O(N) ~ O(2N): O(2N) for the visited array and the stack carried during DFS calls and O(N) for recursive stack space, where N = no. of nodes.
class TopoSortDFS {
private:
    void dfs(int node, int visited[], stack<int> &stack, vector<int> adjacencyList[]) {
        visited[node] = 1;
        for(auto adjacentNode : adjacencyList[node]) {
            if(!visited[adjacentNode]) {
                dfs(adjacentNode, visited, stack, adjacencyList);
            }
        }
        stack.push(node); // Add node to stack after visiting all adjacent nodes.
    }

public:
    vector<int> topoSort(int vertices, vector<int> adjacencyList[])
    {
        int visited[vertices] = {0}; // Initialize visited array with 0.
        stack<int> stack; // Stack to store the topological order.
        for(int i=0; i<vertices; i++) {
            if(!visited[i]) {
                dfs(i, visited, stack, adjacencyList); // Perform DFS if node is not visited.
            }
        }
        vector<int> topoSortedVector; // Vector to store the topological sort result.
        while(!stack.empty()) {
            topoSortedVector.push_back(stack.top()); // Pop from stack to get next node in topological order.
            stack.pop();
        }
        return topoSortedVector;
    }
};



int main() {
    vector<int> adjacencyList[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    int vertices = 6; // Number of vertices in the graph.
    TopoSortDFS obj;
    vector<int> ans1 = obj.topoSort(vertices, adjacencyList); // Perform topological sort using DFS.
    cout << "Using DFS: ";
    for (auto node : ans1) {
        cout << node << " "; // Output topologically sorted order from DFS.
    }
    cout << endl << "Using BFS: ";
    vector<int> ans2 = topoSortBFS(vertices, adjacencyList); // Perform topological sort using BFS.
    for (auto node : ans2) {
        cout << node << " "; // Output topologically sorted order from BFS.
    }
    return 0;
}

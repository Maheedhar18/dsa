#include <bits/stdc++.h>
using namespace std;

// Depth First Search Algorithm
// Time Complexity: O(V+E), Where V = vertices, E = edges.
// Space Complexity: O(N), Space for dfs stack space, visited array.


void dfsOfGraph(int node, vector<int> adjacencyList[], vector<int> visited, vector<int> &dfs) {
        visited[node] = 1; 
        dfs.push_back(node); 
        // traverse all its neighbours
        for(auto it : adjacencyList[node]) {
            // if the neighbour is not visited
            if(!visited[it]) {
                dfsOfGraph(it, adjacencyList, visited, dfs); 
            }
        }
    }



void addEdge(vector<int> adjacencyList[], int u, int v) {
    adjacencyList[u].push_back(v);
    adjacencyList[v].push_back(u);
}

void printAns(vector <int> &answer) {
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
}

int main() 
{
    vector<int> adjacencyList[6];
    
    addEdge(adjacencyList, 0, 1);
    addEdge(adjacencyList, 1, 2);
    addEdge(adjacencyList, 1, 3);
    addEdge(adjacencyList, 0, 4);

    //dfs starts
    int vertices = 6;
    //create a visited vector to store visited nodes
    vector<int> visited(vertices, 0);
    int start = 0;
    // create a list to store dfs
    vector<int> dfs; 
    // call dfs for starting node
    dfsOfGraph(start, adjacencyList, visited, dfs); 
    printAns(dfs);

    return 0;
}
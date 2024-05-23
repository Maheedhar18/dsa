#include <bits/stdc++.h>
using namespace std;


// Breadth First Search Algorithm
// Time Complexity: O(V+E), Where V = vertices, E = edges.
// Space Complexity: O(N), Space for queue data structure visited array



vector<int> bfsOfGraph(int vertices, vector<int> adjacencyList[]) {
    vector<int> visited(vertices, 0);
    visited[0] = 1; 
    queue<int> queue;
    // push the initial starting node 
    queue.push(0); 
    vector<int> bfs; 
    // iterate till the queue is empty 
    while(!queue.empty()) {
       // get the topmost element in the queue 
        int node = queue.front(); 
        queue.pop(); 
        bfs.push_back(node); 
        // traverse for all its neighbours 
        for(auto it : adjacencyList[node]) {
            // if the neighbour has previously not been visited, 
            // store in Q and mark as visited 
            if(!visited[it]) {
                visited[it] = 1; 
                queue.push(it); 
            }
        }
    }
    return bfs; 
}

void addEdge(vector <int> adjacencyList[], int u, int v) {
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

    vector<int> answer = bfsOfGraph(5, adjacencyList);
    printAns(answer);

    return 0;
}

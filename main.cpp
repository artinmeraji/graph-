#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

// Simple Graph class to hold our adjacency list
class Graph {
public:
    map<char, vector<char>> adjList;

    // Function to add an edge
    void addEdge(char u, char v) {
        adjList[u].push_back(v);
    }

    // Depth-First Search using recursion
    void DFS(char startNode, set<char>& visited) {
        // Mark the current node as visited and print it
        visited.insert(startNode);
        cout << startNode << " ";

        // Go through all the neighbors
        for (char neighbor : adjList[startNode]) {
            if (visited.find(neighbor) == visited.end()) {
                DFS(neighbor, visited);
            }
        }
    }

    // Breadth-First Search using a queue
    void BFS(char startNode) {
        set<char> visited;
        queue<char> q;

        // Start with the first node
        visited.insert(startNode);
        q.push(startNode);

        while (!q.empty()) {
            char currentNode = q.front();
            q.pop();
            cout << currentNode << " ";

            // Check all neighbors of the current node
            for (char neighbor : adjList[currentNode]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    Graph g;

    // Building the graph from my theoretical design
    // A connects to B and C
    g.addEdge('A', 'B');
    g.addEdge('A', 'C');
    // B connects to D and E
    g.addEdge('B', 'D');
    g.addEdge('B', 'E');
    // C connects to F
    g.addEdge('C', 'F');

    cout << "--- Graph Traversal Assignment ---" << endl;

    cout << "Starting DFS from node A: ";
    set<char> visitedDFS;
    g.DFS('A', visitedDFS);
    cout << endl;

    cout << "Starting BFS from node A: ";
    g.BFS('A');
    cout << endl;

    return 0;
}

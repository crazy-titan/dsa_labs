#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adj;   // adjacency list

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);   // remove this line if graph is directed
    }

    void DFSUtil(int node, vector<bool> &visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "DFS Traversal starting from node " << start << ": ";
        DFSUtil(start, visited);
        cout << endl;
    }
};

int main() {
    Graph g(6);  // number of vertices

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    g.DFS(0);   // start from node 0

    return 0;
}

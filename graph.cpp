#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void addEdge(vector<vector<int>>& graph, int u, int v) {
    graph[u].push_back(v); // Adding v to u's adjacency list
    graph[v].push_back(u); // Adding u to v's adjacency list for undirected graph
}

void dfs_pre(vector<vector<int>>& graph, int v, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (int n : graph[v]) {
        if (!visited[n])
            dfs_pre(graph, n, visited);
    }
}

void dfs_post(vector<vector<int>>& graph, int v, vector<bool>& visited) {
    visited[v] = true;

    for (int n : graph[v]) {
        if (!visited[n])
            dfs_post(graph, n, visited);
    }
    cout << v << " ";
}

void dfs_iter(vector<vector<int>>& graph, int v) {
    vector<bool> visited(5, false);
    stack<int> to_visit;

    to_visit.push(v);

    while(!to_visit.empty()) {
        v = to_visit.top();
        to_visit.pop();

        if (!visited[v]) {
            cout << v << " ";
            visited[v] = true;

            for (int n : graph[v]) {
                if (!visited[n])
                    to_visit.push(n);
            }
        }
    }
}

void bfs(vector<vector<int>>& graph, int v) {
    queue<int> to_visit;
    vector<bool> visited(5, false);

    to_visit.push(v);

    while(!to_visit.empty()) {
        v = to_visit.front();
        to_visit.pop();
        if (!visited[v]) {
            cout << v << " ";
            visited[v] = true;

            for (int n : graph[v]) {
                if (!visited[n])
                    to_visit.push(n);
            }
        }
    }
}

int main(void) {
    unsigned int V = 5;

    vector<vector<int>> graph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 0);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    vector<bool> visited(V, false);

    cout << "dfs: ";
    dfs_pre(graph, 0, visited);
    cout << endl;
    
    cout << "bfs: ";
    bfs(graph, 0);
    cout << endl;
    
    return 0;
}
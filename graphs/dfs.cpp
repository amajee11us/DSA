#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*
Generate a Depth First Traversal of a graph
*/

class Graph{
    public:
        int V;
        vector<vector<int>> adj;

        vector<int> s; // stack to be used for DFS
        vector<bool> visited;

    Graph(int edge_count){
        V = edge_count;
        adj = vector<vector<int>>(V, vector<int>(V, 0));
        visited = vector<bool>(V, false);
    }

    void addEdge(int x, int y, int w = 1){
        adj[x][y] = w;
        adj[y][x] = w;
    }

    void getDfs(int start = 0){

        int curr = start;
        s.push_back(curr);

        while(!s.empty() && (find(visited.begin(), visited.end(), false)) != visited.end()){
            curr = s[s.size() - 1];
            visited[curr] = true;
            s.erase(s.end() - 1);

            cout << curr << " ";

            for(int i = 0; i < adj[curr].size(); i++){
                if(adj[curr][i] >= 1 && !visited[i])
                    s.push_back(i);
            }
        }
    }
};

int main(){

    int V = 4;

    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(1, 3);
    g.addEdge(0, 2);

    g.getDfs();

    return 0;
}
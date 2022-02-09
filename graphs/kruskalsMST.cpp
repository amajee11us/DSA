#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/* Kruskal's MST algorithm */

class Graph{
    public:
        int V;
        vector<vector<int>> adj;

        // Create an edge list
        map<int, pair<int, int>> edgeList;
        vector<int> parent;

    Graph(int edge_count){
        V = edge_count;
        adj = vector<vector<int>>(V, vector<int>(V, 0));

        parent = vector<int>(V, 0);
        for(int i = 0; i < V; i++){
            parent[i] = i;
        }
    }

    void addEdge(int x, int y, int w = 1){
        adj[x][y] = w;
        adj[y][x] = w;

        addToEdgeList(x, y, w);
    }

    void addToEdgeList(int src, int dest, int wt){
        pair<int, int> edge(src, dest);

        edgeList.insert({wt, edge});
    }

    // Method to find out the topmost parent of a given edge.
    int findParent(int edge){
        if(parent[edge] == edge)
            return parent[edge];
        else
            return findParent(parent[edge]);
    }

    void updateParent(int src, int dst){
        int src_parent = findParent(src);
        int dst_parent = findParent(dst);

        parent[src_parent] = dst_parent;
    }

    unordered_map<int, pair<int, int>> generateMST(int start = 0){
        /*
        Here in this case we have considered a map - ordered
        Thus the entries are already sorted based on the key (here weight)
        */
        unordered_map<int, pair<int, int>> MST;

        for(auto it = edgeList.begin(); it != edgeList.end(); it++){
            int src =  it->second.first;
            int dest = it->second.second;
            if(findParent(src) != findParent(dest)){
                // We have found a valid edge to add to MST
                MST.insert({it->first, {src, dest}});
            }
            updateParent(src, dest);
        }
        return MST;
    }

    void displayMST(unordered_map<int, pair<int, int>> MST){
        for(auto it = MST.begin(); it != MST.end(); it++){
            cout << it->first << "  (" << it->second.first << " , " << it->second.second << ")" << endl;
        }
    }

    void displayGraph(){
        for(int i=0; i < V; i++){
            for(int j = 0; j < V; j++)
                cout << adj[i][j] << "\t";
            cout << endl;
        }
    }
};

int main(){
    // driver code
    Graph g(5);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    g.displayGraph();

    unordered_map<int, pair<int, int>> MST = g.generateMST();

    g.displayMST(MST);

    return 0;
}
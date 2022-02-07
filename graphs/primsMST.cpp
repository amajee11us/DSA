#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/* Prim's MST algorithm */

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

    vector<int> generateMST(int start = 0){
        // store parent edges for the vertices added into the MST
        vector<int> parent = vector<int>(V, -1);

        // Weights of each vertex calculated dynamically 
        vector<int> key = vector<int>(V, INT_MAX);

        // Edges included in the MST
        vector<bool> mstSet = vector<bool>(V, false);

        key[start] = 0; // initialize the weight of the starting node
        parent[start] = -1; // no parent for the 1st node

        int v;
        while(find(mstSet.begin(), mstSet.end(), false) != mstSet.end()){
            // v ane e form an edge so lets pick valid edges
            v = minElement(key, mstSet);

            // add to MST
            mstSet[v] = true;
            
            for(int e = 0; e < V; e++){
                if(adj[v][e] >= 1 && mstSet[e] == false && adj[v][e] < key[e]){
                    parent[e] = v;
                    key[e] = adj[v][e];
                }
            }
        }

        return parent;
    }

    int minElement(vector<int> key, vector<bool> visited){
        int minKey = INT_MAX;
        int minV = -1;
        for(int i = 0; i < V; i++){
            if(key[i] < minKey && !visited[i]){
                minKey = key[i];
                minV = i;
            } 
        }
        return minV;
    }

    void displayMST(vector<int> parent){
        for(int v = 0; v < V; v++){
            cout << parent[v] << "\t-\t" << v << " -->\t" << adj[v][parent[v]] << endl;
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

    vector<int> MST = g.generateMST();

    g.displayMST(MST);

    return 0;
}
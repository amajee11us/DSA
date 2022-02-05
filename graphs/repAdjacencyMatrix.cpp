#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*
Print the adjacency matrix for a given graph.
*/

class Graph{
    public:
        int V; // edge count in the graph
        vector<vector<int>> adj; // adjacency matrix

    Graph(int edge){
        try{
            V = edge;
            if(V > INT_MAX)
                throw (edge);  
        }
        catch(int edge_count){
            cout << "Invalid edge count > 10, found " << edge_count << endl;
        }

        // create the graph - V x V matrix
        adj = vector<vector<int>>(V, vector<int> (V,0));
    }

    void createEdge(int x, int y, int w = 1){
        adj[x][y] = w;
        adj[y][x] = w;
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
    //driver program

    Graph g(5);

    g.createEdge(0, 1, 2);
    g.createEdge(1, 2, 3);
    g.createEdge(0, 3, 6);
    g.createEdge(1, 3, 8);
    g.createEdge(1, 4, 5);
    g.createEdge(2, 4, 7);
    g.createEdge(3, 4, 9);

    g.displayGraph();

    return 0;
}
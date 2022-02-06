#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*
Program to perform Breadth First Search (BFS) in a graph.
*/

class Graph{
    public:
        int V; // edge count in the graph
        vector<vector<int>> adj; // adjacency matrix
        vector<bool> visited;
        // BFS uses a queue
        vector<int> q; // keep track of edges during search operation

    Graph(int edge){
        try{
            V = edge;
            if(V > INT_MAX)
                throw (edge);  
        }
        catch(int edge_count){
            cout << "Invalid edge count > INT_MAX, found " << edge_count << endl;
        }

        // create the graph - V x V matrix
        adj = vector<vector<int>>(V, vector<int> (V,0));
        visited = vector<bool>(V, false);
    }

    vector<int> getBfs(int start_edge = 0){
        vector<int> searchPath;

        q.push_back(start_edge); // add the start edge
        visited[start_edge] = true; 

        int curr;
        while(!q.empty()){
            searchPath.push_back(q[0]);
            curr = q[0];
            q.erase(q.begin());

            for(int i =0; i < adj[curr].size(); i++){
                if(adj[curr][i] >= 1 && (!visited[i])){
                    q.push_back(i);
                    //immediately visit all the adjacent nodes
                    visited[i] = true;
                }
            }
        }
        return searchPath;
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

    vector<int> search = g.getBfs();

    for(int i =0; i < search.size(); i++)
        cout << search[i] << " ";
    cout << endl;

    return 0;
}
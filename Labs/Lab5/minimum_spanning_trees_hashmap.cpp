#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define edge pair<int, int>

class Graph {
    private:
        // graph is stored as a vector of pairs, where each pair takes the form: <weight, edge>
        vector<pair<int, edge> > G;  // graph 
        vector<pair<int, edge> > T;  // minimum spanning tree for the graph G
        int *parent; // to set parents for Union Find algorithm
        int V;  // number of vertices/nodes in graph
    public:
        Graph(int V);
        void addWeightedEdge(int u, int v, int w);
        int findSet(int vertice);
        void findMSTKruskal();
        void printMST();
};

Graph::Graph(int V) {
    parent = new int[V];

    // set parent to self initially 
    //i           0 1 2 3 4 5 ...
    //parent[i]   0 1 2 3 4 5 ...
    for (int i = 0; i < V; i++)
        parent[i] = i;

    G.clear();
    T.clear();
}

void Graph::addWeightedEdge(int u, int v, int w) {
  G.push_back(make_pair(w, edge(u, v)));
}

//find the set which the vertice belongs to
int Graph::findSet(int vertice){
    if (vertice == parent[vertice]){
        return vertice;
    } else{
        return findSet(parent[vertice]);
    }
}


// updates T to the minimum spanning tree using Kruskal's algorithm
void Graph::findMSTKruskal() { 
    sort(G.begin(), G.end()); //sort in increasing weight
    
    for (long unsigned int i = 0; i < G.size(); i++){
        //if v don't form a cycle with u add edge to MST
        int u = G[i].second.first;
        int v = G[i].second.second;
        
        if (findSet(u) != findSet(v)) {
            T.push_back(G[i]); // add to MST
            parent[findSet(u)] = parent[findSet(v)]; //update parent of the source
        }
    }
}

void Graph::printMST() {
    int minCost = 0;
    cout << "Edge : " << "Weight" << endl;
    for (long unsigned int i = 0; i < T.size(); i++) {
        cout << T[i].second.first << " - " << T[i].second.second << " : " << T[i].first << endl;
        minCost += T[i].first;
    }
    cout << "Minimum Cost = " << minCost << endl;
}

int main() {
    int numVertices;
    cin >> numVertices;

    Graph g(numVertices);
    
    int u, v, w;
    cin >> u;
    while (u != -1) {
        cin >> v >> w;
        g.addWeightedEdge(u, v, w);
        cin >> u;
    }
 
    g.findMSTKruskal();
    g.printMST();
    return 0;
}
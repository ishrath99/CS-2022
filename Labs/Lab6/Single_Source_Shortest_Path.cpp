#include <iostream>

using namespace std;

#define INF 100000

// Struct for the edges of the graph
struct Edge {
    int u;  // source vertex of the edge
    int v;  // destination vertex of the edge
    int w;  // weight of the edge
};

// Graph 
struct Graph {
    int V;        // Total number of vertices in the graph
    int E;        // Total number of edges in the graph
    struct Edge* edge;  // Array of edges
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = new Graph;
    graph->V = V;  // Total Vertices
    graph->E = E;  // Total edges

    // Array of edges for graph
    graph->edge = new Edge[E];
    return graph;
}
 //relaxation
void relax(int u, int v, int w, int dist[]){
    if (dist[v] > dist[u] + w){
        dist[v] = dist[u] + w;
    }
}

void BellmanFord(struct Graph* graph, int u, int dist[]) {
    //initialize distances
    dist[0] = 0;
    for (int i = 1; i < graph->V; i++){
        dist[i] = INF;
    }
    
    //run V-1 times
    for (int i = 1; i < graph->V; i++){
        //relax each edges
        for (int j = 0; j < graph->E; j++){
            relax(graph->edge[j].u, graph->edge[j].v, graph->edge[j].w, dist);
        }
    }

}

// Printing the solution
void printSSSP(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
    int V; // Total vertices
    int E; // Total edges
    std::cin >> V >> E;

    struct Graph* graph = createGraph(V, E);

    int u, v, w;
    for (int i=0; i<E; i++) {
        cin >> u >> v >> w;
        graph->edge[i].u = u;
        graph->edge[i].v = v;
        graph->edge[i].w = w;
    }

    int dist[V];
    
    BellmanFord(graph, 0, dist);  //0 is the source vertex

    printSSSP(dist, V);

    return 0;
}
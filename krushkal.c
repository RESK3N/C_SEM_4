#include <stdio.h>
#include <stdlib.h>

#define V 5 // Number of vertices

// Structure to represent an edge
typedef struct {
    int src, dest, weight;
} Edge;

// Structure to represent a graph
typedef struct {
    int numEdges;
    Edge* edges;
} Graph;

// Structure to represent a subset for Union-Find
typedef struct {
    int parent;
    int rank;
} Subset;

// Function to find set of an element using path compression
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform Union of two sets using rank
void unionSets(Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank) {
        subsets[rootX].parent = rootY;
    } else if (subsets[rootX].rank > subsets[rootY].rank) {
        subsets[rootY].parent = rootX;
    } else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Comparison function for sorting edges by weight
int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

// Function to implement Kruskal's Algorithm
void kruskalMST(Graph* graph) {
    int numVertices = V;
    Edge result[V]; // Store the resultant MST
    int e = 0; // Index for result[]
    int i = 0; // Index for sorted edges

    // Step 1: Sort all edges in increasing order of weight
    qsort(graph->edges, graph->numEdges, sizeof(Edge), compareEdges);

    // Step 2: Allocate memory for subsets and initialize them
    Subset* subsets = (Subset*)malloc(numVertices * sizeof(Subset));
    for (int v = 0; v < numVertices; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Step 3: Pick the smallest edge and check for cycles
    while (e < numVertices - 1 && i < graph->numEdges) {
        Edge nextEdge = graph->edges[i++];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // If adding this edge does not form a cycle, include it in result[]
        if (x != y) {
            result[e++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    // Print the MST
    printf("Edge \tWeight\n");
    for (i = 0; i < e; i++)
        printf("%d - %d \t%d\n", result[i].src, result[i].dest, result[i].weight);

    free(subsets);
}

// Driver code
int main() {
    Graph graph;
    graph.numEdges = 7;

    // Example edges (Graph with 5 vertices and 7 edges)
    Edge edges[] = {
            {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8},
            {1, 4, 5}, {2, 4, 7}, {3, 4, 9}
    };

    graph.edges = edges;

    // Run Kruskal's Algorithm
    kruskalMST(&graph);

    return 0;
}

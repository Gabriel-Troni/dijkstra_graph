#include <stdio.h>
#include <limits.h>

#define V 5

int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;
    
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    
    return min_index;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        return;
    }
    printPath(parent, parent[j]);
    printf("%c ", j + 'A');
}

void dijkstra(int graph[V][V], int start) {
    int dist[V]; 
    int sptSet[V];  
    int parent[V]; 

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
        parent[i] = -1;
    }
    
    dist[start] = 0;
    
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;
        
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("Caminho e distâncias mínimas de A até as outras cidades:\n");
    for (int i = 0; i < V; i++) {
        printf("Distância de A até %c: %d horas\n", i + 'A', dist[i]);
        printf("Caminho: A ");
        printPath(parent, i);
        printf("\n");
    }

    printf("\nMenor tempo para chegar de A até E: %d horas\n", dist[4]);
    printf("Caminho de A até E: A ");
    printPath(parent, 4);
    printf("\n");

    printf("\nMenor tempo para chegar de A até D: %d horas\n", dist[3]);
    printf("Caminho de A até D: A ");
    printPath(parent, 3);
    printf("\n");
}

int main() {
    int graph[V][V] = {
        {0, 4, 2, 7, 0},
        {4, 0, 1, 0, 1},
        {2, 1, 0, 3, 3},
        {7, 0, 3, 0, 2},
        {0, 1, 3, 2, 0}
    };

    dijkstra(graph, 0);
    
    return 0;
}
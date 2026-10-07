#include <stdio.h>
#include "display.h"

void display_matrix(const Graph *g) {
    printf("\n================ ADJACENCY MATRIX ================\n");
    printf("%-4s", "");
    for (int i = 0; i < g->n; ++i) printf("%-10d", i + 1);
    printf("\n");
    for (int i = 0; i < g->n; ++i) {
        printf("%-4d", i + 1);
        for (int j = 0; j < g->n; ++j) {
            if (g->adj[i][j] == INF) printf("%-10s", "INF");
            else printf("%-10d", g->adj[i][j]);
        }
        printf("\n");
    }
}

void display_distances(const Graph *g, int source, const int dist[]) {
    printf("\n=========== SHORTEST DISTANCES ===========\n");
    printf("Source: %s\n\n", g->name[source]);
    printf("%-28s %s\n", "Destination", "Shortest Distance");
    printf("-------------------------------------------\n");
    for (int i = 0; i < g->n; ++i) {
        if (dist[i] == INF) printf("%-28s %s\n", g->name[i], "INF");
        else printf("%-28s %d\n", g->name[i], dist[i]);
    }
}

static void print_path(const Graph *g, int v, const int parent[]) {
    if (parent[v] == -1) {
        printf("%s", g->name[v]);
        return;
    }
    print_path(g, parent[v], parent);
    printf(" -> %s", g->name[v]);
}

void display_paths(const Graph *g, int source, const int dist[], const int parent[]) {
    printf("\n================ SHORTEST PATHS ================\n");
    printf("%-24s %-18s %s\n", "Destination", "Distance", "Shortest Path");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < g->n; ++i) {
        printf("%-24s ", g->name[i]);
        if (dist[i] == INF) printf("%-18s No path\n", "INF");
        else {
            printf("%-18d ", dist[i]);
            print_path(g, i, parent);
            printf("\n");
        }
    }
}

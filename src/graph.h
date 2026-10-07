#ifndef GRAPH_H
#define GRAPH_H

#define MAX_VERTICES 50
#define MAX_NAME_LEN 80
#define INF 1000000000

typedef struct {
    int n;
    char name[MAX_VERTICES][MAX_NAME_LEN];
    int adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

#endif

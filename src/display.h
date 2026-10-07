#ifndef DISPLAY_H
#define DISPLAY_H

#include "graph.h"

void display_matrix(const Graph *g);
void display_distances(const Graph *g, int source, const int dist[]);
void display_paths(const Graph *g, int source, const int dist[], const int parent[]);

#endif

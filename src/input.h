#ifndef INPUT_H
#define INPUT_H

#include "graph.h"

int read_int(const char *prompt, int min_value, int max_value);
void read_name(const char *prompt, char *buffer, int size);
void enter_graph(Graph *g);
int select_source(const Graph *g);

#endif

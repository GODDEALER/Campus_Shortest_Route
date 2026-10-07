#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

int read_int(const char *prompt, int min_value, int max_value) {
    char buf[128], *end;
    long v;
    for (;;) {
        printf("%s", prompt);
        if (!fgets(buf, sizeof(buf), stdin)) exit(EXIT_FAILURE);
        v = strtol(buf, &end, 10);
        while (*end == ' ' || *end == '\t') end++;
        if (end != buf && (*end == '\n' || *end == '\0') &&
            v >= min_value && v <= max_value)
            return (int)v;
        printf("Invalid input. Enter a value from %d to %d.\n", min_value, max_value);
    }
}

void read_name(const char *prompt, char *buffer, int size) {
    for (;;) {
        printf("%s", prompt);
        if (!fgets(buffer, size, stdin)) exit(EXIT_FAILURE);
        buffer[strcspn(buffer, "\n")] = '\0';
        if (buffer[0] != '\0') return;
        printf("Name cannot be empty.\n");
    }
}

void enter_graph(Graph *g) {
    g->n = read_int("Enter number of locations: ", 1, MAX_VERTICES);
    for (int i = 0; i < g->n; ++i) {
        char prompt[64];
        snprintf(prompt, sizeof(prompt), "Enter location %d name: ", i + 1);
        read_name(prompt, g->name[i], MAX_NAME_LEN);
    }

    for (int i = 0; i < g->n; ++i)
        for (int j = 0; j < g->n; ++j)
            g->adj[i][j] = (i == j) ? 0 : INF;

    printf("\nEnter road distances. Use 0 when there is no direct road.\n");
    for (int i = 0; i < g->n; ++i) {
        for (int j = i + 1; j < g->n; ++j) {
            char prompt[128];
            snprintf(prompt, sizeof(prompt), "Distance %s <-> %s (0=no road): ",
                     g->name[i], g->name[j]);
            int d = read_int(prompt, 0, INF - 1);
            if (d > 0) g->adj[i][j] = g->adj[j][i] = d;
        }
    }
}

int select_source(const Graph *g) {
    printf("\nAvailable locations:\n");
    for (int i = 0; i < g->n; ++i)
        printf("%d. %s\n", i + 1, g->name[i]);
    return read_int("Select source location: ", 1, g->n) - 1;
}

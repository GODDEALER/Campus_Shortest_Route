#include <stdio.h>
#include <string.h>
#include "graph.h"
#include "input.h"
#include "dijkstra.h"
#include "display.h"

int main(void) {
    Graph g = {0};
    int dist[MAX_VERTICES], parent[MAX_VERTICES];
    int source = -1, choice, ready = 0, calculated = 0;

    printf("====================================================\n");
    printf(" Campus Shortest Route Finder - Dijkstra's Algorithm\n");
    printf("====================================================\n");

    for (;;) {
        printf("\n================ MENU ================\n");
        printf("1. Enter Campus Graph\n");
        printf("2. Display Adjacency Matrix\n");
        printf("3. Select Source Location\n");
        printf("4. Find Shortest Distance\n");
        printf("5. Display Shortest Paths\n");
        printf("6. Display Distance from Source to All Locations\n");
        printf("7. Exit\n");

        choice = read_int("Enter your choice: ", 1, 7);

        if (choice == 1) {
            enter_graph(&g);
            source = -1;
            calculated = 0;
            ready = 1;
            printf("\nCampus graph entered successfully.\n");
        } else if (choice == 2) {
            if (!ready) printf("\nPlease enter the campus graph first.\n");
            else display_matrix(&g);
        } else if (choice == 3) {
            if (!ready) printf("\nPlease enter the campus graph first.\n");
            else {
                source = select_source(&g);
                calculated = 0;
                printf("Selected source: %s\n", g.name[source]);
            }
        } else if (choice == 4) {
            if (!ready) printf("\nPlease enter the campus graph first.\n");
            else if (source < 0) printf("\nPlease select a source location first.\n");
            else {
                dijkstra(&g, source, dist, parent);
                calculated = 1;
                display_distances(&g, source, dist);
            }
        } else if (choice == 5) {
            if (!calculated) printf("\nPlease enter the graph, select a source, and find shortest distances first.\n");
            else display_paths(&g, source, dist, parent);
        } else if (choice == 6) {
            if (!calculated) printf("\nPlease enter the graph, select a source, and find shortest distances first.\n");
            else display_distances(&g, source, dist);
        } else {
            printf("\nExiting program. Thank you!\n");
            break;
        }
    }
    return 0;
}

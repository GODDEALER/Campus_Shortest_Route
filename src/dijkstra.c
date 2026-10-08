#include "dijkstra.h"

void dijkstra(const Graph *g, int source, int dist[], int parent[])
{
    int visited[MAX_VERTICES] = {0};

    for (int i = 0; i < g->n; ++i)
    {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[source] = 0;

    for (int count = 0; count < g->n; ++count)
    {
        int u = -1;
        for (int i = 0; i < g->n; ++i)
            if (!visited[i] && dist[i] != INF && (u == -1 || dist[i] < dist[u]))
                u = i;

        if (u == -1)
            break;
        visited[u] = 1;

        for (int v = 0; v < g->n; ++v)
        {
            if (!visited[v] && g->adj[u][v] != INF &&
                dist[u] + g->adj[u][v] < dist[v])
            {
                dist[v] = dist[u] + g->adj[u][v];
                parent[v] = u;
            }
        }
    }
}

# PBLE 2 - Campus Shortest Route Finder – Dijkstra's Algorithm

This project implements the instructor-specified **Dijkstra's shortest-path algorithm** in C.

## Requirements covered
- Menu-driven program
- Campus locations
- Weighted graph
- Adjacency matrix
- Non-negative edge weights
- User-selected source
- Dijkstra shortest distances
- Parent/predecessor array
- Reconstructed shortest paths
- Distance from source to every location
- Time complexity

## Algorithm
Dijkstra repeatedly selects the unvisited vertex with the smallest known distance and relaxes all of its adjacent edges. The predecessor array reconstructs the final shortest paths.

## Complexity
With an adjacency matrix and linear minimum selection:
- Time: O(V²)
- Space: O(V²)

## Build
```text
gcc -std=c11 -Wall -Wextra -pedantic -O2 src/main.c src/input.c src/dijkstra.c src/display.c -o pble2.exe
```

Run:
```text
pble2.exe
```

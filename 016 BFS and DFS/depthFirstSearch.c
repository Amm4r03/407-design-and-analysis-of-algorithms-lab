#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Function prototypes
void DFS(int graph[][MAX_VERTICES], int start, int visited[], int n);

int main()
{
    int n, graph[MAX_VERTICES][MAX_VERTICES], i, j;
    int start;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix of the graph:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex for traversal: ");
    scanf("%d", &start);

    printf("\nDepth First Search (DFS) traversal: ");
    int visited[MAX_VERTICES] = {0};
    DFS(graph, start, visited, n);

    return 0;
}

// Function to perform Depth First Search (DFS)
void DFS(int graph[][MAX_VERTICES], int start, int visited[], int n)
{
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[start][i] && !visited[i])
        {
            DFS(graph, i, visited, n);
        }
    }
}
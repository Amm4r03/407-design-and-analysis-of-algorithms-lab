#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Queue structure for BFS
struct Queue
{
    int items[MAX_VERTICES];
    int front;
    int rear;
};

// Function prototypes
void enqueue(struct Queue *q, int value);
int dequeue(struct Queue *q);
int isEmpty(struct Queue *q);
void BFS(int graph[][MAX_VERTICES], int start, int n);
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

    printf("\nBreadth First Search (BFS) traversal: ");
    BFS(graph, start, n);

    printf("\nDepth First Search (DFS) traversal: ");
    int visited[MAX_VERTICES] = {0};
    DFS(graph, start, visited, n);

    return 0;
}

// Function to perform Breadth First Search (BFS)
void BFS(int graph[][MAX_VERTICES], int start, int n)
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;

    int visited[MAX_VERTICES] = {0};
    enqueue(q, start);
    visited[start] = 1;

    while (!isEmpty(q))
    {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        for (int i = 0; i < n; i++)
        {
            if (graph[currentVertex][i] && !visited[i])
            {
                enqueue(q, i);
                visited[i] = 1;
            }
        }
    }

    free(q);
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

// Function to add an element to the queue
void enqueue(struct Queue *q, int value)
{
    if (q->rear == MAX_VERTICES - 1)
        printf("Queue overflow\n");
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Function to remove an element from the queue
int dequeue(struct Queue *q)
{
    int item;
    if (isEmpty(q))
    {
        printf("Queue underflow\n");
        item = -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            q->front = q->rear = -1;
        }
    }
    return item;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *q)
{
    if (q->rear == -1)
        return 1;
    else
        return 0;
}
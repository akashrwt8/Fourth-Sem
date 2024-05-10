#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Graph
{
    int v, e;
    int **adj;
};

struct Graph *adjMatrix()
{
    int v, u;
    struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));
    if (g == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    printf("Enter number of vertices and edges respectively : ");
    scanf("%d %d", &g->v, &g->e);

    g->adj = (int **)malloc(sizeof(int *) * g->v);
    if (g->adj == NULL)
    {
        printf("Memory allocation failed\n");
        free(g);
        return NULL;
    }
    for (int i = 0; i < g->v; i++)
    {
        g->adj[i] = (int *)malloc(sizeof(int) * g->v);
    }

    // Initialize adjacency matrix to 0
    for (int i = 0; i < g->v; i++)
    {
        for (int j = 0; j < g->v; j++)
        {
            g->adj[i][j] = 0;
        }
    }

    printf("Enter pairs of nodes for each edge with weight: ");
    for (int i = 0; i < g->e; i++)
    {
        int weight;
        scanf("%d %d %d", &v, &u, &weight);
        g->adj[v][u] = weight;
        g->adj[u][v] = weight;
    }
    return g;
}

void printGraph(struct Graph *g)
{
    printf("Adjacency Matrix is\n");
    for (int i = 0; i < g->v; i++)
    {
        for (int j = 0; j < g->v; j++)
        {
            printf("%d\t", g->adj[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    struct Graph *g = adjMatrix();
    if (g != NULL)
    {
        printGraph(g);
        primsMST(g);
        // Free allocated memory
        for (int i = 0; i < g->v; i++)
        {
            free(g->adj[i]);
        }
        free(g->adj);
        free(g);
    }
    return 0;
}

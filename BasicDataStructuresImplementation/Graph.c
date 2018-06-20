#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;

typedef struct adjacency {
    int vertice;
    int time;
    struct adjacency *next;
} ADJACENCY;

typedef struct vertice {
    /* data goes here */

    ADJACENCY *head;
} VERTICE;

typedef struct graph {
    int vertices;
    int edges;
    VERTICE *adjadcencies;
} GRAPH;

GRAPH *newGraph(int numberOfVertices){
    GRAPH *g = (GRAPH *) malloc(sizeof(GRAPH));
    g->vertices = numberOfVertices;
    g->edges = 0;
    g->adjadcencies = (VERTICE *) malloc(numberOfVertices * sizeof(VERTICE));

    int i;
    for(i = 0; i < numberOfVertices; i++){
        g->adjadcencies[i].head = NULL;
    }
    
    return g;
}

int main(){

    return 1;
}
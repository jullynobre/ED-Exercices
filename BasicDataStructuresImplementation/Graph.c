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

ADJACENCY *newAdjacency(int vertice, int time){
    ADJACENCY *temp = (ADJACENCY *) malloc(sizeof(ADJACENCY));
    temp->vertice = vertice;
    temp->time = time;
    temp->next = NULL;
    return(temp);
}

//This method creates a directed edge
bool createEdge(GRAPH *gr, int v1, int v2, int time){
    if(!gr) return(false);
    if((v1 < 0) || (v1 >= gr->vertices)) return(false);
    if((v2 < 0) || (v2 >= gr->vertices)) return(false);

    ADJACENCY *new = newAdjacency(v2, time);
    new->next = gr->adjadcencies[v1].head;
    gr->adjadcencies[v1].head = new;
    gr->edges++;

    return(true);
}

void printGraph(GRAPH* gr){
    printf("Vertices: %d \nEdges: %d \n\n", gr->vertices, gr->edges);

    int i;
    for(i = 0; i < gr->vertices; i++){
        printf("v(%d): ", i);
        ADJACENCY *adj = gr->adjadcencies[i].head;
        while(adj){
            printf("v%d(%d) ", adj->vertice, adj->time);
            adj = adj->next;
        }
        printf("\n");
    }
}

int main(){
    GRAPH *gr = newGraph(5);
    createEdge(gr, 0, 1, 2);
    createEdge(gr, 1, 2, 4);
    createEdge(gr, 2, 0, 12);
    createEdge(gr, 2, 4, 40);
    createEdge(gr, 3, 1, 3);
    createEdge(gr, 4, 3, 8);

    printGraph(gr);

    return 1;
}
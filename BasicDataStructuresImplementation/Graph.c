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
    temp->vertice = v;
    temp->time = time;
    temp->next = NULL;
    return(temp);
}

//This method creates a directed edge
bool createEdge(GRAPH *gr, int v1, int v2, int time){
    if(!gr) return(false);
    if((v1 < 0) || (v1 >= gr->numberOfVertices)) return(false);
    if((v2 < 0) || (v2 >= gr->numberOfVertices)) return(false);

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
        printf("Vertice: %d \n", i);
        ADJACENCY *adj = gr->adjadcencies[i].head;
        while(adj){
            print("v%d(%d) ", adj->vertice, adj->time);
            adj = adj->next;
        }
        printf("\n");
    }
}

int main(){

    return 1;
}
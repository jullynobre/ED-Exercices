/*Dijkstra's algorithm to find the shortest distance between two vertices */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

void initGraph(GRAPH *g, int *d, int *p, int s){
    int v;
    for(v = 0; v < g->vertices; v++){
        d[v] = INT_MAX/2;
        p[v] = -1;
    }
    d[s] = 0;
}

void relax(GRAPH *g, int *d, int *p, int u, int v){
    ADJACENCY *ad = g->adjadcencies[u].head;
    
    while(ad && ad->vertice != v) ad = ad->next;

    if(ad){
        if(d[v] > d[u] + ad->time){
            d[v] = d[u] + ad->time;
            p[v] = u;

            printf("Previus v%d = v%d\n", v, u);
        }
    }
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

bool hasOpen(GRAPH *gr, int *open){
    int i;
    for (i = 0; i < gr->vertices; i++) 
        if(open[i]) return(true);
    return(false);
}

int shorterDistance(GRAPH *gr, int *open, int *d){
    int i;
    for (i = 0; i < gr->vertices; i++)  if(open[i]) break;
    if(i == gr->vertices) return(-1);

    int shorter = i;
    for(i = shorter + 1; i < gr->vertices; i++)
        if(open[i] && (d[shorter] > d[i]))
            shorter = i;

    return(shorter);
}

int *dijkstra(GRAPH* gr, int s){
    int *d = (int *) malloc(gr->vertices * sizeof(int));
    int p[gr->vertices];
    bool open[gr->vertices];

    initGraph(gr, d, p, s);

    int i;
    for (i = 0; i < gr->vertices; i++)  open[i] = true;

    while(hasOpen(gr, open)){
        int u = shorterDistance(gr, open, d);
        open[u] = false;

        ADJACENCY *adj = gr->adjadcencies[u].head;
        while(adj){
            relax(gr, d, p, u, adj->vertice);
            adj = adj->next;
        }
    }

    return d;
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

    int *r = dijkstra(gr, 0);

    int i;
    for(i = 0; i < gr->vertices; i++)
        printf("D(v0 -> v%d) = %d\n", i, r[i]);

    return 1;
}
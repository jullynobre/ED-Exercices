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
    /* data */

    ADJACENCY *head;
} VERTICE;

typedef struct graph {
    int vertices;
    int edges;
    VERTICE *adj;
} GRAPH;

int main(){

    return 1;
}
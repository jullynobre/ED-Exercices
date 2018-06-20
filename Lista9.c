/*

2.
    e1 ab
    e2 bc
    e3 cg
    e4 gd
    e5 da
    e6 ab
    e7 bd
    e8 dc
    e9 ca

    a. Caminhos não cíclicos de a até g
        e5 - e4
        e5 - e8 - e3
        e5 - e7 - e2 - e3+
        e7 - e3
        e7 - e8 - e4
        e6 - e2 - e3
        e6 - e7 - e4
        e1 - e2 - e3
        e1 - e7 - e4
    b. Caminho não cíclicos de g até b
        e3 - e2
        e3 - e9 - e6
        e3 - e8 - e5 - e6
        e4 - e7
        e4 - e8 - e2
        e4 - e8 - e9 - e6
        e4 - e5 - e6
        e4 - e5 - e9 - e2
    c. Grau dos nós b, d e g
        b = 4
        d = 4
        g = 2

3. Nós adjacentes de a, d e g
    a = b, c, d
    d = a, b, c, g
    g = c, d
4. Seguência dos nós visitados, partindo do vértice a
    b, c, g, d, a, b, d, c, a

*/      

#include <stdio.h>
#include <stdlib.h>

typedef struct edge {
    char vertice1;
    char vertice2;
} EDGE;

EDGE *newEdge(char v1, char v2){
    EDGE *aux = (EDGE *) malloc(sizeof(EDGE));
    aux->vertice1 = v1;
    aux->vertice2 = v2;

    return aux;
}

int main(){
    EDGE *edges[9] = {
        newEdge('a', 'b'), 
        newEdge('b', 'c'), 
        newEdge('c', 'g'), 
        newEdge('g', 'd'), 
        newEdge('d', 'a'),
        newEdge('a', 'b'),
        newEdge('b', 'd'), 
        newEdge('d', 'c'), 
        newEdge('c', 'a')
    };

    int conec[5] = {0, 0, 0, 0, 0};

    char node = 'a';

    int i, j;
    for(i = 0; i < 9; i++){
        char node2 = ' ';

        if( edges[i]->vertice1 == node ) node2 = edges[i]->vertice2;
        else if ( edges[i]->vertice2 == node ) node2 = edges[i]->vertice1;
        
        if(node2 != ' '){
            switch (node2){
                case 'a':
                    conec[0] = 1;
                    break;
                case 'b':
                    conec[1] = 1;
                    break;
                case 'c':
                    conec[2] = 1;
                    break;
                case 'd':
                    conec[3] = 1;
                    break;
                case 'g':
                    conec[4] = 1;
                    break;
            }
        }
    }

    switch (node){
        case 'a':
            conec[0] = 1;
            break;
        case 'b':
            conec[1] = 1;
            break;
        case 'c':
            conec[2] = 1;
            break;
        case 'd':
            conec[3] = 1;
            break;
        case 'g':
            conec[4] = 1;
            break;1
    }
    
    j = 1;
    for(i = 0; i < 5; i++)
        if(!conec[i]) j = 0;
        
    
    if(j) printf("\nv%c está conectado com todos os outros vértices\n", node);
    else printf("\nv%c NÂO está conectado com todos os outros vértices\n", node);
    
    return 1;
}
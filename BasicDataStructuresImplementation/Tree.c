#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef int TYPEKEY;

typedef struct node {
    TYPEKEY key;
    /*Data goes here*/

    struct node *sibilin, *child;
} NODE;

typedef NODE* POINTER;


//Return a new node with the specified key
POINTER newNode(TYPEKEY key){
	POINTER newNode = (POINTER)malloc(sizeof(NODE)); 
	
	newNode->child = NULL;
	newNode->sibilin = NULL;
	newNode->key = key;

	return(newNode);
}


int main(){
	
	POINTER root = newNode(8);
	printf("teste");

	//system("pause");

	return(0);
}
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

POINTER searchKey(POINTER root, TYPEKEY key){
	if(root == NULL) return(NULL);
	if(root->key == key) return root;

	POINTER child = root->child;
	while(child){
		POINTER aux = searchKey(child, key);
		if(aux) return aux;

		child = child->sibilin;
	}
	return(NULL);
}

bool insert(POINTER root, TYPEKEY newKey, TYPEKEY parentKey){
	POINTER parent = searchKey(root, parentKey);

	if(!parent) return(false);

	POINTER node = newNode(newKey);
	POINTER child = parent->child;
	if(!child) parent->child = node;
	else{
		while(child->sibilin)
			child = child->sibilin;
		child->sibilin = node;
	}

	return true;
}

void printTree(POINTER root){
	if (root == NULL) return;
	printf("%d (", root->key);

	POINTER child = root->child;
	while(child){
		printTree(child);
		child = child->sibilin;
	}

	printf(")");
}

int main(){
	
	POINTER root = newNode(8);
	printf("%d\n", insert(root, 7, 8));

	printTree(root);
	return(0);
}
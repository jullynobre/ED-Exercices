#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef int TYPEKEY;

typedef struct aux {
    TYPEKEY key;
    /*Data goes here*/

    struct aux *left, *right;
} NODE;

typedef NODE* POINTER;

//Function that initialize a tree; Outher functionalities can be added to this function in future
POINTER init(){
	return(NULL);
}

int main(){
	POINTER r = init();
	return(0);
}

POINTER insert(POINTER root, POINTER node){
	if(root == NULL){
		return(node);
	}
	if(node->key < root->key){
		root->left = insert(root->left, node);
	}else{
		root->right = insert(root->right, node);
	}
	return(root);
}
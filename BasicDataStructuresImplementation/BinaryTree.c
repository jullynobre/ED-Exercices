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

//Function that initialize a tree; Other functionalities can be added to this function in future
POINTER init(){
	return(NULL);
}

//Return the root of tree that node were inserted
POINTER insert(POINTER root, POINTER node){
	if(root == NULL){
		return(node);
	}
	if(node->key < root->key){
		root->left = insert(root->left, node);
	} else{
		root->right = insert(root->right, node);
	}
	//Ignore equal key
	return(root);
}

//Return a new node with the specified key
POINTER newNode(TYPEKEY key){
	POINTER node = (POINTER) malloc(sizeof(POINTER));
	node->left = NULL;
	node->right = NULL;
	node->key = key;

	return(node);
}

//Return the node for specified key
POINTER search(TYPEKEY key, POINTER root){
	if(root == NULL){ return(NULL); }
	else if(key < root->key){ return( search(key, root->left) ); }
	else if(key > root->key){ return( search(key, root->right) ); }
	return root;
}

int countNodes( POINTER root ){
	if (root == NULL) { 
		return(0); 
	}
	return (countNodes(root->left) + 1 + countNodes(root->right));
}

//Return the pointer of the searched node. RootNode recieve the pointer for his root node
POINTER searchNode(POINTER root, TYPEKEY key, POINTER *dad){
	POINTER actual = root;
	*dad = NULL;
	while (actual){
		if( actual->key == key){ return(actual); }
		*dad = actual;
		if( key < actual->key ){ actual = actual->left; }
		else{ actual = actual->right; }
	}
	return(NULL);
}

POINTER removeNode(POINTER root, TYPEKEY key){
	POINTER dad, node, p, q;
	node = searchNode(root, key, &dad);

	if(node == NULL) return(root);

	if(!node->left || !node->right){ //if the node removed has a maximum of one child
		if(!node->left) q = node->right;
		else q = node->left;
	}
	else{ //If has two child
		p = node;
		q = node->left;
		while(q->right){
			p = q;
			q = q->right;
		}
		//If the substitute parent is or isn't the node removed
		if(p != node){
			p->right = q->left;
			q->left = node->left;
		}
		q->right = node->right;
	}
	if (!dad){ //If remove node is the root node
		free(node);
		return(q);
	}
	if(key < dad->key) dad->left = q;
	else dad->right = q;
	free(node);
	return(root);
}

void printTree(POINTER root){
	if(root != NULL){
		printf("%i", root->key);
		printf("(");
		printTree(root->left);
		printTree(root->right);
		printf(")");
	}
}

int main(){
	POINTER tree = init();

	POINTER n1 = newNode(25);
	tree = insert(tree, n1);
	POINTER n2 = newNode(12);
	tree = insert(tree, n2);
	POINTER n3 = newNode(13);
	tree = insert(tree, n3);
	POINTER n4 = newNode(26);
	tree = insert(tree, n4);

	printf("%d\n", countNodes(tree));
	printTree(tree);

	system("pause");

	return(0);
}
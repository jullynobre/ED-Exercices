#include <stdio.h>
/*
Leia um vetor X de N elementos e que:
	Crie outro vetor Y contendo os elementos de X que estão na faixa entre 10 e 40;
	Crie outro vetor W contendo os números que estão nas posições pares;
	Pesquise a existência de um determinado elemento Z no vetor X;
	Escreva o menor e maior elemento do vetor X.
*/

void printList(int *xi, int count)
{
	for (int i = 0; i < count; i++)
    {	
    	printf("%d ", *xi);
    	xi++;
    }
}

void getY(int *xi, int count)
{
	if(count > 0)
	{
		int qtt = 0, *yi, aux;
		yi = malloc(sizeof(int) * count);
		
		for (int i = 0; i < count; i++)
	    {	
	    	if(*(xi + i) > 10 && *(xi + i) < 40)
	    	{
	    		*(yi + qtt) = *(xi + i);
	    		qtt++; 
	    	}
	    }
	    
	    printf("Y (vetor com os elemntos na faixa entre 10 e 40): ");
	    printList(yi, qtt);
	}
}

void getW(int *xi, int count)
{
	if(count > 0)
	{
		int qtt = 0, *wi, aux;
		wi = malloc(sizeof(int) * count);
		
		for (int i = 0; i < count; i++)
	    {	
	    	if(i % 2 == 0)
	    	{
	    		*(wi + qtt) = *(xi + i);
	    		qtt++; 
	    	}
	    }
	    
	    printf("\nW (vetor com os numeros que estao nas posicoes pares): ");
	    printList(wi, qtt);
	}
}

int checkForExistence(int *xi, int count, int z)
{
	int existence = 0;
	for (int i = 0; i < count; i++)
    {	
    	if(*(xi + i) == z)
    	{
    		existence++;
    	}
    }
    return existence;
}

void getHigherAndLower(int *xi, int count){
	int higher = *xi, lower = *xi;
	for (int i = 1; i < count; i++)
    {
    	if(*(xi + i) > higher)
    	{
    		higher = *(xi + i); 
    	}
    	if(*(xi + i) < lower)
    	{
    		lower = *(xi + i); 
    	}
    }
    printf("\nMenor elemento: %d \nMaior elemento: %d\n", lower, higher);
}

int main()
{
	int *xi, n = 0, z = 0, existence;
    
    printf("Informe a quantidade N de elementos do vetor a ser lido: ");
    scanf("%d", &n);

    xi = malloc(n*sizeof(int));

    printf("Agora, informe os %d elementos do vetor: \n", n);
    for (int i = 0; i < n; i++)
    {	
    	scanf("%d", (xi + i));	
    }

    getY(xi, n);
    getW(xi, n);

    printf("\n\nInforme um elemento Z: ");
	scanf("%d", &z);
	existence = checkForExistence(xi, n, z);
	if(existence)
	{
		printf("O elemento %d se repete %d vez(es)\n", z, existence);
	}else
	{
		printf("O elemento %d nao existe no vetor informado\n", z);
	}

	getHigherAndLower(xi, n);

    system("pause");
	return 0;
}
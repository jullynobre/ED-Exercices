#include <stdio.h>
/*
Escreva um algoritmo que receba um vetor de N elementos e verifique a existência de
elementos repetidos. Caso não existam elementos repetidos retorne um “Ok”. Caso
contrário, que remova as repetições dos elementos e que retorne o número de
elementos removidos. A seguir efetue uma pesquisa binária no vetor sem elementos
repetidos.
*/
void printList(int *i, int count)
{
	for (int y = 0; y < count; y++)
    {	
    	printf("%d ", *(i + y));
    }
}

void removeNumberFromList(int *v, int *size, int position)
{
	for(int i = position + 1; i < *size; i++)
	{
		*(v + i - 1) = *(v + i);
	}

	*size -= 1;
}

int verifyExistenceOfRepeatedElements(int *v, int *n)
{
	int count = 0, hasRepeatedElements = 0;
	for(int i = 0; i < *n; i++)
	{
		for(int j = i + 1; j < *n; j++)
		{
			if(*(v + i) == *(v + j))
			{
				hasRepeatedElements++;
				removeNumberFromList(v, n, i);
			}
		}
	}
	return hasRepeatedElements;
}

int cmpfunc(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void order(int *i, int count){
	int aux = 0;

	for (int j = 0; j < count; j++)
	{
		for (int k = j+1; k < count; k++)
		{
			if (*(i + j) > *(i + k))
			{
				aux = *(i + k);
				*(i + k) = *(i + j);
				*(i + j) = aux;
			}
		}
	}
}

int main()
{
	int *v, size, *p, key = 0;

	printf("Informe a quantidade N de elementos do vetor: ");
	scanf("%d", &size);
	p = &size;
	v = malloc(size * sizeof(int));
	
	printf("\nInforme o(s) %d elemento(s) do vetor: \n", size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d", (v + i));
	}

	int repeatedElements = verifyExistenceOfRepeatedElements(v, p);
	if(!repeatedElements)
	{
		printf("\n\nOK!");
	}else
	{
		printf("%d elemento(s) removido(s)\n", repeatedElements);
	}
	printf("\nLista com elementos sem repeticoes: ");
	printList(v, size);
	

	printf("\n\nInforme um valor a ser pesquisado no vertor atraves  de uma pesquisa binaria: ");
	scanf("%d", &key);
	order(v, size);
	int *item = (int*) bsearch (&key, v, size, sizeof (int), cmpfunc);
	if( item != NULL ) 
	{
      printf("%d encontrado!\n", *item);
   	} else 
   	{
      printf("%d não foi encontrado!\n", *item);
   	}
	
	printf("\n");
	system("pause");
	return 0;
}
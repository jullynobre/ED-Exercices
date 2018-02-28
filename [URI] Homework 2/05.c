#include <stdio.h>
/*Faça um programa que leia um valor N. Este N será o tamanho de um vetor X[N]. 
A seguir, leia cada um dos valores de X, encontre o menor elemento deste vetor e a sua posição dentro do vetor, mostrando esta informação.*/

int main()
{
	int n, *x, i, smaller, position = 0;
	scanf("%d", &n);
	x = malloc(n * sizeof(int));
	for(i = 0; i < n; i++)
	{
		scanf("%d", (x + i));
	}
	smaller = *x;
	for(i = 1; i < n; i++)
	{
		if(*(x + i) < smaller)
		{
			smaller = *(x + i);
			position = i;
		}
	}

	printf("Menor valor: %d\nPosicao: %d\n", smaller, position);

	system("pause");
	return 0;
}
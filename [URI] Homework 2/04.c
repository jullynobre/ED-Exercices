#include <stdio.h>
/*Faça um programa que leia um valor e apresente o número de Fibonacci correspondente a este valor lido. 
Lembre que os 2 primeiros elementos da série de Fibonacci são 0 e 1 e cada próximo termo é a soma dos 2 anteriores a ele. 
Todos os valores de Fibonacci calculados neste problema devem caber em um inteiro de 64 bits sem sinal.*/

int main()
{
	int t = 0, i, j, *n;
    scanf("%d", &t);
    n = malloc(t * sizeof(int));
    for(i = 0; i < t; i++)
    {
    	scanf("%d", (n + i));
    }

    for(j = 0; j < t; j++)
    {
    	unsigned long long int first = 0, second = 1, next = 1, aux =0;
    	int index;
    	index = *(n + j);
    	if(index >= 0 && index <= 60)
    	{
	    	if(index == 0)
	    	{
	    		printf("Fib(%d) = %d\n", index, 0);
	    	}
	    	else if(index == 1 || index == 2)
	    	{
	    		printf("Fib(%d) = %d\n", index, 1);
	    	}
	    	else
	    	{
		    	for(i = 2; i < index; i++)
		    	{
		    		first = second;
		    		aux = second + next;
		    		second = next;
		    		next = aux;
		    	}
		    	printf("Fib(%d) = %lld\n", index, next);
	    	}
    	}
    }

	system("pause");
    return 0;
}
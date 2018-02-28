#include <stdio.h>
/*
Leia uma lista de no máximo 100 números inteiros, carregando-os em um vetor. Osnúmeros lidos maiores ou iguais que 256 deverão ser ignorados.
	Ordene os números lidos em ordem decrescente.
	Informar quantos são ímpares e quantos são pares.
	Apresente a média dos números ímpares maiores que 50. 
*/

void printList(int *i, int count)
{
	for (int y = 0; y < count; y++)
    {	
    	printf("%d ", *i);
    	i++;
    }
}

void descendingOrder(int *i, int count){
	int aux = 0;

	for (int j = 0; j < count; j++)
	{
		for (int k = j+1; k < count; k++)
		{
			if (*(i + j) < *(i + k))
			{
				aux = *(i + k);
				*(i + k) = *(i + j);
				*(i + j) = aux;
			}
		}
	}
}

void printQtdeOfOddAndEvenNumbers(int *i, int count)
{
	int odd = 0, even = 0; 
	for (int j = 0; j < count; j++)
	{
		if(*(i + j) % 2){
			odd++;
		}else{
			even++;
		}
	}
	printf("\nQuantidade de numeros impares e pares, consecutivamente: %d, %d", odd, even);
}

int getAverageOddBiggerThan50(int *i, int count)
{
	int sum = 0;
	int numbers = 0;
	for (int j = 0; j < count; j++)
	{
		if(*(i + j) % 2 && *(i + j) > 50){
			numbers++;
			sum += *(i + j);
		}
	}
	return sum/numbers;
}

int main()
{
    int n[100], *i, in, count = 0, qtde[2];
    i = &n[0];

    for (int y = 0; y < 10; y++)
    {	
    	scanf("%d", &in);
    	if(in < 256){
    		*i = in;
    		i++;
    		count++;
    	}
    }

    i = &n[0];

    printf("Lista original com os numeros menores que 256: ");
	printList(i, count);
	
	printf("\nLista em ordem decrescente: ");
	descendingOrder(i, count);
	printList(i, count);
    
    printQtdeOfOddAndEvenNumbers(i, count);
	
	printf("\nQuantidade de numeros impares maiores que 50: %d \n", getAverageOddBiggerThan50(i, count));
    	
    system("pause");
    return 0;
} 
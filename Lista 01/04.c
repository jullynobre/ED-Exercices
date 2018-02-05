#include <stdio.h>
/*
Desenvolva um algoritmo que determine se um determinado número N informado é
primo ou não. Se sim, que encontre e informe os dois primos antecessores de N e os dois
primos sucessores de N. O algoritmo só encerra quando for informado um número N
primo.
*/

int isPrimeNumber(int n)
{
	if(n > 1)
	{
		for(int i = 2; i <= n/2; i++)
		{
			if(n % i == 0)
			{
				return 0;
			}
		}
		return 1;
	}
	return 0;
}

void predecessorsPrimeNumbers(int n)
{
	int count = 0;
	while(count < 2 && n > 1)
	{
		n--;
		if(isPrimeNumber(n))
		{
			printf("Numero primo antecessor: %d\n", n);
			count++;
		}
	}
}

void successorsPrimeNumbers(int n)
{
	int count = 0;
	while(count < 2)
	{
		n++;
		if(isPrimeNumber(n))
		{
			printf("Numero primo sucessor: %d\n", n);
			count++;
		}
	}
}

int main()
{
	int n = 0;
	
	while(1)
	{
		printf("\nInforme um numero: ");
		scanf("%d", &n);

		if(isPrimeNumber(n))
		{
			predecessorsPrimeNumbers(n);
			successorsPrimeNumbers(n);
			break;
		}
	}

	system("pause");
	return 0;
}
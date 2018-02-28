#include <stdio.h>
/*Escreva um programa que leia dois valores X e Y. A seguir, mostre uma sequência de 1 até Y, passando para a próxima linha a cada X números.*/

int main()
{
	int x, y, i, j = 1;
	scanf("%d %d", &x, &y);
	if(1 < x && x < 20 && x < y && y < 100000){
		for(i = 1; i <= y; i++){
			printf("%d", i);
			
			if(j < x){
				printf(" ");
			} else{
				printf("\n");
				j = 0;
			}

			j++;
		}
	}

	system("pause");
	return 0;
}
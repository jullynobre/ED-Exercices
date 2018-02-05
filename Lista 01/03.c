#include <stdio.h>
/*
Leia um vetor A e um vetor B, ambos com N elementos e que intercale estes vetores A e
B, formando um outro vetor C da seguinte forma. A seguir efetue uma pesquisa
seqüencial no vetor C.
C[1] = A[1]
C[2] = B[1]
C[3] = A[2]
C[4] = B[2]
*/
void printList(int *i, int count)
{
	for (int y = 0; y < count; y++)
    {	
    	printf("%d ", *i);
    	i++;
    }
}

void intercalate(int *a, int *b, int *c, int count){
	for (int i = 0; i < count; i++)
	{
		*(c + 2*i) = *(a + i);
		*(c + 2*i + 1) = *(b + i);
	}

	printf("\n");
	printList(c, 2*count);
}

int main()
{
	int *a, *b, *c, n = 0;
	
	printf("Informe a quantidade N de elementos dos vetores A e B: ");
	scanf("%d", &n);
	
	a = malloc(n*sizeof(int));
	b = malloc(n*sizeof(int));
	c = malloc(2*n*sizeof(int));

	printf("\nInforme o(s) %d elemento(s) do vetor A: \n", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", (a + i));
	}
	printf("\nInforme o(s) %d elemento(s) do vetor B: \n", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", (b + i));
	}

	intercalate(a, b, c, n);

	system("pause");
	return 0;
}
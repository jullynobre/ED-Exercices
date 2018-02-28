#include <stdio.h>
#include <math.h> 
/*
Neste problema você deve ler um número que indica uma coluna de uma matriz na qual uma operação deve ser realizada, um caractere maiúsculo, 
indicando a operação que será realizada, e todos os elementos de uma matriz M[12][12]. Em seguida, calcule e mostre a soma ou a média dos elementos 
que estão na área verde da matriz, conforme for o caso. 
*/

int main()
{
	float m[2][2], sum = 0, result, intP, floatP, resultF;
	int c, x, y;
	char t;

	scanf("%d", &c);
	scanf("%1s", &t);
	for(x = 0; x < 2; x++)
	{
		for (y = 0; y < 2; y++)
		{
			printf("M[%d][%d] : ", x, y);
			scanf("%f", &m[ x ][ y ]);
		}
	}

	for(x = 0; x < 2; x++)
	{
		sum += m[x][c];
	}

	if(t == 'S')
	{
		result = sum;
	}else if (t == 'M')
	{
		result = sum/2;
	}

	intp = (int) result;
	
	system("pause");
	return 0;
}
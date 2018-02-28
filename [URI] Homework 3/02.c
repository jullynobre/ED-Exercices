#include <stdio.h>

int correctPositions(int *p, int m){
	int *o, i, j, qtt = 0, bigger = 0;
	o = malloc(m * sizeof(int));
	for(i = 0; i < m; i++)
	{
		bigger = *(p + i);
		for(j = i + i; j < m; j++)
		{
			if(*(p + j) > *(p + i)) bigger = *(p + j);
		}
		*(o + i) = bigger;
		if(*(o + i) == *(p + i)) qtt++;
	}

	return qtt;
}

int main()
{
	int n = 0, i, j, m = 0, *p;
	scanf("%d", &n);

	for(i = 0; i < n; i++)
	{
		scanf("%d", &m);
		p = malloc(m*sizeof(int));
		for(j = 0; j < n; j++)
		{
			scanf("%d", (p + j));
		}

		printf("%d\n", correctPositions(p, m));
	}

	system("pause");
	return 0;
}
#include <stdio.h>

int main()
{
	int i;
	for(i = 1; i <= 9; i++)
	{
		if(i % 2)
		{
			int j = 6;
			while(j > 3)
			{
				printf("I=%d J=%d\n", i, i + j);
				j--;
			}
		}
	}

	system("pause");
	return 0;
}
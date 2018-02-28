#include <stdio.h>

int main()
{
	for(int i = 1; i <= 100; i++)
	{
		if(i % 2)
		{
			printf("%d\n", i);
		}
	}

	system("pause");
	return 0;
}
#include <stdio.h>

void sendFromAToB(int *a, int *b, int n, int *station, int *stationCount, int carIndex, int carValue){
	int i;
	if(carValue < n)
	{
		//Check to see if there are any car in front of him
		if(*(a + carValue) == 0)
		{
			*(b + carIndex) = carValue;
			*(a + carValue - 1) = 0;
		}else
		{
			i = carValue;
			while((i < n) && *(a + i) != 0)
			{
				*(station + *stationCount) = *(a + i);
				*(a + i) = 0;
				*(stationCount)++;
				i++;
			}
		}

	}

}


int main(){
	int i, j, k, n = 1;
	int *a, *b, *station;

	while(n != 0)
	{
		scanf("%d", &n);
		if(n != 0)
		{
			a = malloc(n*sizeof(int));
			b = malloc(n*sizeof(int));
			station = malloc(n*sizeof(int));
			
			scanf("%d", &n);
			if(n != 0)
			{
				*(a + n - 2) = 1;
				*(b) = n;
				//Fills A and B 
				for(i = 1; i < n; i++)
				{
					*(a + n - i - 1) = i + 1;
					scanf("%d", (b + i));
				}

				//The first car of the sequence is always possible
				sendFromAToB(a, b, n, station, 0, 0, *(b + n - 1));
			}
		} else 
		{
			scanf("%d", &n);			
		}
	}

	system("pause");
}
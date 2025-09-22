#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	srand((unsigned int)time(NULL));

	int index[10] = { 0 };
	int result[10] = { 0 };
	int N = 0, i = 0, j = 0;
	int isRun = 0, isIn = 0;

	while (isRun < 10)
	{
		N = rand() % 10;
		isIn = 0;
		for (i = 0; i < isRun; i++)
		{
			if (N == index[i])
			{
				isIn = 1;
			}
		}
		if (!isIn) {
			index[isRun] = N;
			isRun++;
		}
	}

	for (j = 0; j < 10; j++)
	{
		isIn = 0;
		for (i = 0; i < 10; i++)
		{
			if (index[i] == j)
			{
				isIn = i;
			}
		}
		result[j] = isIn;
	}

	printf("index : ");
	for (j = 0; j < 10; j++)
	{
		printf("%d ", index[j]);
	}
	printf("\nresult : ");
	for (j = 0; j < 10; j++)
	{
		printf("%d ", result[j]);
	}

	return 0;
}
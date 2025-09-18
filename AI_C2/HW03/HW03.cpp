#include <stdio.h>
#include <math.h>
#include <Windows.h>

#define PI 3.14159226535897

void moveCursor(int x, int y)
{
	printf("\x1b[%d;%dH", y, x);
}

//매개변수 isExploded
//0: 폭발전 폭탄
//1: 폭발함
void printBomb(int isExploded)
{
	//폭탄은 항상 7칸
	if (isExploded)
	{
		printf("\x1b[A^^^^^^^");
		printf("\x1b[B\x1b[7D!!BAM!!");
		printf("\x1b[B\x1b[7D^^^^^^^");
	}
	else
		printf("(  b  )");
}

int main()
{
	// 여기부터 코드를 작성하세요----------------------   
	int i = 0, j = 0, x = 14, y = 9, lx = 0, ly = 0, length = 2;
	int t = 0;

	double Pi = 3.1415926535897979323, angle = 90;

	moveCursor(0, 3);
	printBomb(0);
	moveCursor(x, y);
	for (i = 0; i < 12; i++)
	{
		lx = cos(angle * Pi / 180.0);
		ly = sin(angle * Pi / 180.0);
		for (j = 0; j < length; j++)
		{
			t++;
			moveCursor(x, y);
			if (t == 1)
			{
				printf("\033[31m*\033[0m");
			}
			else
			{
				printf("#");
			}
			x += lx;
			y += ly;
			Sleep(100);
		}
		if (lx)
		{
			length += 2;
		}
		angle -= 90;
	}
	Sleep(400);
	angle = -90;
	t = 0, length = 2;
	x = 14, y = 9;
	moveCursor(x, y);
	for (i = 0; i < 12; i++)
	{
		lx = cos(angle * Pi / 180.0);
		ly = sin(angle * Pi / 180.0);
		for (j = 0; j < length; j++)
		{
			t++;
			moveCursor(x, y);
			printf(" ");
			moveCursor(x, y);
			x -= lx;
			y -= ly;
			moveCursor(x, y);
			printf("\033[31m*\033[0m");
			moveCursor(x, y);
			Sleep(100);
		}
		if (lx)
		{
			length += 2;
		}
		angle -= 90;
	}

	system("cls");
	moveCursor(8, 8);
	printBomb(1);

	// 여기까지 코드를 작성하세요----------------------   
	moveCursor(10, 20);
	return 0;
}
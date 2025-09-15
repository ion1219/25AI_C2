#include <stdio.h>
#include <Windows.h>
#include <math.h>

void move(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}



int main() 
{
	int line = 5, i = 0,j = 0, x = 0, y = 0, lx = 0, ly = 0;
	double Pi = 3.1415926535897979323, angle = 0;
	printf("(Bomb)");
	for (i = 0; i < 5; i++) 
	{
		lx = cos(angle * Pi / 180);
		if (lx) {
			line = -5;
		}
		else {
			line = 0;
		}
		ly = sin(angle * Pi / 180.0);
		for (j = 0; j < line; j++)
		{
			x += lx;
			y += ly;
			move(x, y);
			printf("*");
		}
		angle += 90;
	}
}
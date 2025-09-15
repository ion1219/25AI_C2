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
	int line = 5, i = 0, j = 0, x = 0, y = 0, lx = 0, ly = 0, length = 5;
	int t = 0;
	double Pi = 3.1415926535897979323, angle = 0;
	printf("(Bomb)");
	x = 6, y = 0;
	for (i = 0; i < 9; i++)
	{
		lx = cos(angle * Pi / 180);
		if (lx) {
			line = 5;
			move(x, y);
			printf("+");
		}
		else {
			line = 0;
			move(x, y);
			printf("+");
			length--;
		}
		ly = sin(angle * Pi / 180.0);
		for (j = 0; j < length; j++)
		{
			t++;
			x += lx;
			y += ly;
			move(x, y);
			if (t == 25) {
				printf("*");
			}
			else if (((int)angle / 90) % 2 == 1) {
				printf("I");
			}
			else {
				printf("-");
			}
			Sleep(100);
		}
		angle += 90;
	}
	for (i = 0; i < 9; i++)
	{
		lx = cos(angle * Pi / 180);
		if (lx) {
			line = 5;
			move(x, y);
			printf("+");
		}
		else {
			line = 0;
			move(x, y);
			printf(" ");
			length++;
		}
		ly = sin(angle * Pi / 180.0);
		for (j = 0; j < length; j++)
		{
			t++;
			x -= lx + 1;
			y -= ly + 1;
			move(x, y);
			if (t == 25) {
				printf(" ");
			}
			else if (((int)angle / 90) % 2 == 1) {
				printf(" ");
			}
			else {
				printf(" ");
			}
			Sleep(100);
		}
		angle -= 90;
	}
	move(0, 20);
}
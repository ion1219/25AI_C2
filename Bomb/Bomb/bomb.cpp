#include <stdio.h>
#include <Windows.h>
#include <math.h>
#include <stdlib.h>

void move(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void clearScreen() {
	system("cls");
}

void delay(int ms) {
	Sleep(ms);
}

void setColor(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void printFrame(const char* frame[], int lines, int color) {
	setColor(color);
	for (int i = 0; i < lines; i++) {
		printf("%s\n", frame[i]);
	}
	setColor(7); // reset to white
}

int main()
{
	int line = 5, i = 0, j = 0, x = 0, y = 0, lx = 0, ly = 0, length = 5;
	int t = 0;
	double Pi = 3.1415926535897979323, angle = 0;
	printf("(Bomb)");
	x = 5, y = 0;
	for (i = 0; i < 9; i++)
	{
		lx = cos(angle * Pi / 180);
		if (lx) {
			line = 5;
			move(x, y);
			if (t != 0) {
				printf("+");
			}
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
	angle = 0;
	//move(0, 10);
	//printf("%.2f", angle);
	t = 0;
	for (i = 0; i < 9; i++)
	{
		lx = cos(angle * Pi / 180);
		if (lx) {
			line = 5;
			move(x, y);
			printf("*");
			move(x, y);
			if(t > 0)
				length++;
		}
		else {
			line = 0;
			move(x, y);
			printf("*");
			move(x, y);

		}
		ly = sin(angle * Pi / 180.0);
		for (j = 0; j < length; j++)
		{
			t++;
			move(x, y);
			printf(" ");
			move(x, y);
			x -= lx;
			y -= ly;
			move(x, y);
			printf("*");
			move(x, y);
			Sleep(100);
		}
		angle -= 90;
	}

	const char* frame0[] = {
		"                          ",
		"                          ",
		"                          ",
		"           .             ",
		"                          ",
		"                          ",
		"                          ",
		"                          ",
	};

	const char* frame1[] = {
		"                          ",
		"                          ",
		"          . .            ",
		"           *             ",
		"          . .            ",
		"                          ",
		"                          ",
		"                          ",
	};

	const char* frame2[] = {
		"                          ",
		"         .   *   .        ",
		"       *    *    *        ",
		"         *  *  *          ",
		"       .   *   .          ",
		"                          ",
		"                          ",
		"                          ",
	};

	const char* frame3[] = {
		"                          ",
		"      . * * * * * .       ",
		"     *   * * * *   *      ",
		"    * * *  ***  * * *     ",
		"     *   * * * *   *      ",
		"      . * * * * * .       ",
		"                          ",
		"                          ",
	};

	const char* frame4[] = {
		"                          ",
		"    . * * * * * * * .     ",
		"   *   * *     * *   *    ",
		"  * *  *  BOOM!  *  * *   ",
		"   *   * *     * *   *    ",
		"    . * * * * * * * .     ",
		"                          ",
		"                          ",
	};

	const char* frame5[] = {
		"                          ",
		"   ` . * * * * * * . '    ",
		"  '  *     * *     *  `  ",
		"  *   *  *  *  *  *   * ",
		"  `  *     * *     *  '  ",
		"   . ' * * * * * * ' .   ",
		"                          ",
		"                          ",
	};

	const char* frame6[] = {
		"                          ",
		"                          ",
		"      . . . . . . .       ",
		"     .   .     .   .      ",
		"      . . . . . . .       ",
		"                          ",
		"                          ",
		"                          ",
	};

	const char* frame7[] = {
		"                          ",
		"                          ",
		"                          ",
		"                          ",
		"                          ",
		"                          ",
		"                          ",
		"                          ",
	};

	const char** frames[] = {
		frame0, frame1, frame2, frame3, frame4, frame5, frame6, frame7
	};

	int colors[] = {
		7,   // White (spark)
		6,   // Yellow
		14,  // Bright Yellow
		12,  // Red
		4,   // Dark Red
		8,   // Grey smoke
		8,   // Lighter smoke
		7    // White
	};

	int frameCount = sizeof(frames) / sizeof(frames[0]);
	int linesPerFrame = 8;

	for (int i = 0; i < frameCount; i++) {
		clearScreen();
		printFrame(frames[i], linesPerFrame, colors[i]);
		delay(300);
	}

	delay(1000);
	return 0;

	move(0, 50);
}
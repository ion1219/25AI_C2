

#include <stdio.h>

void sum(int x, int y,int* res)
{
    *res = x + y;
}

int main()
{
    int* pa;
    int a = 3;
    int b = 2;
    int c = 0;

    pa = &a;

    sum(a, b, pa);

    printf("%d", *pa);

    return 0;
}

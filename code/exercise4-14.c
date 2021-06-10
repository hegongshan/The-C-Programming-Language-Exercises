#include <stdio.h>

#define swap(t, x, y) {t temp = x; x = y; y = temp;}

int main()
{
    int a = 20;
    int b = 10;
    printf("before swap: a = %d, b = %d\n", a, b);
    swap(int, a, b);
    printf("after swap: a = %d, b = %d\n", a, b);
    return 0;
}

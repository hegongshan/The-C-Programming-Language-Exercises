#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
	printf("%u\n", setbits(170, 4, 3, 7));
	return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	// y最右边的n位
	int i = y & ~(~0 << n);
	int mask = ~(((1 << n) - 1) << (p - n + 1));
	x &= mask;
	return x | (i << (p - n + 1));
}
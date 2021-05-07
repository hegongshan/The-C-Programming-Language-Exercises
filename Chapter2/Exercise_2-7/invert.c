#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main()
{
	printf("%d\n", invert(240, 4, 3));
	return 0;
}

unsigned invert(unsigned x, int p, int n)
{
	int mask = (~(~0 << n)) << (p - n + 1);
	return mask ^ x;
}
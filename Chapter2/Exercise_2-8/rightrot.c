#include <stdio.h>

unsigned rightrot(unsigned x, unsigned n);

int main()
{
	printf("%u\n", rightrot(170, 5));
	return 0;
}

unsigned rightrot(unsigned x, unsigned n)
{
	while (n > 0)
	{
		if (x & 0x1)
			x = (x >> 1) | ~(~0U >> 1);
		else
			x >>= 1;
		n--;
	}
	return x;
}
#include <stdio.h>

int invert(int x, int p, int n);

int main(void) {
	printf("%o\n", invert(0b110110110, 2, 2));
	return 0;
}

int invert(int x, int p, int n) {
	int a = (x >> (p + 1 - n)) & ~(~0 << n);
	a = a << n;
	// return (((x >> (p + 1 - n)) ^ ~(~0 << n)) << n) | (x & ~(~0 << n));
}

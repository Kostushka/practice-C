#include <stdio.h>
#define MALE     0b00000001
#define DRIVE    0b00000010
#define HIGH_EDU 0b00000100
#define CAT 	 0b00001000

void print_person(char p);

int main (void) {

	char a, b;

	a = MALE | CAT;
	b = HIGH_EDU | DRIVE;

	print_person(a);
	print_person(b);
	
	return 0;
}

void print_person(char p) {
	if (p & MALE) {
		printf("male ");
	} else {
		printf("female ");
	}
	if (p & DRIVE) {
		printf("drive ");
	}
	if (p & HIGH_EDU) {
		printf("high_edu ");
	}
	if (p & CAT) {
		printf("cat ");
	}
	printf("\n");

}

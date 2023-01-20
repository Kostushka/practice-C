#include <stdio.h>
#include "calc.h"
#define MAX 100

double stackCalc[MAX]; //[...]
int iCalc = 0;

double pop (void) {
	if (iCalc > 0) {
		--iCalc;
		return stackCalc[iCalc];
	} else {
		printf("stack empty\n");
		return 0.0;
	}
}

void push (double f) {
	if (iCalc < MAX) {
		stackCalc[iCalc] = f;
		++iCalc;
	} else {
		printf("stack full");
	}
}

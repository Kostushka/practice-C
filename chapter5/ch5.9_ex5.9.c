#include <stdio.h>

// Упр. 5.9 
// переписать через указатели:
// day_of_years
// month_day 

int day_of_years (int year, int d, int m);
void month_day (int year, int yearday, char *d, char *m);

static char year[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char lyear[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static char *y = year;
static char *ly = lyear;

static char *daytab[2];

int main (void) {

	// static char *daytab[] = {y, ly}; ???
	daytab[0] = y;
	daytab[1] = ly;

	char day, month = 0;
	printf("%d\n", day_of_years(2016, 24, 5));
	month_day(2004, 3, &day, &month);
	printf("%d %d\n", day, month);
	return 0;
}

int day_of_years (int year, int d, int m) {
	int leap, i;
	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	for (i = 1; i < m; i++) {
		d += daytab[leap][i];
	}
	return d;
}

void month_day (int year, int yearday, char *d, char *m) {
	int leap, i;
	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++) {
		yearday -= daytab[leap][i];
	}
	*d = yearday;
	*m = i; 
}

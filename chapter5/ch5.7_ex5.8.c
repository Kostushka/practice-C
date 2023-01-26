#include <stdio.h>

// Упр. 5.8
// контроль ошибок данных в функциях

int day_of_year (int year, int month, int day);
void month_day (int year, int yearday, int *m, int *d);

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int main (void) {

	int year, month, day;
	
	year = 2018;
	month = 5;
	day = 2;
	
	printf("2018 05 02 = %d days\n", day_of_year(year, month, day));

	month_day(1905, 136, &month, &day);
	printf("1905 136 days: 1905 %d %d \n", month, day);
	
	return 0;
}

int day_of_year (int year, int month, int day) {

    if (month < 1 || month > 12) {
        printf("wrong month\n");
        return 1;
    }

    if (day < 1 || day > 31) {
        printf("wrong day\n");
        return 1;
    }

	int leap, i;
	
	// проверить год - високосный или нет по формуле: 1 или 0
	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

	// прибавляем к исходному дню дни каждого месяца
	for (i = 1; i < month; i++) {
		day += daytab[leap][i];
	}

	return day;	
}


void month_day (int year, int yearday, int *m, int *d) {

	if (yearday < 1 || yearday > 366) {
        printf("wrong data\n");
        return;
    }

	int leap, i;
	
	// проверить год - високосный или нет по формуле: 1 или 0
	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

	// последовательно вычитаем дни каждого месяца
	for (i = 1; yearday > daytab[leap][i]; i++) {
		yearday -= daytab[leap][i];
	}

	// записываем по адресу
	*m = i;
	*d = yearday;
}

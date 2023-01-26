#include <stdio.h>

// 5.7 Многомерные массивы

// при передаче многомерного массива в функцию, строки можно не указывать
// f(char days[2][13]){...} // правильно
// f(char days[][13]){...} // правильно

// Задача: год, месяц, день => день года || 2018 05 02 => 1 < 5 -> 31 + 2 -> 2 < 5 -> 33 + 28 -> 3 < 5 -> 61 + 31 -> 4 < 5 -> 92 + 30 -> 5 < 5 => 122
// 		   день года => день, месяц || 1905 136 => 136 > 31 => 136 - 31 => 105 > 28 => 77 > 31 => 46 > 30 => 16 > 31 => 16 05

int day_of_year (int year, int month, int day);
void month_day (int year, int yearday, int *m, int *d);

// многомерный массив с кол-вом дней в каждом месяце для високосного и не високосного года
			   // [строка][столбец]
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

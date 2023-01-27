#include <stdio.h>
// 5.8 Инициализация массива указателей
// Задача: вернуть указатель на строку символов с названием n месяца

char* month_name (int n);

int main (void) {

	printf("%p\n", month_name(5)); // возвращает адрес начала строки
	printf("%s\n", month_name(5));
	
	return 0;
}

char* month_name (int n) {

	// статический массив с указателями
	static char *months[] = {
	"Illegal month", "Jan", "Feb", 
	"Mar", "Apr", "May", 
	"Jun", "Jul", "Aug", 
	"Sep", "Oct", "Nov", 
	"Dec"};

	return (n < 1 || n > 12) ? months[0] : months[n];
	
}

#include <stdio.h>
#include <string.h>

// 7.8 Различные функции
// 7.8.1 Операции со строками


int main (void) {
	char s[] = "Hello";
	char t[] = "world";
	char c = 'l';
	int n = 3;

	// присоединяет t в хвост s
	strcat(s, t);
	
	// присоединяет n символов из t в хвост s
	strncat(s, t, n);

	// сравнивает первые символы двух строк, пока они равны
	// s < t => -1; s == t => 0; s > t => 1
	int res = strcmp(s, t); 

	// сравнивает первые n символов двух строк, пока они равны
	// s < t => -1; s == t => 0; s > t => 1
	int resn = strncmp(s, t, n);

	// копирует t в s
	strcpy(s, t);

	// копирует n символов t в s
	strncpy(s, t, n);

	// вычисляет длину s
	int len = strlen(s);

	// возвращает указатель на первый символ c в s или NULL
	char *p = strchr(s, c);

	// возвращает указатель на первый символ c в s или NULL
	char *rp = strrchr(s, c);


	
	
	return 0;
}

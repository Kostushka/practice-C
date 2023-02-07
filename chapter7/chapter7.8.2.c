#include <stdio.h>
#include <ctype.h>

// 7.8.2 Анализ, классификация и преобразование символов

int main (void) {
	unsigned char c = 'w';

	// c - алфавитный символ, иначе 0
	isalpha(c);

	// c - буква в верхнем регистре, иначе 0
	isupper(c);

	// с - буква в нижнем регистре, иначе 0
	islower(c);

	// c - цифра, иначе 0
	isdigit(c);

	// isalpha(c) или isdigit(c), иначе 0
	isalnum(c);

	// c - пробел, табуляция, конец строки, возврат каретки, перевод строки, вертикальная табуляция, иначе 0
	isspace(c);

	// с в верхнем регистре
	int u = toupper(c);

	// c в нижнем регистре
	int l = tolower(c);

	
	return 0;
}

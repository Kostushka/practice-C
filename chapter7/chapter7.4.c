#include <stdio.h>
#define MAX 100

// 7.4 Форматированный ввод и функция scanf()
// scanf - считывает символы с потока ввода и интерпретирует их в соответствии со строкой спецификацией формата, аргументы определяют, куда поместить входные данные
// sscanf - считывает символы со строки

void getdata (void);
int mygetline (char *s, int max);

int main (void) {
	double sum, v;
	sum = 0;
	// scanf возвращает число успешно прочитанных, преобразованных и помещенных по адресу элементов 
	// (1) - символ соответсвует спецификатору
	// (0) - несоответсвие спецификатору 
	// (EOF) - конец файла
	while (scanf("%lf", &v) == 1) {
		printf("%.2f\n", sum += v);
	}

	getdata();
	
	return 0;
}

void getdata (void) {
	int day, year, m;
	char month[20];
	char line[MAX];
	
	printf("%ld\n", sizeof(line));
	
	// scanf("%d %s %d", &day, month, &year);
	// printf("%d %s %d\n", day, month, year);
	
	while (mygetline(line, sizeof(line)) > 0) {
		if (sscanf(line, "%d %s %d", &day, month, &year) == 3) {
			printf("%s", line);
		} else if (sscanf(line, "%d/%d/%d", &day, &m, &year) == 3) {
			printf("%s", line);	
		} else {
			printf("invalid string: %s", line);
		}
	}
}

int mygetline (char *s, int max) {
	int c, i;
	i = 0;
	while (i < max - 1) {
		if ((c = getchar()) != EOF && c != '\n') {
			*s++ = c;
			i++;
		} else {
			break;
		}
	}
	if (c == '\n') {
		*s++ = c;
		++i;
 	}
 	*s = '\0';
 	
 	return i;
}

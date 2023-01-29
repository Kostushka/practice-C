#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXLENGTH 100

// 6.3 Массивы структур
// Программа подсчитывает сколько раз встречается ключевое слово

// массив для слов
// char *words[MAX];

// массив для счетчиков каждого слова
// char countwords[MAX];

// или массив структур
struct Key {
	char *word; // указатель на первый символ слова
	int count; // счетчик для слова
} keytab[] = {
	{"char", 0}, // 16 байт
	{"main", 0},
	{"return", 0},
	{"void", 0}
};

#define MAX (int)(sizeof keytab / sizeof (struct Key)) // размер (байты) массива структур / размер структуры (байт) 64 / 16 = 4 элемента

// инициализация массива структур
// отсортированный массив
// struct Key keytab[MAX] = {
	// {"char", 0},
	// {"main", 0},
	// {"return", 0},
	// {"void", 0}
// };


// получить слово из входного потока (слово - строка букв или цифр, начинающаяся с буквы)
int getword (char *s);
// поиск слова в массиве структур
int bisearch (char *s, struct Key *k);
// int mystrcmp (char *s, char *k);

int main (void) {
	int n;
	char word[MAXLENGTH];
	
	printf("%ld %ld\n", sizeof keytab, sizeof (struct Key));

	while (getword(word) != EOF) {
		// является ли первый символ буквой
		if (isalpha(word[0])) {
			// есть ли слово в массиве (возвращает индекс или -1)
			if ((n = bisearch(word, keytab)) >= 0) {
				// инкрементирую счетчик
				keytab[n].count++;
			}
		}
	}
	for (n = 0; n < MAX; n++) {
		if (keytab[n].count > 0) {
			printf("%d %s\n", keytab[n].count, keytab[n].word);
		}
	}

	return 0;
}

int bisearch (char *s, struct Key *k) {
	int low, high, mid;
	int res;

	low = 0;
	high = MAX - 1;

	while (low <= high) {
		mid = (low + high) / 2;
		// передаем указатели для посимвольного сравнения
		if ((res = strcmp(s, k[mid].word)) < 0) {
			high = mid - 1;
		} else if (res > 0) {
			low = mid + 1;
		} else {
			// возвращаем индекс слова в массиве
			return mid;
		}
	}
	return -1;
}
// 
// int mystrcmp (char *s, char *k) {
	// while (*s == *k) {
		// if (*s == '\0') {
			// return 0;
		// }
	// }
	// return *s - *k;
// }

int getch (void);
void ungetch (int c);

int getword (char *s) {

	int c;
	
	char *w = s;

	// получили символ
	while (isspace(c = getch()));

	if (c != EOF) {
		// записали в массив
		*w++ = c;
	}

	// если не буква, вернуть символ
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}

	int i;
	
	for (i = 0 ; i < MAXLENGTH; w++, i++) {
		// если не буква и не число, закидываем в буфер
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	}

	// перезаписать не букву нулем
	*w = '\0';	

	// первый символ слова
	return s[0];
}

char buf[MAXLENGTH];
int bufi = 0;

int getch (void) {
	return bufi > 0 ? buf[--bufi] : getchar();
}

void ungetch (int c) {
	if (bufi < MAXLENGTH) {
		buf[bufi++] = c;
	}
}

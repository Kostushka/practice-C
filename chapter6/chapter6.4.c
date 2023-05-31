#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXLENGTH 100

// 6.4 Указатели на структуры
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
struct Key *bisearch (char *s, struct Key *k);
// int mystrcmp (char *s, char *k);

int main (void) {
	char word[MAXLENGTH];
    struct Key *p;
	
	printf("%ld %ld\n", sizeof keytab, sizeof (struct Key));

	while (getword(word) != EOF) {
		// является ли первый символ буквой
		if (isalpha(word[0])) {
			// есть ли слово в массиве (возвращает индекс или -1)
			if ((p = bisearch(word, keytab)) != NULL) {
				// инкрементирую счетчик
				p->count++;
			}
		}
	}
	for (p = keytab; p < keytab + MAX; p++) {
		if (p->count > 0) {
			printf("%d %s\n", p->count, p->word);
		}
	}

	return 0;
}

struct Key *bisearch (char *s, struct Key *k) {
	struct Key *low = &k[0];
	struct Key *high = &k[MAX];
	struct Key *mid;
    int res;

	while (low < high) {
		mid = low + (high - low) / 2;
		// передаем указатели для посимвольного сравнения
		if ((res = strcmp(s, mid->word)) < 0) {
			high = mid;
		} else if (res > 0) {
			low = mid + 1;
		} else {
			// возвращаем индекс слова в массиве
			return mid;
		}
	}
	return NULL;
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

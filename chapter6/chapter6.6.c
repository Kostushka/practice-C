#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define HASHSIZE 101


// 6.6 Поиск по таблице

// ключ - значение:
// #define IN 1 => IN - 1

// install(s, t) - функция, которая записывает ключ и значение в таблицу
// lookup(s) - ищет ключ в таблице, возвращает указатель на значение или NULL

// ключ конвертируется в число - индекс в массиве указателей (каждый элемент массива указывает на начало связанного списка блоков)
// блок - структура с указателем на текст (значение) и с указателем на следующий блок в списке или NULL

struct Block {
	char *key;
	char *value;
	struct Block *next;	
};

// массив указателей на структуры
struct Block *hashtab[HASHSIZE];

// [{key: "", value: "", next: *p}, ...]

// хэш-функция: возвращает число (индекс) для размещения/поиска в массиве по ключу
unsigned hash (char *s);

// lookup(s) - ищет ключ в массиве, возвращает указатель на элемент массива или NULL
struct Block *lookup (char *s);

// install(s, t) - функция, которая проверяет есть ли пара ключ и значение: если есть, перезаписывает, иначе создает новую запись
struct Block *install (char *key, char *value);

char *mystrdup (char *s);

int main (void) {
	char k[] = "city";
	char v[] = "Moscow";
	printf("%s %s\n", install(k, v)->key, install(k, v)->value);
	install("city2", "Sevastopol");
	printf("%s\n", hashtab[hash("city2")]->value);
	printf("index: %d %d\n", hash(k), hash("city2"));
	return 0;
}

unsigned hash (char *s) {
	unsigned hashval;
	for (hashval = 0; *s != '\0'; s++) {
		hashval = *s + 31 * hashval;
	}
	return hashval % HASHSIZE;
}

struct Block *lookup (char *s) {
	struct Block *p;
	// берем элемент в таблице по индексу ключа и ищем до конца связанного списка
	for (p = hashtab[hash(s)]; p != NULL; p = p->next) {
		// проверяем соответствие в связанном списке по ключу
		if (strcmp(s, p->key) == 0) {
			return p;
		}
	}
	return NULL;
}

struct Block *install (char *key, char *value) {

	struct Block *p;
	unsigned hashval;

	// если нет записи, добавляем
	if ((p = lookup(key)) == NULL) {
		// выделяем место
		p = (struct Block *) malloc(sizeof(*p));
		// если места нет или ключ - пустая строка
		if (p == NULL || (p->key = mystrdup(key)) == NULL) {
			return NULL;
		}
		// получить индекс
		hashval = hash(key);
		// записать в элемент вершину связанного списка
		p->next = hashtab[hashval];
		// записать по индексу структуру
		hashtab[hashval] = p;
	// если есть запись, удаляем значение
	} else {
		free((void *) p->value);
	}
	// записываем значение
	if ((p->value = mystrdup(value)) == NULL) {
		return NULL;
	}
	// возвращаем указатель на структуру
	return p;
}

char *mystrdup (char *s) {
	char *p;
	p = (char *) malloc(strlen(s) + 1);
	if (p != NULL) {
		strcpy(p, s);
	}
	return p;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASHSIZE 101

// Упр. 6.5 
// Функция deletekey, удаляющая пару ключ занчения из хэш-таблицы
// ищу в хэше по ключу блок
// если есть удаляю
// иначе NULL

struct Block {
    char *key;
    char *value;
    struct Block *next;
};

struct Block *hashtab[HASHSIZE];

unsigned hash (char *key);

struct Block *lookup (char *key);

struct Block *install (char *key, char *value);

// Функция deletekey, удаляющая пару ключ занчения из хэш-таблицы
struct Block *deletekey (char *key);

int main (void) {
    char key[] = "length";
    char value[] = "95";

    install(key, value);
    printf("%s %s\n", hashtab[hash(key)]->key, hashtab[hash(key)]->value);

    deletekey(key);
    printf("%s %s\n", hashtab[hash(key)]->key, hashtab[hash(key)]->value);
    
    return 0;
}

unsigned hash (char *key) {
    unsigned hashval;
    for (hashval = 0; *key != '\0'; key++) {
        hashval = *key + 31 * hashval;
    }

    return hashval % HASHSIZE;
}

struct Block *lookup (char *key) {
    struct Block *p;
    for (p = hashtab[hash(key)]; p != NULL; p = p->next) {
        if (strcmp(p->key, key) == 0) {
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
		if (p == NULL || (p->key = strdup(key)) == NULL) {
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
	if ((p->value = strdup(value)) == NULL) {
		return NULL;
	}
	// возвращаем указатель на структуру
	return p;
}

struct Block *deletekey (char *key) {
    struct Block *p;
    if ((p = lookup(key)) != NULL) {
        free((void *) p->key);
        free((void *) p->value);
        p->key = p->value = NULL;
        return p;
    } else {
        return NULL;
    }
}
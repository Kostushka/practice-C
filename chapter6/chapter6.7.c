#include <stdio.h>
#include <stdlib.h>

// 6.7 Определение новых типов
// оператор typedef - определяет имя нового типа данных
// typedef int Length; - синоним типа int с именем Length

typedef int Length;
typedef char *String;
// структура Treenode и указатель на структуру Treep
typedef struct Node *Treep;
typedef struct Node {
	char *word;
	int count;
	struct Node *left;
	struct Node *right;
} Treenode;

Treep talloc (void);

int mystrcmp (String, String);

int main (void) {

	Length max;
	String s, p = "lala";
	p = (String) malloc(100);
	
	return 0;
}

Treep talloc (void) {
	return (Treep) malloc(sizeof(Treenode));
}

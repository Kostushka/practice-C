#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

// 6.5 Структуры со ссылками на себя
// Подсчет частоты встречаемости любого слова во входном потоке
// отсортированный массив слов + бинарный поиск - Х :(
// линейный поиск по всем словам в массиве - слишком медленно :(

// двоичное дерево: добавление нового слова в нужную позицию :)
// каждый узел содержит информацию: 1) указатель на слово
// 									2) частота встречаемости
// 									3) указатель на левый дочерний узел (меньшее по алфавиту слово)
// 									4) указатель на правый дочерний узел (большее по алфавиту слово)
// Задача: выяснить, есть ли новое слово в дереве
// слово == корню 
// слово < корня -> левый узел
// слово > корня -> правй узел
// ...
// если слова нет, добавить слово в пустое место, до которого дошли

// *если слова будут поступать в отсортированном порядке - программа будет выполнять что-то вроде линейного поиска - это долго

struct Tnode {
	char *word;
	int count;
	struct Tnode *left; // структура ссылается на себя, но не на экземпляр
	struct Tnode *right;	
};

// ищет слово или добавляет
struct Tnode *addtree (struct Tnode *p, char *w);

// создает новый узел
struct Tnode *talloc (void);

// выводит дерево в отсортированном порядке
void treeprint (struct Tnode *p);

// копирует строку в место в памяти
char *mystrdup(char *s);

int getword (char *word);
int getch (void);
void ungetch (int c);

int main (void) {

	struct Tnode *root;
	char word[MAX];

	root = NULL;
	
	while (getword(word) != EOF) {
		if (isalpha(word[0])) {
			root = addtree(root, word);
		}
	}
	
	treeprint(root);
	
	return 0;
}

int getword (char *word) {
	int c;
	char *w = word;
	while (isspace(c = getch()));

	if (c != EOF) {
		*w++ = c;	
	}

	if (!(isalpha(c))) {
		*w = '\0';
		return c;
	}
	
	int i;
	for (i = 0; i < MAX; i++, w++) {
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	}
	
	*w = '\0';
	
	return word[0];
}

char buf[MAX];
int p = 0;

int getch (void) {
	return p > 0 ? buf[--p] : getchar();
}

void ungetch (int c) {
	if (p < MAX) {
		buf[p++] = c;
	}	
}


struct Tnode *addtree (struct Tnode *p, char *w) {

	int cond;
	
	if (p == NULL) {
		p = talloc(); // новый узел
		p->word = strdup(w); // запись слова
		p->count = 1; // запись счетчика
		p->left = p->right = NULL; // запись NULL в указатели веток
	// если root не NULL
	} else if ((cond = strcmp(w, p->word)) == 0) {
		p->count++; // инкрементация счетчика
	} else if (cond < 0) {
		p->left = addtree(p->left, w); // поиск по левой ветке
	} else {
		p->right = addtree(p->right, w); // поиск по правой ветке
	}

	return p;
}


void treeprint (struct Tnode *p) {
	if (p != NULL) {
		// рекурсивно доходим до конца левой ветки
		treeprint(p->left);
		// печатаем всю левую ветку и корень
		printf("%d %s\n", p->count, p->word);
		// рекурсивно доходим до конца правой ветки и печатаем
		treeprint(p->right);
	}	
}

struct Tnode *talloc (void) {
	// обозначить возвращаемый тип (по умолчанию у malloc возвр. тип void)
	// malloc - динамическое выделение памяти для создания нового узла
	return (struct Tnode *) malloc(sizeof(struct Tnode));
}

char *mystrdup (char *s) {

	char *p;

	// int i;
	// for (i = 0; s[i] != '\0'; i++);
	
	p = (char *) malloc(strlen(s) + 1); // длина строки + \0
	
	if (p != NULL) { // если есть место
		strcpy(p, s); // копируем строку в место в памяти
	}
	return p; // возвращаем указатель на строку
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 5000
#define LIM 100

// Упр.6.4 
// Программа выводит все слова с входного потока, отсортированные по частоте встречаемости в порядке убывания
// "hello" "hello" "hello" "good" "bye" "word" "all"
// 3 hello 1 good 1 bye 1 word 1 all

// заводим массив указателей на структуру
// получаем слово
// проверяем наличие слова в структуре (в виде двоичного дерева)
// инкрементируем счетчик
// иначе кладем в создаваемую структуру (в виде двоичного дерева)
// записываем указатель на созданную структуру в массив
// сортируем массив с укзателями на структуру по count

struct Node {
	char *word;
	int count;
	struct Node *left;
	struct Node *right;
};

// массив указателей на структуру
struct Node *arr[MAX];
int n = 0;

struct Node *addtree(struct Node *p, char *s);
struct Node *talloc(void);
void printnode(struct Node *p);
int getword(char *s, int max);
int getch(void);
void ungetch(int c);
char *mystrdup(char *s);
void mystrcpy(char *s, char *t);
void swap(struct Node **p, int i, int j);
void myqsort(struct Node **p, int left, int right);

int main(void) {

	struct Node *root = NULL;

	char word[LIM];
	while (getword(word, LIM) != EOF) {
		if (isalpha(word[0])) {
			root = addtree(root, word);
		}
	}
	// printnode(root);
	myqsort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%d %s\n", arr[i]->count, arr[i]->word);
	}
	
	return 0;
}

void printnode(struct Node *p) {
	if (p != NULL) {
		printnode(p->left);
		printf("%d %s\n", p->count, p->word);
		printnode(p->right);
	}
}

struct Node *addtree(struct Node *p, char *s) {
	int cond;
	
	if (p == NULL) {
		p = talloc();
		p->word = mystrdup(s);
		p->count = 1;
		p->left = p->right = NULL;
		// записываем указатель на структуру в массив
		arr[n++] = p;
	} else if ((cond = strcmp(s, p->word)) == 0) {
		p->count++;
	} else if (cond < 0) {
		p->left = addtree(p->left, s);
	} else {
		p->right = addtree(p->right, s);
	}

	return p;
}

struct Node *talloc(void) {
	return (struct Node *) malloc(sizeof(struct Node));
}

int getword(char *s, int max) {
	int c;
	while (isspace(c = getch()));
	if (c != EOF) {
		*s++ = c;
	}
	if (!isalpha(c)) {
		*s = '\0';
		return c;
	}
	for (int i = 0; i < max; i++, s++) {
		if (!isalnum(*s = getch())) {
			ungetch(*s);
			break;
		}
	}
	*s = '\0';
	return s[0];
}

char buf[LIM];
int bufi = 0;

int getch(void) {
	return bufi > 0 ? buf[--bufi] : getchar();
}

void ungetch(int c) {
	if (bufi < LIM) {
		buf[bufi++] = c;
	} else {
		printf("buf is full\n");
	}
}

char *mystrdup(char *s) {
	char *p = (char *) malloc(strlen(s) + 1);
	if (p != NULL) {
		strcpy(p, s);
	}
	return p;
}

void mystrcpy(char *s, char *t) {
	while ((*s = *t) != '\0') {
		++s;
		++t;
	}
}

void myqsort(struct Node **p, int left, int right) {

	int pivot, i;
	
	if (left >= right) {
		return;
	}
	swap(p, left, (left + right) / 2);

	pivot = left;
	for (i = left + 1; i <= right; i++) {
		if (p[i]->count - p[left]->count > 0) {
			swap(p, i, ++pivot);
		}
	}

	swap(p, left, pivot);
	myqsort(p, left, pivot - 1);
	myqsort(p, pivot + 1, right);
	
}

void swap (struct Node **p, int i, int j) {
	struct Node *t;
	t = p[i];
	p[i] = p[j];
	p[j] = t;
}

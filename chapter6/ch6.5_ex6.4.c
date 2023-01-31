#include <stdio.h>

// Упр.6.4 
// Программа выводит все слова с входного потока, отсортированные по частоте встречаемости в порядке убывания
// "hello" "hello" "hello" "good" "bye" "word" "all"
// 3 hello 1 good 1 bye 1 word 1 all

// получаем слово
// проверяем наличие в структуре (в виде двоичного дерева)
// инкрементируем счетчик
// иначе кладем в структуру (в виде двоичного дерева)
// сортировка по count

struct Node {
	char *word;
	int count;
};

void swap (struct Node *p, int i, int j);
void qsort (struct Node *p, int left, int right);

int main (void) {
	
	return 0;
}


void qsort (struct Node *p, int left, int right) {
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
	qsort(p, left, pivot - 1);
	qsort(p, pivot + 1, right);
	
}

void swap (struct Node *p, int i, int j) {
	struct Node t;
	t = p[i];
	p[j] = p[i];
	p[i] = t;
}

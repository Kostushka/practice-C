#include <stdio.h>

void qsort (char s[], int startI, int endI);
void swap (char v[], int a, int b);


int main (void) {

	char s[] = {23, 3, 8, 45, 2, 90};

	printf("до сортировки: \n");
	for (int i = 0; i < 6; i++) {
		printf("%d ", s[i]);
	}
	printf("\n");

	qsort(s, 0, 5);

	printf("после сортировки: \n");
	for (int i = 0; i < 6; i++) {
		printf("%d ", s[i]);
	}
	printf("\n");

	return 0;
}

void qsort (char s[], int startI, int endI) {

	if (startI >= endI) {
		return; // если 1 элемент в массиве, выходим
	}

	int pivot, i;

	// меняем местами первый и средний элемент
	swap(s, startI, (startI + endI) / 2);

	pivot = startI;
	
	// пробегаемся и меняем местами элементы
	// те, что меньше среднего, переносим в левый край
	for (i = startI + 1; i <= endI; i++) {
		if (s[i] < s[pivot]) {
			swap(s, ++pivot, i);
		}
	}

	// обратная замена
	swap(s, startI, pivot);

	// левая часть
	qsort(s, startI, pivot - 1);

	// правая часть
	qsort(s, pivot + 1, endI);
}

// поменять местами элементы
void swap (char v[], int a, int b) {
	char c;
	c = v[a];
	v[a] = v[b];
	v[b] = c;
}

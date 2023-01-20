#include <stdio.h>

void qsort (int s[], int startI, int endI);

int main (void) {

	int s[] = {23, 3, 8, 45, 2, 90};

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

void qsort (int s[], int startI, int endI) {

	int mid, i;
	void swap (int v[], int a, int b);

	if (startI >= endI) {
		return; // если 1 элемент в массиве, выходим
	}

	// меняем местами первый и средний элемент
	swap(s, startI, (startI + endI) / 2);

	mid = startI;

	// пробегаемся и меняем местами элементы
	// те, что меньше среднего, переносим в левый край
	for (i = startI + 1; i <= endI; i++) {
		if (s[i] < s[mid]) {
			swap(s, ++mid, i);
		}
	}

	// обратная замена
	swap(s, startI, mid);

	// левая часть
	qsort(s, startI, mid - 1);

	// правая часть
	qsort(s, mid + 1, endI);
}

// поменять местами элементы
void swap (int v[], int a, int b) {
	int c;
	c = v[a];
	v[a] = v[b];
	v[b] = c;
}

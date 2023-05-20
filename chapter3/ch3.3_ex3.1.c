#include <stdio.h>

// Упр. 3.1 Бинарный поиск с одной проверкой внутри функции

int bsearch(int *arr, int item, int n);

int main(void) {

	int arr[] = {1, 4, 9, 23, 89, 345, 1923};
	printf("%d\n", bsearch(arr, 345, sizeof(arr) / sizeof(arr[0])));
	
	return 0;
}

int bsearch(int *arr, int item, int n) {
	int low = 0;
	int high = n - 1;
	int mid = (low + high) / 2;

	while (low <= high && arr[mid] != item) {
		// одна проверка внутри цикла
		if (item < arr[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
		mid = (low + high) / 2;
	}

	if (arr[mid] == item) {
		return mid;
	} else {
		return -1;
	}
}

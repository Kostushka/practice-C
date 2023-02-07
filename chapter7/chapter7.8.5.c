#include <stdio.h>
#include <stdlib.h>
// 7.8.5 Управление памятью

// возвращает указатель на n байт неинициализированной памяти или NULL
void *malloc(size_t n);

// возвращает указатель на участок памяти, достаточный для размещения n объектов размером size или NULL
// память инициализируется нулями
void *calloc(size_t n, size_t size);

// освобождает участок памяти, на который указывает указатель p, полученный вызовом malloc или calloc
// free(p);

int main (void) {
	int *ip;
	int n = 5;
	ip = (int *) calloc(n, sizeof(int));
	free(ip);
	return 0;
}

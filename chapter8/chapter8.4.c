#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

// 8.4 Прямой доступ к файлу и функция lseek

// lseek: передвижение по файлу без считывания и записи данных
// long lseek (int fd, long offset, int origin);
// устанавливает указатель текущей позиции в файле на offset байт от места origin
// origin: 0 - начало файла
// 		   1 - текущая позиция
//         2 - конец файла
// переместить в конец файла
// lseek(fd, 0L, 2);
// переместить в начало файла
// lseek(fd, 0L, 0);

// считывание n байт из позиции pos
int get(int fd, long pos, char *buf, int n);

int main(void) {

	return 0;
}

int get(int fd, long pos, char *buf, int n) {
	// возвращает значение новой текущей позиции или -1
	if (lseek(fd, pos, 0) >= 0) {
		return read(fd, buf, n);
	} else {
		return -1;
	}
}

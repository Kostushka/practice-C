#include <stdio.h>

// 8.1 Дескрипторы файлов
// В UNIX весь ввод-вывод осуществляется через единообразный интерфейс: чтение и запись файлов
// перед чтением или записью необходимо открыть файл
// система проверяет, существует ли файл и есть ли у меня к нему доступ: в случае :) возвращает неотрицательное целое число (дескриптор файла)
// дескриптор файла используется как идентификатор файла (указатель на файл)

// когда программа запускается на исполнение в командной строке, автоматически открываются файлы с дескрипторами 0(поток ввода) 1(поток вывода) 2(поток ошибок)
// перенаправить ввод из файла можно с помощью <
// перенаправить вывод в файл можно с помощью >

int main(void) {
	return 0;
}

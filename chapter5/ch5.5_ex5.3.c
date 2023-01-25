#include <stdio.h>

// Упр. 5.3
// Версия strcat с указателями: копирует строку t в конец строки s

void strcatp (char s[], char t[]);
void strcatp2 (char *s, char *t);
// "hello\0" "hi\0" => "hellohi\0"

int main (void) {
	char s[] = "Hello,";
	char t[] = " world!";
	// strcatp(s, t);
	strcatp2(s, t);
	printf("%s\n", s);
	return 0;
}

void strcatp (char s[], char t[]) {
	int n, k;
	k = 0;
	for (n = 0; s[n] != '\0'; n++);
	while ((s[n++] = t[k++]) != '\0');
	
}

void strcatp2 (char *s, char *t) {
	// доходим до \0 символа первой строки, перемещая указатель
	while (*s != '\0') {
		++s;
	}
	// записываем вторую строку до \0 второй строки, перезаписывая \0 первой строки
	while ((*s++ = *t++) != '\0');
}

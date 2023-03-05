#include <stdio.h>
#include <ctype.h>
#define MAX 100
// Упр.3.3
// Функция expand(s1, s2) -> 
// разворачивает a-z -> abc...xyz
// разворачивает a-b-c -> abc
// разворачивает a-z0-9 -> abc...xyz012...789
// разворачивает -a-z -> -abc...xyz
// учитывать любой регистр
// - в начале и в конце == не символ развертывания

void expand (char s1[], char s2[]);

int main (void) {

	char s1[] = "-a-z0-9";
	char s2[MAX];

	expand(s1, s2);

	printf("%s\n", s2);

    return 0;
}

void expand (char s1[], char s2[]) {

    int i, v;

    i = v = 0; 

    // пропуск - в начале и в конце строки
    if (s1[i] == '-') {
    	++i;
    }

    while (s1[i] != '\0') {
    	for (int n = s1[i]; n <= s1[i+2]; n++) {
    		s2[v++] = n;
    	}    	
    	i += 3;
    }

	s2[v] = '\0';
}

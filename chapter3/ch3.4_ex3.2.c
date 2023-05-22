#include <stdio.h>
#define LIM 100

// Упр. 3.2
// Функция escape(s, t) -> 
// копирует строку t в строку s
// конвертирует символ конца строки -> \n
// конвертирует символ табуляции -> \t

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main (void) {
    char s[LIM];
    char t[] = "H\tel\\gl\to!\n";
    printf("%s", t);
    escape(s, t);
    printf("%s\n", s);
    unescape(s, t);
    printf("%s", s);

    return 0;
}

void escape (char s[], char t[]) {

	int k = 0;

    for (int i = 0; t[i] != '\0'; ++i) {
        switch (t[i]) {
            case '\t':
                s[k++] = '\\';
                s[k++] = 't';
                break;
            case '\n':
                s[k++] = '\\';
                s[k++] = 'n';
                break;
            default: 
                s[k++] = t[i];
                break;
        }
    }
    
    s[k] = '\0';
}

// H'\\''t'ell'\\''t'o!''\\''n'

void unescape(char s[], char t[]) {
	int k = 0;
	for (int i = 0; t[i] != '\0'; i++) {
		if (t[i] == '\\') {
			switch(t[++i]) {
				case 't':
					s[k++] = '\t';
					break;
				case 'n':
					s[k++] = '\n';
					break;
				default:
					s[k++] = t[i - 1];
					s[k++] = t[i];
					break;
			}
		} else {
			s[k++] = t[i];
		}
	}
	s[k] = '\0';
}

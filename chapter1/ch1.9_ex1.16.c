#include <stdio.h>
#define MAX 10
// Упр 1.16
// Программа определения самой длинной строки для какой угодно длины строк входного потока

int mygetline(char s[], int max);
void copy(char max[], char cur[]);

int main (void) {

    char curline[MAX], maxline[MAX];
    int maxn, len;
    len = maxn = 0;

    while ((len = mygetline(curline, MAX)) > 0) {
    	if (maxn < len) {
    		maxn = len;
    		copy(maxline, curline);
    	}
    }
    if (maxn > 0) {
    	printf("%s", maxline);
    }

    return 0;
}

int mygetline(char s[], int max) {
	
	int count, c, i;

	count = i = 0;
	
	while ((c = getchar()) != EOF) {
	
		// пока в буфере есть место
		if (i < max - 1) {
			s[i++] = c;
		}
		
		// считаем количество символов пока не \n
		if (c != '\n') {
			++count;
		} else {
			break;
		}
	}
	
	s[i] = '\0';

	return count;
}

void copy(char max[], char cur[]) {
	int i;
	i = 0;
	while ((max[i] = cur[i]) != '\0') {
		++i;
	}
}

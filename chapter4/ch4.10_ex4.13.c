#include <stdio.h>

// Упр 4.13 
// Рекурсивная версия reverse
// "431\0" => "134\0"

void reverse (char s[], int start, int end);

int main (void) {
	char s[] = "123456789";
	int end;
	for (end = 0; s[end] != '\0'; end++);
	
	printf("%s\n", s);
	reverse(s, 0, end - 1);
	printf("%s\n", s);
	
	return 0;
}

void reverse (char s[], int start, int end) {

	int c;
	// поменять местами [x ... y]
	c = s[start];
	s[start] = s[end];
	s[end] = c;
	
	if (start < end) {
		// передать следующие элементы [y a ... b x] - reverse(a, b)
		reverse(s, ++start, --end);
	}	
	
}

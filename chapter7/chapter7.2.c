#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// 7.2 Форматированный вывод и printf


int main (void) {

	char str[80];
	printf("%6lu\n", 2355557777);
	printf("%.*s\n", 5, "Hello how are you?");

	// помещает результат в символьную строку
	sprintf(str, "lala");
	printf("%s\n", str);


	// ------------------------------------------------

	int x = 10, y = 5;

	int a = 2, b = 3;

	int key;

	int count = 0;
	
	char m[10][20];


	do {

		sprintf(m[0], "###################");
		for (int i = 1; i < 9; i++) {
			sprintf(m[i], "#                 #");
		}
		sprintf(m[9], "###################");

		m[y][x] = '@';
		m[b][a] = '*';

		system("clear");
		
		for (int i = 0; i < 10; i++) {
			printf("%s\n", m[i]);
		}
		printf("%d\n", count);

		if (count == 5) {
			printf("You are winner!!!\n");
			break;
		}

		key = getchar();

		switch (key) {
			case 'j':
				y++;
				break;
			case 'k':
				y--;
				break;
			case 'h':
				x--;
				break;
			case 'l':
				x++;
				break;
			default:
				break;
		}
		
		if (m[y][x] == '#') {
			y = 5;
			x = 10;
		}
		
		if (y == b && x == a) {
			a = rand() * 1.0 / RAND_MAX * 18 + 1;
			b = rand() * 1.0 / RAND_MAX * 8 + 1;
			count++;
		}
	
	} while (key != 'e');
	
	
	// printf("####################\n");
	// sprintf(str, "#                  #");
	// for (int i = 0; i < 10; i++) {
		// printf("%s\n", str);
	// }
	// printf("####################\n");
	
	return 0;
}

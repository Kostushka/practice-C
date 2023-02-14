#include <stdio.h>
#define MAX 100
#define IN 1
#define OUT 0

// Упр 1.13
// Программа вывода гистограммы длин слов во входном потоке

int main (void) {

    int c, i;
    int state = OUT;
    int count[MAX]; // счетчик символов в слове

	i = 0;
	
    for (int j = 0; j < MAX; j++) {
    	count[j] = 0;
    }

    while ((c = getchar()) != EOF) {
        // если не пробельный символ
        if (c != ' ' && c != '\t' && c != '\n') {
        
            // состояние - в слове
            state = IN;
            
            // инкремент счетчика
            ++count[i];
            
        // если пробельный символ и состояние - в слове
        } else if (state == IN) {
        
            // состояние - вне слова
            state = OUT;

            // обнуляем счетчик
            ++i;
        }         
        
    }

    // гистограмма
    for (i = 0; count[i] != 0; i++) {
    	printf("|");
    	while (count[i]-- > 0) {
    		printf("_");
    	}
    	putchar('\n');
    	printf("|\n");
    }
       

    

    return 0;
}

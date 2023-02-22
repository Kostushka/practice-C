#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
#define NUMBER 1

// Упр. 4.4 
// добавить реализацию команд ??? (куда добавить?)
// для вывода верхнего элемента стека без его удаления
// для создания в стеке дубликата элемента
// для обмена местами двух верхних элементов
// для очистки стека

void push (double f);
double pop (void);
int getop (char s[]);
int getch (void);
void ungetch (int c);
double change (void);
double print (void);
void doubl(void);
void clean(void);


int main (void) {
    int typeChar;
    char s[MAX];

    while ((typeChar = getop(s)) != EOF) {
    	switch (typeChar) {
    		case NUMBER: 
    			push(atof(s));
    			break;
    		case '+': 
    			push(pop() + pop());
    			break;
    		case '*':
    			push(pop() * pop());
    			break;
    		case '-':
    			// меняю местами
                change();
    			push(pop() - pop());	
    			break;
    		case '/':
    			// вывожу без удаления из стека
    			if (print() != 0.0) {
    				// меняю местами
    				change();
    				push(pop() / pop());
    			} else {
    				printf("error: / 0");
    			}
    			break;
    		case '^':
    			// дублирую элемент
    			doubl();
    			push(pop() * pop());
    			break;
    		case '\n':
    			printf("result: %g\n", print());
    			// очищаю стек
    			clean();
    			break;
    		default: 
    			printf("error: %s not valid value\n", s);
    			break;
    	}
    	
    }
   
    return 0;
}


double stack[MAX];

int i = 0;

void push (double f) {
    if (i < MAX) {
        stack[i++] = f; 
    } else {
        printf("error: stack full\n");
    }
}
double pop (void) {
    if (i > 0) {
        return stack[--i];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

// вывод верхнего элемента без его удаления
double print (void) {
    if (i > 0) {
        return stack[i - 1];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

// обмен местами двух верхних элементов
double change (void) {
    double t = stack[i - 2];
    stack[i - 2] = stack[i - 1];
    stack[i - 1] = t;
}

// создание в стеке дубликата элемента
void doubl (void) {
    double d = stack[i - 1];
    push(d);
}

// очистка стека
void clean(void) {
    if (i > 0) {
        i = 0;
    }
}

int getop (char s[]) {
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t');

	s[1] = '\0';

	if (!isdigit(c) && c != '.') {
		return c; // не число
	}
	
	i = 0;
	if (isdigit(c)) {
		while (isdigit(s[++i] = c = getch())); 
	}
	if (c == '.') {
		while (isdigit(s[++i] = c = getch()));
	}
	s[i] = '\0';
	if (c != EOF) {
		ungetch(c);
	}
	return NUMBER;
	 	
}

char buf[MAX];
int bufi = 0;

int getch (void) {
	return (bufi > 0) ? buf[--bufi] : getchar();
}

void ungetch (int c) {
	if (bufi < MAX) {
		buf[bufi++] = c;
	} else {
		printf("error: buf full\n");
	}
}

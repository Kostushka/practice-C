#include <stdio.h>
#include <ctype.h>
#define MAX 100
#define NUMBER 1

// 4.3 Внешние переменные
// Программа калькулятор
// (1 - 2) * (4 + 5)

// 1 2 - 4 5 + * обратная польская запись

// 1 2 в стек
// - 
// 1 2 из стека 1 - 2 = -1
// -1 в стек
// 4 5 в стек
// +
// 4 5 из стека 4 + 5 = 9
// 9 в стек
// * 
// -1 9 из стека -1 * 9 = -9
// -9 в стек
// \n
// -9 из стека


void push (double f);
double pop (void);
int getop (char s[]);
double atof (char s[]);
int getch (void);
void ungetch (int c);

int main (void) {
	// тип символа из входного потока
    int typeChar;
    // массив, куда записывается число
    char s[MAX];
    // для записи операнда
    double op2;

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
    			op2 = pop();
    			push(pop() - op2);	
    			break;
    		case '/':
    			op2 = pop();
    			if (op2 != 0.0) {
    				push(pop() / op2);
    			} else {
    				printf("error: / 0");
    			}
    			break;
    		case '\n':
    			printf("result: %g\n", pop());
    			break;
    		default: 
    			printf("error: %s not valid value\n", s);
    			break;
    	}
    	
    }
   
    return 0;
}


// стек
double stack[MAX];

// индекс в стеке
int i = 0;

// добавить в стек
void push (double f) {
    if (i < MAX) {
        stack[i++] = f; 
    } else {
        printf("error: stack full\n");
    }
}

// удалить из стека
double pop (void) {
    if (i > 0) {
        return stack[--i];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

// строка -> число
double atof (char s[]) {

	int i, sign, flag, count;
	double res, pow;

	for (i = 0; isspace(s[i]); i++);

	sign = s[i] == '-' ? -1 : 1;
	if (s[i] == '-' || s[i] == '+') {
		++i;
	}

	res = flag = count = 0;

	while (s[i] != '\0') {
		if (s[i] == '.') {
			flag = 1;
			++i;
			continue;
		}
		if (flag) {
			++count;
		}
		res = res * 10 + (s[i] - '0');
		++i;
	}
	
	pow = 1;
	while (count-- > 0) {
		pow = pow * 10;
	}
	return sign * res / pow;
	
}

// возвращает корректный символ из входного потока
int getop (char s[]) {
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t');

	s[1] = '\0';

	if (!isdigit(c) && c != '.') {
		return c; // не число
	}
	
	i = 0;
	if (isdigit(c)) {
		// если первый символ цифра - заменяем нулевой символ и добавляем следующие, пока они числовые
		while (isdigit(s[++i] = c = getch())); 
	}
	if (c == '.') {
		// если первый нечисловой символ после числовых - точка, повторяем запись числовых смволов до первого нечислового
		while (isdigit(s[++i] = c = getch()));
	}
	// перезаписываем нечисловой символ
	s[i] = '\0';
	if (c != EOF) {
		// если нечисловой символ - не конец файла - записываем в буфер, с которого начнем извлечение следующего символа
		ungetch(c);
	}
	return NUMBER; // работаем с числом
	 	
}

// буфер для нечисловых символов, идущих после числовых
char buf[MAX];
int bufi = 0;

int getch (void) {
	// если буфер пуст, возвращаем символ из входного потока
	// иначе символ из буфера
	return (bufi > 0) ? buf[--bufi] : getchar();
}

void ungetch (int c) {
	if (bufi < MAX) {
		// добавляем нечисловой символ в буфер
		buf[bufi++] = c;
	} else {
		printf("error: buf full\n");
	}
}

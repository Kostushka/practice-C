#include <stdio.h>
#define MAX 100

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

// стек
char stack[MAX];
// индекс в стеке
int index = 0;

void push (double f);
double pop (void);
int getop (char s[]);

int main (void) {
    int c;
   
    return 0;
}

// добавить в стек
void push (double f) {
    if (index < MAX) {
        stack[index++] = f; 
    } else {
        printf("error: stack full");
    }
}
// удалить из стека
double pop (void) {
    if (index > 0) {
        return stack[--index];
    } else {
        printf("error: stack empty");
        return 0.0;
    }
}
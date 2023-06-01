#include <stdio.h>
#define MAX 100

// 6.8 Объединения
// Объединение - переменная, которая может содержать объекты разных типов и размеров 
// занимают одинаковый объем в памяти - u имеет достаточную длину, чтобы содержать самый большой тип
// то есть u можно присваивать данные любого из трех типов
union u_tag {
	int ival;
	float fval;
	char *sval;
} u;

struct {
	int utype;
	int flag;
	char *name;
	union {
		int ival;
		float fval;
		char *sval;
	} u;
} symtab[MAX];


int main (void) {

	symtab[0].u.ival = 25;
	symtab[1].u.sval = "string";
	// symtab[1].u.sval[0];
	symtab[2].u.fval = 123.89;
	
	printf("%d\n", symtab[0].u.ival);
	printf("%c\n", *symtab[1].u.sval);
	printf("%.2f\n", symtab[2].u.fval);

	return 0;
}

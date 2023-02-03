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

	symtab[0].u.ival;
	*symtab[0].u.sval;
	symtab[0].u.sval[0];

	return 0;
}

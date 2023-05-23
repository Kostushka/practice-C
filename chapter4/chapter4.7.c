#include <stdio.h>

// 4.7 Регистровые переменные - для помещения частоиспользуемых переменных в регистры CPU, для увеличения быстродействия
// только для автоматических переменных и параметров функций

int f (register int p);

int main (void) {

	register int x;
	register char c;

	return 0;
}

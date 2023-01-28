#include <stdio.h>
#include <math.h>
// 6.1 Структуры
// Структура - совокупность нескольких переменных, сгруппированных под единым именем

int main (void) {

	// структура: точка с координатами
	// point - метка структуры (идентификатор)
	// описание формы структуры: не выделяется память
	struct point {
		// поля структуры
		int x;
		int y;
	};

	// переменная pt, имеющая тип struct point: выделяется память
	struct point pt;

	// инициализация структуры
	struct point maxpt = {300, 400};

	// обращение к элементам структуры
	printf("%d %d\n", maxpt.x, maxpt.y);

	// вычислить расстояние от начала координат (0, 0) до точки (300, 400)
	double dist;
	dist = sqrt(sqrt((double) maxpt.x) + sqrt((double) maxpt.y));
	printf("dist: %g\n", dist);

	// прямоугольник: вложенные структуры
	struct rect {
		struct point pt1;
		struct point pt2;
	};

	struct rect screen;
	screen.pt1.x;

	return 0;
}

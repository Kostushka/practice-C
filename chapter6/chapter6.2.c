#include <stdio.h>
#define min(x, y) ((x < y) ? x : y);
#define max(x, y) ((x > y) ? x : y);

// 6.2 Структуры и функции

// makepoint: принимает два целых числа и возвращает структуру Point
struct Point makepoint (int x, int y);

// addpoint: сложение координат точек
struct Point addpoint (struct Point pt1, struct Point pt2);

// canonrect: приведение координат прямоугольника к каноничному виду
struct Rect canonrect (struct Rect r);

// структура
struct Point {
	int x; // переменная типа int
	int y;
};

struct Rect {
	struct Point pt1; // переменная типа cтруктура Point
	struct Point pt2;
};

// ptinrect: проверяет находится ли точка в прямоугольнике
int ptinrect (struct Point p, struct Rect r);

int main (void) {

	struct Rect screen;
	struct Point middle;
	struct Rect noncanonrect;
	struct Point *pp; // объявили указатель на структуру
	pp = &middle; // записали адрес структуры
	printf("(%d %d)\n", (*pp).x, (*pp).y); 
	printf("(%d %d)\n", pp->x, pp->y); // идентичная запись для указателя на элемент структуры

	noncanonrect.pt1.x = 5;
	noncanonrect.pt2.x = 2;
	noncanonrect.pt1.y = 8;
	noncanonrect.pt2.y = 1;

	printf("(%d %d) (%d %d)\n", noncanonrect.pt1.x, noncanonrect.pt1.y, noncanonrect.pt2.x, noncanonrect.pt2.y);
	noncanonrect = canonrect(noncanonrect);
	printf("(%d %d) (%d %d)\n", noncanonrect.pt1.x, noncanonrect.pt1.y, noncanonrect.pt2.x, noncanonrect.pt2.y);
	
	screen.pt1 = makepoint(0,0);
	screen.pt2 = makepoint(5,5);
	
	middle = makepoint((screen.pt1.x + screen.pt2.x) / 2, (screen.pt1.y + screen.pt2.y) / 2);
	struct Point a = makepoint(6, 7);

	struct Point ab = addpoint(middle, middle);
	
	printf("(%d %d) (%d %d)\n", screen.pt1.x, screen.pt1.y, screen.pt2.x, screen.pt2.y);
	printf("(%d %d)\n", middle.x, middle.y);
	printf("(%d %d)\n", ab.x, ab.y);
	printf("(%d %d)\n", middle.x, middle.y);
	printf("in rect: %d\n", ptinrect(middle, screen));
	printf("in rect: %d\n", ptinrect(a, screen));
	
	return 0;
}

struct Point makepoint (int x, int y) {
	// объявление структуры
	struct Point temp = {x, y};

	// temp.x = x;
	// temp.y = y;

	return temp;
}

// передача по значению
struct Point addpoint (struct Point pt1, struct Point pt2) {

	pt1.x += pt2.x;
	pt1.y += pt2.y;

	return pt1;
}

int ptinrect (struct Point p, struct Rect r) {

	return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}


struct Rect canonrect (struct Rect r) {
	struct Rect temp;
	temp.pt1.x = min(r.pt1.x, r.pt2.x);
	temp.pt1.y = min(r.pt1.y, r.pt2.y);
	temp.pt2.x = max(r.pt1.x, r.pt2.x);
	temp.pt2.y = max(r.pt1.y, r.pt2.y);
	return temp;
}

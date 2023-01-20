
// 4.11.2 Макроподстановки - макроопределения - макросы
// действует от точки определения до конца файла
// #define имя текст_для_замены

// #define AGE 24 
// #define forever for(;;)

// макрос с аргументами
// #define max(A, B) ((A) > (B) ? (A) : (B))
// x = max(q+r, s+t) => x = ((q+r) > (s+t) ? (q+r) : (s+t))
// создает проблемы, если x = max(i++, j++); 

// getchar() putchar() - макросы из <stdio.h>
// #undef getchar =>  getchar - функция, а не макрос
// int getchar(void){...}

// #арг в кавычках
// #define dprint(expr) printf(#expr " %g\n", expr);
// dprint(x/y); => printf("x/y %g\n", x/y);

// породить идентификатор
// #define paste(front, back) front ## back
// paste(name, 1) => name1


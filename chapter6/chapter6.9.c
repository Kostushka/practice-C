
// 6.9 Битовые поля
// Пример: набор однобитовых флажков-переключателей
// возможность обращаться к отдельным фрагментам машинного слова
// набор "масок" - битовые позиции в переменной
#define KEYWORD 01
#define EXTERNAL 02
#define STATIC 04
// или
// enum {KEYWORD = 01, EXTERNAL = 02, STATIC = 04};

unsigned int flags = ~0;
// установить равным 1 биты EXTERNAL и STATIC в flags
flags |= EXTERNAL | STATIC;
// установить равным 0 биты EXTERNAL и STATIC в flags
flags &= ~(EXTERNAL | STATIC);

// НО можно обойтись и без поразрядных операций
// внутри "слова" можно задать битовое поле - последовательность битов
struct {
	unsigned int is_keyword : 1;
	unsigned int is_external : 1;
	unsigned int is_static : 1;
} flags2;

flags2.is_external = flags2.is_static = 0;

int main (void) {
	return 0;
}

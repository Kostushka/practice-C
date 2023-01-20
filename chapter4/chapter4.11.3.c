
// 4.11.3 Условное включение
// управление препроцессорной обработкой

// включение файла hdr в текст программы не более одного раза
// #ifndef(HDR)
// #define HDR
// /* содержимое hdr.h */
// #endif

// #if SYSTEM == SYSV
// 	#define HDR "sysv.h"
// #elif SYSTEM == BSD
// 	#define HDR "bsd.h"
// #else 
// 	#define HDR "default.h"
// #endif
// #include HDR

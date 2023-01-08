#include <stdio.h>

// Программа вывода длины всех строк из входящего потока

int main (void) {

    int c, count;

    count = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            printf("%d\n", count);
            count = 0;
        } else {
            ++count;
        }  
    }

    return 0;
}




// int main (void) {

//     int c, i;
//     i = 0;

//     while ((c = getchar()) != EOF) {
//         if (c != '\n') {
//             ++i;
//         } else {
//             printf("%d\n", i);
//             i = 0;
//         }
       
//     }

//     return 0;
// }

// int main (void) {

//     int c, i;
//     i = 0;

//     while ((c = getchar()) != EOF) {
//         if (c != '\n') {
//             ++i;
//             continue;
//         } 

//         if (i > 80) {
//             printf("%d\n", i);
//         }

//         i = 0; 
       
//     }

//     return 0;
// }
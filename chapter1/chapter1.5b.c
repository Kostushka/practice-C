#include <stdio.h>

// 1.5.2 Подсчет символов

int main (void) {

    long nc = 0;
    double nc2;

    // 1. вариант через while
    while (getchar() != EOF) {
        ++nc;
    }
    printf("nc: %ld\n", nc);

    // 2. вариант через for
    for (nc2 = 0; getchar() != EOF; ++nc2); // телло цикла не нужно, потому ;
    printf("nc2: %.0f\n", nc2);

    return 0;
}
#include <stdio.h>

// 3.3 Конструкция else if

/* 
if (...) 
    оператор
else if (...)
    оператор
else if (...) 
    оператор
esle
    оператор

*/

int binSearch (char s[], int item);

int main (void) {

    int num = 34;
    char s[20];

    for (int i = 0; i < 19; i++) {
        s[i] = num;
        num = num + 2;
    }
    s[19] = '\0';

    printf("%d\n", binSearch(s, 45));
    return 0;
}

int binSearch (char s[], int item) {
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        ++count;
    }
    int low = 0;
    int high = count;

    while (low <= high) {
        int n = (low + high) / 2;
        if (s[n] == item) {
            return n;
        } else if (s[n] > item) {
            high = n - 1;
        } else {
            low = n + 1;
        }
    }
    return -1;
}
// int binSearch (char s[], int item, int n);

// int main (void) {

//     int num = 34;
//     char s[20];

//     for (int i = 0; i < 20; i++) {
//         s[i] = num;
//         num = num + 2;
//     }

//     printf("%d\n", binSearch(s, 40, 20));
//     return 0;
// }

// int binSearch (char s[], int item, int n) {
//     int low = 0;
//     int high = n - 1;

//     while (low <= high) {
//         int mid = (low + high) / 2;
//         if (s[mid] == item) {
//             return mid;
//         } else if (s[mid] > item) {
//             high = mid - 1;
//         } else {
//             low = mid + 1;
//         }
//     }
//     return -1;
// }
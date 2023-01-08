#include <stdio.h>
#include <ctype.h>

// Программа, которая преобразует строку 16-чных цифр в число

int htoi (char s[]);

int main (void) {

    char s[] = "F";

    printf("%x\n", htoi(s));

    return 0;
}


int htoi (char s[]) {
    int i, n;

    n = 0x0;

    if (s[0] == '0' && tolower(s[1]) == 'x') {
        for (i = 2; s[i] >= '0' && s[i] <= '9' || tolower(s[i]) >= 'a' && tolower(s[i]) <= 'f'; ++i) { 
            if (s[i] >= '0' && s[i] <= '9') {
                n = n * 10 + (s[i] - '0');
            } else {
                n = n * 10 + s[i];
            }
        }
    } else {
        for (i = 0; s[i] >= '0' && s[i] <= '9' || tolower(s[i]) >= 'a' && tolower(s[i]) <= 'f'; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                n = n * 10 + (s[i] - '0');
            } else {
                n = n * 10 + s[i];
            }
        }
    }
  
    

    printf("%s %x \n", s, n );

    return n;
}
// int htoi (char s[]) {
//     int i, n;

//     n = 0x0;

//     if (s[i] >= '0' && s[i] <= '9') {
//         for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) {
//             n = n * 10 + (s[i] - '0');
//         }
//     } else if (tolower(s[i]) >= 'a' && tolower(s[i]) <= 'f') {
//         n = n * 10 + s[i];
//     }    

//     return n;
// }
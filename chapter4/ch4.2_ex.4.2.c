#include <stdio.h>
#include <ctype.h>

// Упр. 4.2 
// atof, которая понимает экспоненциальную запись
// 123.45e-6 -> 123.45 -> E e -> знак -6/6

double atof (char s[]);

int main (void) {
    return 0;
}

double atof (char s[]) {
    int i, sign, flag, count;
    double res, pow;
    
    // n = 0;
    // for (i = 0; s[i] != '\0'; i++) {
    //     j = i;
    //     if (s[i] == 'e' || s[i] == 'E') {
    //         sign = (s[j++] == '-') ? -1 : 1;
    //         n += s[j++];
    //     }
    // }

    for (i = 0; isspace(s[i]); i++); 

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+') {
        ++i;
    }

    flag = count = res = 0;

    while (s[i] != '\0') {
    
        if (s[i] == '.') {
            flag = 1;
            ++i;
            continue;
        }
        if (flag) {
            ++count;
        }
        res = res * 10 + (s[i] - '0');
    }

    pow = 1;
    while (count-- > 0) {
        pow = pow * 10;
    }

    res = sign * res / pow;
    
}
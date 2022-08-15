#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INVALID_BASE_EXIT_CODE 1

void itob(int n, char s[], int b);
int stringLength(char s[]);
void reverse(char s[]);

int main() {

    char string[20];

    printf("INT_MIN: %d\n", 22087);
    itob(22087, string, 16);
    itob(22087, string, 3);
    printf("Result: %s\n", string);

    return 0;
}

// 36 symbols to use => so base 36 is the maximal one
void itob(int n, char s[], int base) {
    int i, digit;
    int sign = n;

    if(base < 2 || base > 36) {
        fprintf(stderr, "ERROR: Not supported base - %d", base);
        exit(INVALID_BASE_EXIT_CODE);
    }

    i = 0;
    do {
        digit = abs(n % base);

        s[i++] = digit > 9 ? ((digit - 10) + 'A') : (digit + '0');
    } while( n /= base);

    if(sign < 0) s[i++] = '-';

    s[i] = '\0';

    reverse(s);
}

int stringLength(char s[]) {
    int i;
    for(i = 0; s[i] != '\0'; ++i);

    return i;
}

void reverse(char s[]) {
    int c, i, j;

    for(i = 0, j = stringLength(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

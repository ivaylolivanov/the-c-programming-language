#include <stdlib.h>

void itoa(int number, const char* result, int field_limit);

int main()
{
    int n;
    char string[20] = "123442\0";

    itoa(n, string, 4);

    return 0;
}

void itoa(int number, const char* result, int field_limit)
{
    do {
    } while (number /= 10);
}

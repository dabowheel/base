#include <stdio.h>

#define IMPORT_FROM_BASE
#include "base.h"

int main()
{
    string s;
    int count = 0;
    while ((s = getline(stdin))) {
        count++;
        sdestroy(s);
    }

    printf("line count is %d\n", count);
    return 0;
}
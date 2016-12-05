#include <stdio.h>
#include "print_helper.h"

int print_ascii_tbl(FILE *stream)
{
    for (char c = ' '; c <= '~'; c++) {
        if (!fprintf(stream, "%c ", c)) {
            return 0;
        }
    }

    return fprintf(stream, "\n");
}
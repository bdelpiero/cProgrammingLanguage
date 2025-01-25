#include <stdio.h>

// (not my solution) Copied this one from the wiki

/* Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b,
and each backslash by \\. This makes tabs and backspaces visible in an unambiguous way. */

int main(){

    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            putchar('\\');
            c = 't';
        }
        if (c == '\b')
        {
            putchar('\\');
            c = 'b';
        }
        if (c == '\\')
        {
            putchar('\\');
            c = '\\';
        }
        
        putchar(c);
        
    }
    
    return 0;
}

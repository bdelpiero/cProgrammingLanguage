#include <stdio.h>

/* Program that replaces each string of one or
more blanks by a single blank */
int main()
{
  int c, last_char;
  while ((c = getchar()) != EOF) {
    if (c != ' ' || last_char != ' ') {
      putchar(c);
      last_char = c;
    }
  }
}

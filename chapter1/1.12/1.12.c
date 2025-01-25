#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */ 

// program that prints input one word per lien
int main() {
  int c, state;

  state = OUT;
  while ((c = getchar()) != EOF) {
    if (c != ' ' && c != '\n' && c != '\t') {
      // we are inside a word
      putchar(c);
      state = IN;
    } else if (state == IN ) {
      // we were inside a word until last char
      putchar('\n');
      // guarantees we should not write more than one consecutive new line
      state = OUT;
    }
  }

  return 0;
}


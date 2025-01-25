#include <stdio.h>
int main()
{
  int c, nl, t, s;
  nl = t = s = 0;
  while ((c = getchar()) != EOF)
    if (c == '\n')
      ++nl;
    if (c == '\t')
      ++t;
    if (c == ' ')
      ++s;
  printf("Total #  of new lines: %d\n", nl);
  printf("Total # of tabs: %d\n", nl);
  printf("Total # of spaces: %d\n", nl);
}

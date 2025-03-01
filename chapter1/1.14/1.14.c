#include <stdio.h>

// TODO: use only relevant chars, from 33 to 126
#define TOTAL_ASCII_CHARS 127

// program that prints a histogram of the frequences of different chatacter in its input
int main() {
  // TODO: should only include printable chars (from 33 to 126)
  int char_frequency[TOTAL_ASCII_CHARS] = {0}; // initialize all values to 0
  int c, max_char_frequency;
  max_char_frequency = 0;

  // track chars frecquency
  while ((c = getchar()) != EOF) {
    // TODO: should skip unprintable chars
    if (++char_frequency[c] > max_char_frequency) 
      max_char_frequency = char_frequency[c];
  }

  int i, j, h_x_axis_min, h_x_axis_max;

  // TODO: include only printable characters
  h_x_axis_min = 33;
  h_x_axis_max = TOTAL_ASCII_CHARS - 1;

  // print the y-axis
  for (i = max_char_frequency; i > 0; i--) {
    printf("%3d| ", i);

    for (j = h_x_axis_min; j <= h_x_axis_max; j++) {
      if (char_frequency[j] >= i) {
        printf("# ");
      } else {
        printf("  ");
      }
    }

    printf("\n");
  }

  // print the x-axis
  printf("F/C  ");
  for (i = h_x_axis_min; i <= h_x_axis_max; i++) {
    printf("%c ", i);
  }

  printf("\n");

  return 0;
}

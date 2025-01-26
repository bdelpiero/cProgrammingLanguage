#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */ 
#define MAX_ENGLISH_WORD_LENGTH 45 /* kind of arbitrary. should use smth better than a constant */

// program that prints a histogram of the length of words of its input
int main() {
  int c, i, j, state, current_word_length, max_word_count;
  int word_count_by_length[MAX_ENGLISH_WORD_LENGTH];

  current_word_length = 0;
  state = OUT;
  for (i = 0; i < MAX_ENGLISH_WORD_LENGTH; ++i)
    word_count_by_length[i] = 0; 

  // track words by length
  while ((c = getchar()) != EOF) {
    if (c != ' ' && c != '\n' && c != '\t') {
      // we are inside the current word
      ++current_word_length;
      state = IN;
    } else if (state == IN ) {
      // we just left a word
      if (current_word_length == MAX_ENGLISH_WORD_LENGTH) {
        // avoid array overflow errors
        printf("Encountered a word that exceeds max expected length. Exiting\n");
        return 1;
      }
      ++word_count_by_length[current_word_length - 1];
      current_word_length = 0;
      state = OUT;
    }
  }

  int h_start, h_end, initialized;
  h_start = h_end = max_word_count=  0;

  // define the range of the histogram
  for (i = 0; i < MAX_ENGLISH_WORD_LENGTH; i++) {
    if (word_count_by_length[i] != 0) {
      h_end = i;
      if (initialized == 0) {
        // The first position with an amount
        h_start = i;
        initialized = 1;
      }
      if (word_count_by_length[i] > max_word_count) {
        // The most frequent length (rename to most_frequent-length?)
        max_word_count = word_count_by_length[i];
      }
    }
  }

  // print the y-axis
  for (i = max_word_count; i > 0; i--) {
    if (i > 9) {
      printf("%d | ", i);
    } else {
      printf("0%d | ", i);
    }
    
    for (j = h_start; j <= h_end; j++) {
      if (word_count_by_length[j] >= i) {
        printf("#  ");
      } else {
        printf("   ");
      }
      
      if (i > 10) {
        // add extra padding wo the x-axis is alligned
        printf(" ");
      }
    }

    printf("\n");
  }


  // print the x-axis
  printf("F/L  ");
  for (i = h_start; i <= h_end; i++) {
    printf("0%d ", i + 1);
  }

  return 0;
}


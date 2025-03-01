#include <stdio.h>

int fahr_to_celsius(int fahr);

/* print Fahrenheit-Celsius table
 for fahr = 0, 20, ..., 300 */
int main()
{
  int fahr, celsius;
  int lower, upper, step;
  lower = 0; /* lower limit of temperature scale */
  upper = 300; /* upper limit */
  step = 20; /* step size */
  fahr = lower;
  while (fahr <= upper) {
    celsius = fahr_to_celsius(fahr);
    printf("%d\t%d\n", fahr, celsius);
    fahr = fahr + step;
  }
} 

int fahr_to_celsius(int fahr) {
  return 5 * (fahr-32) / 9;
}

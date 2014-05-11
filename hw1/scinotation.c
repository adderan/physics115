#include <stdio.h>
#include <math.h>

int main() {
  double num = 19000000000;
  printf("%2.1e \n", num);

  double goldenmean = (sqrt( (double)5) - 1)/2;
  printf("The value of the golden mean is %0.8f \n", goldenmean);
  return 0;
}

#include <stdio.h>

main() {

  float e = 1.0;
  int i;
  printf("epsilon  1 - (1 - epsilon)");
  for(i = 0; i < 10; i++) {
    float x = 1 - e;
    float y = 1 - x;
    printf("%1.5e %1.5e \n", e, y);
    e = e/10;
  }
  printf("================================= \n");

  double e1 = 1.0;
  for(i = 0; i < 20; i++) {
    double x = 1 - e1;
    double y = 1 - x;
    printf("%1.5e %1.5e \n", e1, y);
    e1 = e1/10;
  }
}


#include <stdio.h>

main() {
  float minfloat = 1.0;
  int i;
  printf("Single precision: \n");
  while(minfloat != 0) {
    minfloat = minfloat/10;
    printf("%e \n", minfloat);

  }
  printf("Double precision: \n");
  double mindouble = 1.0;
  while(mindouble != 0) {
    mindouble = mindouble/10;
    printf("%e \n", mindouble);

  }
}

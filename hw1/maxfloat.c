#include <stdio.h>
#include <float.h>

main() {
  float maxfloat = 1.0;
  int i;
  for(i = 0; i < 40; i++) {
    printf("%e \n", maxfloat);
    maxfloat = maxfloat*10.0;
  }

  double maxdouble = 1.0;
  for(i = 0; i < 310; i++) {
    maxdouble = maxdouble*10.0;
    printf("%e \n", maxdouble);
  }
 

}

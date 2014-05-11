#include <stdio.h>
#include <math.h>

main() {

  int p;
  double s_up_error[8] = {};
  double s_down_error[8] = {};

  printf("             Single precision                                                 Double precision \n");
  for(p = 2; p < 8; p++) {
    int N = (int)pow(10.0, (double)p);
    float s_up_float = 0.0;
    double s_up_double = 0.0;
    int i;
    for(i = 1; i < N+1; i++) {
      s_up_float += (float)1/i;
      s_up_double += (double)1/i;
    }
    s_up_error[p] = ((double)s_up_float - s_up_double)/(s_up_double)
;
    float s_down_float = 0.0;
    double s_down_double = 0.0;
    for(i = N; i > 0; i--) {
      s_down_float += (float)1/i;
      s_down_double += (double)1/i;
    }
    s_down_error[p] = ((double)s_down_float - s_down_double)/s_down_double;

    printf("N = %10d S(up) = %10f   S(down) = %10f     S(up) = %10f  S(down) = %10f \n", N, s_up_float, s_down_float, s_up_double, s_down_double);
    
  }
  printf("\n");
  int i;
  for(i = 2; i < 8; i++) {
    printf("p = %5d  S(up) error =  %10f  S(down) error = %10f \n", i, s_up_error[i], s_down_error[i]);
  }

}


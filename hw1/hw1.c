#include <stdio.h>
int main() {
  printf("Hello, world \n");
  return 0;
}

Output:

Hello, world 



___________________________________________________________

#include <stdio.h>
#include <math.h>

int main() {
  double num = 19000000000;
  printf("%2.1e \n", num);

  double goldenmean = (sqrt( (double)5) - 1)/2;
  printf("The value of the golden mean is %0.8f \n", goldenmean);
  return 0;
}

Output:

1.9e+10 
The value of the golden mean is 0.61803399 

____________________________________________________________________________________

#include <stdio.h>

main() {

  int num = 0;
  double correctNum = 0;
  int i;
  for(i = 1; i < 34; i++) {
    num = 2*num + 1;
    correctNum = 2*correctNum + 1.0;
    char *iscorrect = "wrong";
    if((double)num == correctNum) {
      iscorrect = "correct";
    }

    printf(" %12d 2^%2d -1 %7s \n", num, i, iscorrect); 
  }
}


Output:

    134217727 2^27 -1 correct 
    268435455 2^28 -1 correct 
    536870911 2^29 -1 correct 
   1073741823 2^30 -1 correct 
   2147483647 2^31 -1 correct 
           -1 2^32 -1   wrong 
           -1 2^33 -1   wrong 
_________________________________________________________________________________________

#include <stdio.h>
#include <float.h>

main() {
  float maxfloat = 1.0;
  int i;
  printf("Single precision: \n");
  for(i = 0; i < 40; i++) {
    printf("%e \n", maxfloat);
    maxfloat = maxfloat*10.0;
  }
  printf("Double precision: \n");
  double maxdouble = 1.0;
  for(i = 0; i < 310; i++) {
    maxdouble = maxdouble*10.0;
    printf("%e \n", maxdouble);
  }
 

}

Output:

Single precision:
.....
,,,,
.....
1.000000e+34 
1.000000e+35 
1.000000e+36 
1.000000e+37 
1.000000e+38 
inf
Double precision:
......
......
......
1.000000e+305 
1.000000e+306 
1.000000e+307 
1.000000e+308 
inf 

____________________________________________________________________________________

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


Output:
..........
1.000527e-42 
9.949219e-44 
9.809089e-45 
1.401298e-45 
0.000000e+00
Double precision:
..........

9.999889e-321 
9.980126e-322 
9.881313e-323 
9.881313e-324 
0.000000e+00

_____________________________________________________________________

#include <stdio.h>

main() {

  float e = 1.0;
  int i;
  printf("epsilon  1 - (1 - epsilon) \n");
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


Output:

epsilon  1 - (1 - epsilon)
1.00000e+00 1.00000e+00 
1.00000e-01 1.00000e-01 
1.00000e-02 9.99999e-03 
1.00000e-03 9.99987e-04 
1.00000e-04 1.00017e-04 
1.00000e-05 1.00136e-05 
1.00000e-06 1.01328e-06 
1.00000e-07 1.19209e-07 
1.00000e-08 0.00000e+00 
1.00000e-09 0.00000e+00 
================================= 
1.00000e+00 1.00000e+00 
1.00000e-01 1.00000e-01 
1.00000e-02 1.00000e-02 
1.00000e-03 1.00000e-03 
1.00000e-04 1.00000e-04 
1.00000e-05 1.00000e-05 
1.00000e-06 1.00000e-06 
1.00000e-07 1.00000e-07 
1.00000e-08 1.00000e-08 
1.00000e-09 1.00000e-09 
1.00000e-10 1.00000e-10 
1.00000e-11 1.00000e-11 
1.00000e-12 9.99978e-13 
1.00000e-13 1.00031e-13 
1.00000e-14 9.99201e-15 
1.00000e-15 9.99201e-16 
1.00000e-16 1.11022e-16 
1.00000e-17 0.00000e+00 
1.00000e-18 0.00000e+00 
1.00000e-19 0.00000e+00 

____________________________________________________________________________________

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

Output:


             Single precision                                                 Double precision 
N =        100 S(up) =   5.187378   S(down) =   5.187377     S(up) =   5.187378  S(down) =   5.187378 
N =       1000 S(up) =   7.485478   S(down) =   7.485472     S(up) =   7.485471  S(down) =   7.485471 
N =      10000 S(up) =   9.787613   S(down) =   9.787604     S(up) =   9.787606  S(down) =   9.787606 
N =     100000 S(up) =  12.090851   S(down) =  12.090153     S(up) =  12.090146  S(down) =  12.090146 
N =    1000000 S(up) =  14.357358   S(down) =  14.392652     S(up) =  14.392727  S(down) =  14.392727 
N =   10000000 S(up) =  15.403683   S(down) =  16.686031     S(up) =  16.695311  S(down) =  16.695311 

p =     2  S(up) error =    0.000000  S(down) error =  -0.000000 
p =     3  S(up) error =    0.000001  S(down) error =   0.000000 
p =     4  S(up) error =    0.000001  S(down) error =  -0.000000 
p =     5  S(up) error =    0.000058  S(down) error =   0.000001 
p =     6  S(up) error =   -0.002457  S(down) error =  -0.000005 
p =     7  S(up) error =   -0.077365  S(down) error =  -0.000556 


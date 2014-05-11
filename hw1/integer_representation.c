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

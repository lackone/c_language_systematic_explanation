#include <stdio.h>

int main(void) {
      int a = 10;
      int b = 20;
      int *const cp = &a;
      //cp是常理，不能改
      //cp = &b;

      const int* cp2 = &a;
      cp2 = &b;
      //cp2指向的不能改
      //*cp2 = 30;

      //指针本身不能改，指针指向的也不能改
      const int* const cp3 = &a;
      //cp3 = &b;
      //*cp3 = 30;

    return 0;
}
#include <stdio.h>

int main( void) { /* printf-eks.c */
  int i = 10;
  short j = 5;
  long k = 111L;
  printf("i: %d, j: %3hd, k: %10.5ld\n", i, j, k);

  double x = 10.5;
  float y = 5.5F;
  long double z = 111.75L;
  printf("x: %f, y: %5.2f, z: %Le\n", x, y, z);

  char c = 'A';
  char d = 'a';
  printf("c: %c, d: %d\n", c, d);

  char *s = "Computer", *t = "C";
  printf("s: %s,\nt: %s\n", s, t);  

  return 0;
}

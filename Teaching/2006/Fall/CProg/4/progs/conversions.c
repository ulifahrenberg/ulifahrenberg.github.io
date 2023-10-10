#include <stdio.h>

int main( void) {
  unsigned short a= 45, b= 50;
  printf( "a-b = %d\n", a-b);

  float c= 4.56; double d= 123456.789;
  printf( "c+d = %f\n", c+d);

  double e= 3.14159; int pi;
  pi= e;
  printf( "pi = %d\n", pi);

  return 0;
}

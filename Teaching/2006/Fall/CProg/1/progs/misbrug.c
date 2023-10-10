#include <stdio.h>

int main( void) {
  int a, b, c;
  a= b= c= 7;
  printf( "a: %d, b: %d, c: %d\n", a, b, c);
  a= 1+( b= 2*( c= 3));
  printf( "a: %d, b: %d, c: %d\n", a, b, c);
  return 0;
}

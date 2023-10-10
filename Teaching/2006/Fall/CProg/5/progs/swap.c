#include <stdio.h>

void swap( int *x, int *y);

int main( void) {
  int a= 3, b= 7;

  printf( "Before: %d %d\n", a, b);
  swap( &a, &b);
  printf( "After:  %d %d\n", a, b);

  return 0;
}

void swap( int *x, int *y) {
  int tmp;
  tmp= *x;
  *x= *y;
  *y= tmp;
}

#include <stdio.h>

int nextSquare( void) {
  static int s= 0;
  s++;
  return s*s;
}

int main( void) {
  int i;
  for( i= 1; i<= 10; i++)
    printf( "%d\n", nextSquare());
  return 0;
}


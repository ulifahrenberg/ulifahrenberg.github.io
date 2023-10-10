#include <stdio.h>
int main( void) {  /* for.c */
  int i= 1;

  printf( "%d elefant\n", i);
  for( i= 2; i<=10; ) {
    printf( "%d elefanter\n", i);
    i++;
  }
  return 0;
}

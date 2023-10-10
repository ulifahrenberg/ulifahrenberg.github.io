#include <stdio.h>

unsigned long fakultet( unsigned long n);

int main( void) {  /* fak.c */
  unsigned long tal;

  printf( "\nEnter a number: ");
  scanf( "%lu", &tal);

  printf( "\nThe factorial of %lu is %lu\n", tal, fakultet( tal));

  return 0;
}

/* Compute factorial of n */
unsigned long fakultet( unsigned long n) {
  if( n== 1)
    return 1;
  else
    return n* fakultet( n-1);
}

#include <stdio.h>
#define MAX 40

unsigned long fibo( int n);

int main( void) {  /* fibo.c */
  int i;

  printf( "The Fibonacci numbers up to %d\n", MAX);
  for( i= 1; i<= MAX; i++) {
    printf( "%lu ", fibo( i));
    fflush( stdout);
  }
  printf( "\n");

  return 0;
}

/* Compute n'th Fibonacci number */
unsigned long fibo( int n) {
  switch( n) {
  case 1: case 2:
    return 1; break;
  default:
    return fibo( n- 1)+ fibo( n- 2);
  }
}

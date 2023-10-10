#include <stdio.h>
#include <stdlib.h>
#define MAX 400

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
  unsigned long result;
  static unsigned long memo[ MAX];
            /* this gets initialised to 0 ! */
  switch( n) {
  case 1: case 2:
    return 1; break;
  default:
    result= memo[ n];
    if( result== 0) { /* need to compute */
      result= fibo( n- 1)+ fibo( n- 2);
      memo[ n]= result;
    }
    return result;
  }
}

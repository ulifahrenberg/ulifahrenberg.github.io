#include <stdio.h>
#include <stdlib.h>
/* #include <math.h> */

double f( double x) {  /* the recursive function definition */
  static int iteration= 0;
  double result;

  iteration++;
  /* x*x + 8x = 20 */
  result= 2.5- x*x/8;  /* Change here for other function */

  printf( "iteration: %d\tresult: %.7f\n", iteration, result);

  return result;
}

int main( int argc, char** argv) {  /* rekursion.c */
  double start= 1.0;
  int iterations= 100;
  char* endptr;
  int i;

  if( argc< 3)
    printf( "Warning: %s needs two argument; using '100' and '1'\n", argv[ 0]);
  else {
    iterations= strtol( argv[ 1], &endptr, 10);
    start= strtod( argv[ 2], &endptr);
  }

  for( i= 1; i<= iterations; i++)
    start= f( start);

  return 0;
}

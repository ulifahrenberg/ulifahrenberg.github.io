#include <stdio.h>
#include <math.h>

/* factor.c
   Factor a positive integer into primes */

void greeting(
       void);
unsigned int readPosInt(
       void);
unsigned int findFactor(
       unsigned int x);

int main( void) {
  unsigned int x, f;

  greeting();
  x= readPosInt();

  printf( "%u = ", x);

  while( x!= 1) {
    f= findFactor( x);
    printf( "%u * ", f);
    x= x/ f;
  }

  printf( "1\n");
  return 0;
}

/* Say what we are doing */
void greeting( void) {
  printf( "\nWe factor a positive integer \
into primes.\n");
}

/* Read a positive integer */
unsigned int readPosInt( void) {
  unsigned int input;

  printf( "Enter a positive integer: ");
  scanf( "%u", &input);

  return input;
}

/* Find the smallest factor in a positive integer */
unsigned int findFactor( unsigned int x) {
  unsigned int i;
  int found_one= 0;

  for( i= 2; i<= (int)sqrt( x); i++)
    if( x% i== 0) {
      found_one= 1;
      break;
    }

  if( found_one)
    return i;
  else
    return x;
}

#include <stdio.h>
#include <stdlib.h>

unsigned long fakultet( unsigned long n);

int main( int argc, char** argv) {  /* fak2.c */
  char * myself= argv[0];
  unsigned long tal;
  char * endptr;  /* needed for strtol */

  if( argc== 1)
    printf( "Error: %s needs one argument\n", myself);
  else {  /* convert argv[1] to int */
    tal= strtol( argv[1], &endptr, 10);
    printf( "\nThe factorial of %lu is %lu\n",\
	    tal, fakultet( tal));
  }
  return 0;
}

/* Compute factorial of n */
unsigned long fakultet( unsigned long n) {
  if( n== 1)
    return 1;
  else
    return n* fakultet( n-1);
}

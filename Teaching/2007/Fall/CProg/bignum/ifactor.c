#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>

/*
  ifactor.c
  
  Factors a positive integer bignum into its prime factors.
  Integer is given as command-line argument.

  Uses gmp.h.  Compile with '-lgmp'.
 */

/* Explain usage of program.  Is called on input errors */
void usage( char *progname) {
  printf( "\
Usage: %s nnn\n\
Factors arbitrary-length positive integer nnn into primes.\n\
Other arguments are ignored.\n", progname);
  exit( -1);
}

/* return whether x is prime */
int is_prime( mpz_t x); 

int main( int argc, char **argv) {
  mpz_t tal; /* the integer to be factored */
  mpz_t sqrt_tal; /* square root of tal */
  mpz_t i;
  int found_factor= 0; /* whether we found a factor */
  char *myself;

  myself= argv[ 0];

  if( argc< 2) /* needs 1 argument */
    usage( myself);

  mpz_init( tal); /* always need to initialize bignums */

  if( mpz_set_str( tal, argv[ 1], 0)) /* we want an integer argument */
    usage( myself);

  if( mpz_cmp_ui( tal, 0)<= 0) /* positive integer, please */
    usage( myself);

  if( mpz_cmp_ui( tal, 1)== 0) { /* treat case tal==1 specially */
    printf( "1 is composite\n");
    exit( 0);
  }

  mpz_init( sqrt_tal);
  mpz_sqrt( sqrt_tal, tal);

  gmp_printf( "%Zd ", tal);

  mpz_init_set_ui( i, 2);
  while( mpz_cmp( i, sqrt_tal)<= 0) { /* loop as long as i<= sqrt( tal) */
    /* we only check divisibility by primes.
       Does this make it faster? */
    if( is_prime( i) && mpz_divisible_p( tal, i)) {
      mpz_divexact( tal, tal, i);

      if( found_factor) {
	gmp_printf( "* %Zd ", i);
      } else { /* output is different if we just found the first factor */
	gmp_printf( "= %Zd ", i);
	found_factor= 1;
      }
      /* gmp_printf( "tal: %Zd, i: %Zd\n", tal, i); /* for debugging */
    } else /* didn't find a factor. increase i */
      mpz_add_ui( i, i, 1);
  }

  /* if there is a factor in tal which is > sqrt(tal),
     then we didn't find it above */
  if( found_factor && mpz_cmp_ui( tal, 1)> 0)
    gmp_printf( "* %Zd ", tal);

  if( !found_factor)
    printf( "is prime");
  printf( "\n");

  return 0;
}

int is_prime( mpz_t x) {
  return mpz_probab_prime_p( x, 5);
}

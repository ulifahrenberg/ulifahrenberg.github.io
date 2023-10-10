#include <stdio.h>
#include <gmp.h>

/*
  prim_gmp.c

  Hvis det indtastede tal er prim, udskrives "PRIMA",
  ellers udskrives næste primtal.

  Bruger bignums (gmp.h). Kompiler med '-lgmp'.
*/

/* funktioner kan ikke returnere bignums, så
      mpz_t indlaes( void);
   virker ikke.  Vi er noedt til at bruge pointers i stedet.
*/
void indlaes( mpz_t *tal);
int prim( mpz_t tal);
void nextPrime( mpz_t *tal);
void udskriv( mpz_t tal);

int main( void) {
  mpz_t tal; /* et bignum-heltal */
  mpz_init( tal); /* som skal initialiseres foer brug */

  indlaes( &tal);  /* indlaes bignum-heltal */
  if( prim( tal))  /* er tal prim? */
    printf( "PRIMA\n");
  else {
    nextPrime( &tal);  /* find naeste primtal */
    printf( "Next prime is ");
    udskriv( tal); /* udskriv et bignum-heltal */
  }

  return 0;
}

void indlaes( mpz_t *tal) {
  printf( "\nEnter a number: ");
  gmp_scanf( "%Zd", tal); /* bemaerk at '&' mangler her! */
}

void udskriv( mpz_t tal) {
  gmp_printf( "%Zd\n", tal);
}

int prim( mpz_t tal) {
  int isprime= 1;
  mpz_t i, sqrt_tal;
  mpz_init( i);
  mpz_init( sqrt_tal);

  mpz_sqrt( sqrt_tal, tal);

  /* foerhen stod der her:
  for( i= 2; i<= sqrt( tal); i++) {
    if( tal% i== 0) {
      isprime= 0;
      break;
    }
  }
  */
  for( mpz_set_ui( i, 2); mpz_cmp( i, sqrt_tal)<= 0; mpz_add_ui( i, i, 1)) {
    if( mpz_divisible_p( tal, i)) {
      isprime= 0;
      break;
    }
  }

  mpz_clear( i); /* bignums skal deallokeres efter brug! */
  mpz_clear( sqrt_tal);

  return isprime;
}

void nextPrime( mpz_t *tal) {
  mpz_add_ui( *tal, *tal, 1);
  while( !prim( *tal))
    mpz_add_ui( *tal, *tal, 1);
}
